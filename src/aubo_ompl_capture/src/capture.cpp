#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>
#include <pluginlib/class_loader.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <moveit/planning_interface/planning_interface.h>
#include <moveit/planning_request_adapter/planning_request_adapter.h>
#include <moveit/ompl_interface/model_based_planning_context.h>
#include <moveit/robot_state/conversions.h>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <std_msgs/msg/string.hpp>
#include <ompl/base/PlannerData.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <set>
#include <sstream>
#include <unistd.h>

namespace capture
{
namespace pi = planning_interface;
namespace fs = std::filesystem;
using State = moveit::core::RobotState;
using Marker = visualization_msgs::msg::Marker;
using Display = moveit_msgs::msg::DisplayTrajectory;
using Clock = std::chrono::steady_clock;
constexpr const char* TCP = "scissor_tcp";

struct Run
{
  std::string id, reason = "no_wrapped_solve", frame;
  unsigned int solve_calls = 0;
  bool captured = false, exact = false;
  double solve_wall_s = 0, tree_capture_s = 0, range = 0, goal_bias = 0;
  pi::MotionPlanRequest context_request;
  moveit_msgs::msg::PlanningScene context_scene;
  std::vector<State> states;
  std::vector<int> parents;
  std::vector<bool> starts, goals;
  std::vector<std::pair<unsigned int, unsigned int>> edges;
  std::vector<unsigned int> raw;
};

// Both plugins are in this library. The adapter and solve execute on the same
// synchronous pipeline call stack; nested calls restore the previous record.
thread_local Run* active_run = nullptr;
struct Scope
{
  Run* previous;
  explicit Scope(Run& run) : previous(active_run) { active_run = &run; }
  ~Scope() { active_run = previous; }
};

static double elapsed(Clock::time_point t)
{
  return std::chrono::duration<double>(Clock::now() - t).count();
}

static void collect(const ompl_interface::ModelBasedPlanningContextPtr& context, bool solved, Run& run)
{
  run.context_request = context->getMotionPlanRequest();
  if (run.solve_calls != 1) { run.reason = "multiple_internal_solves"; run.captured = false; return; }
  if (run.context_request.num_planning_attempts != 1) { run.reason = "planning_attempts_must_be_1"; return; }
  const auto setup = context->getOMPLSimpleSetup();
  const auto* rrt = dynamic_cast<const ompl::geometric::RRT*>(setup->getPlanner().get());
  if (!rrt) { run.reason = "actual_planner_is_not_geometric_RRT"; return; }
  if (run.context_request.group_name != "aubo_arm") { run.reason = "group_is_not_aubo_arm"; return; }
  const auto& reference = context->getCompleteInitialRobotState();
  if (!reference.getRobotModel()->hasLinkModel(TCP)) throw std::runtime_error("scissor_tcp is missing");
  run.frame = reference.getRobotModel()->getModelFrame();
  run.range = rrt->getRange();
  run.goal_bias = rrt->getGoalBias();
  run.exact = solved && setup->haveExactSolutionPath();
  context->getPlanningScene()->getPlanningSceneMsg(run.context_scene);
  ompl::base::PlannerData data(setup->getSpaceInformation());
  rrt->getPlannerData(data);
  data.decoupleFromPlanner();
  const auto space = context->getOMPLStateSpace();
  run.parents.assign(data.numVertices(), -1);
  for (unsigned int i = 0; i < data.numVertices(); ++i)
  {
    State robot(reference);
    space->copyToRobotState(robot, data.getVertex(i).getState());
    robot.update();
    run.states.push_back(robot);
    run.starts.push_back(data.isStartVertex(i));
    run.goals.push_back(data.isGoalVertex(i));
    std::vector<unsigned int> targets;
    data.getEdges(i, targets);
    for (auto target : targets)
    {
      if (run.parents.at(target) != -1) throw std::runtime_error("RRT vertex has multiple parents");
      run.parents[target] = static_cast<int>(i);
      run.edges.emplace_back(i, target);
    }
  }
  if (run.exact)
  {
    if (data.numGoalVertices() != 1) throw std::runtime_error("expected one exact RRT goal vertex");
    unsigned int current = data.getGoalIndex(0);
    std::set<unsigned int> seen;
    while (true)
    {
      if (!seen.insert(current).second) throw std::runtime_error("cycle in RRT parent chain");
      run.raw.push_back(current);
      if (run.starts.at(current)) break;
      if (run.parents.at(current) < 0) throw std::runtime_error("goal chain does not reach a start");
      current = static_cast<unsigned int>(run.parents[current]);
    }
    std::reverse(run.raw.begin(), run.raw.end());
  }
  run.reason = run.exact ? "ok" : "tree_only_no_exact_solution";
  run.captured = true;
}

class Context : public pi::PlanningContext
{
public:
  explicit Context(ompl_interface::ModelBasedPlanningContextPtr inner)
    : PlanningContext(inner->getName(), inner->getGroupName()), inner_(std::move(inner))
  {
    setPlanningScene(inner_->getPlanningScene());
    setMotionPlanRequest(inner_->getMotionPlanRequest());
  }
  bool solve(pi::MotionPlanResponse& response) override { return solveImpl(response); }
  bool solve(pi::MotionPlanDetailedResponse& response) override { return solveImpl(response); }
  bool terminate() override { return inner_->terminate(); }
  void clear() override { inner_->clear(); }
private:
  template<class Response> bool solveImpl(Response& response)
  {
    Run* run = active_run;
    if (run) ++run->solve_calls;
    const auto before = Clock::now();
    const bool solved = inner_->solve(response);  // The original OMPL solve, exactly once.
    if (run)
    {
      run->solve_wall_s += elapsed(before);
      const auto capture_start = Clock::now();
      try { collect(inner_, solved, *run); }
      catch (const std::exception& e) { run->captured = false; run->reason = std::string("capture_error: ") + e.what(); }
      catch (...) { run->captured = false; run->reason = "unknown_capture_error"; }
      run->tree_capture_s += elapsed(capture_start);
    }
    return solved;
  }
  ompl_interface::ModelBasedPlanningContextPtr inner_;
};

class PlannerManager : public pi::PlannerManager
{
public:
  bool initialize(const moveit::core::RobotModelConstPtr& model, const rclcpp::Node::SharedPtr& node,
                  const std::string& ns) override
  {
    loader_ = std::make_unique<pluginlib::ClassLoader<pi::PlannerManager>>("moveit_core", "planning_interface::PlannerManager");
    inner_ = loader_->createSharedInstance("ompl_interface/OMPLPlanner");
    const bool ok = inner_->initialize(model, node, ns);
    config_settings_ = inner_->getPlannerConfigurations();
    return ok;
  }
  std::string getDescription() const override { return inner_->getDescription(); }
  void getPlanningAlgorithms(std::vector<std::string>& names) const override { inner_->getPlanningAlgorithms(names); }
  bool canServiceRequest(const pi::MotionPlanRequest& req) const override { return inner_->canServiceRequest(req); }
  void setPlannerConfigurations(const pi::PlannerConfigurationMap& config) override
  {
    inner_->setPlannerConfigurations(config);
    config_settings_ = inner_->getPlannerConfigurations();
  }
  pi::PlanningContextPtr getPlanningContext(const planning_scene::PlanningSceneConstPtr& scene,
       const pi::MotionPlanRequest& req, moveit_msgs::msg::MoveItErrorCodes& error) const override
  {
    auto context = inner_->getPlanningContext(scene, req, error);
    if (!context) return context;
    auto ompl_context = std::dynamic_pointer_cast<ompl_interface::ModelBasedPlanningContext>(context);
    if (!ompl_context) return context;
    return std::make_shared<Context>(std::move(ompl_context));
  }
private:
  // Destruction order is intentional: the delegate dies before its loader.
  std::unique_ptr<pluginlib::ClassLoader<pi::PlannerManager>> loader_;
  std::shared_ptr<pi::PlannerManager> inner_;
};

static geometry_msgs::msg::Point point(const State& robot)
{
  const auto p = robot.getGlobalLinkTransform(TCP).translation();
  geometry_msgs::msg::Point result;
  result.x = p.x(); result.y = p.y(); result.z = p.z();
  return result;
}

static std::vector<geometry_msgs::msg::Point> curve(const State& a, const State& b,
                                                 const moveit::core::JointModelGroup* group)
{
  std::vector<double> qa, qb;
  a.copyJointGroupPositions(group, qa); b.copyJointGroupPositions(group, qb);
  double max_change = 0;
  for (size_t j = 0; j < qa.size(); ++j) max_change = std::max(max_change, std::abs(qa[j] - qb[j]));
  const unsigned int count = std::max(2u, static_cast<unsigned int>(std::ceil(max_change / 0.03)));
  std::vector<geometry_msgs::msg::Point> result;
  State sample(a);
  for (unsigned int i = 0; i <= count; ++i)
  {
    a.interpolate(b, static_cast<double>(i) / count, sample, group);
    sample.update();
    result.push_back(point(sample));
  }
  return result;
}

static std::ofstream file(const fs::path& path)
{
  std::ofstream output(path, std::ios::binary);
  output.exceptions(std::ios::badbit | std::ios::failbit);
  output << std::setprecision(17);
  return output;
}
template<class Message> static void saveMessage(const fs::path& path, const Message& message)
{
  rclcpp::SerializedMessage serialized;
  rclcpp::Serialization<Message>().serialize_message(&message, &serialized);
  const auto& bytes = serialized.get_rcl_serialized_message();
  file(path).write(reinterpret_cast<const char*>(bytes.buffer), bytes.buffer_length);
}
static void csvHeader(std::ostream& output, const moveit::core::JointModelGroup* group)
{
  for (const auto& name : group->getVariableNames()) output << ',' << name;
  output << ",tcp_x,tcp_y,tcp_z\n";
}
static void csvState(std::ostream& output, const State& state, const moveit::core::JointModelGroup* group)
{
  std::vector<double> q;
  state.copyJointGroupPositions(group, q);
  for (auto value : q) output << ',' << value;
  const auto p = point(state);
  output << ',' << p.x << ',' << p.y << ',' << p.z << '\n';
}

class CaptureResult : public planning_request_adapter::PlanningRequestAdapter
{
public:
  void initialize(const rclcpp::Node::SharedPtr& node, const std::string&) override
  {
    node_ = node;
    const auto qos = rclcpp::QoS(1).reliable().transient_local();
    markers_ = node->create_publisher<visualization_msgs::msg::MarkerArray>("/rrt_ompl/markers", qos);
    raw_ = node->create_publisher<Display>("/rrt_ompl/raw_path", qos);
    final_ = node->create_publisher<Display>("/rrt_ompl/final_path", qos);
    status_ = node->create_publisher<std_msgs::msg::String>("/rrt_ompl/status", qos);
    const char* home = std::getenv("HOME");
    if (!home) throw std::runtime_error("HOME is missing");
    output_ = fs::path(home) / "aubo_ws/rrt_results/ompl_same_plan";
  }
  std::string getDescription() const override { return "Capture same-call OMPL RRT tree and final path"; }
  bool adaptAndPlan(const PlannerFn& planner, const planning_scene::PlanningSceneConstPtr& scene,
                   const pi::MotionPlanRequest& req, pi::MotionPlanResponse& res,
                   std::vector<std::size_t>&) const override
  {
    static std::atomic<unsigned long> sequence{0};
    Run run;
    run.id = std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count()) + "-" +
        std::to_string(getpid()) + "-" + std::to_string(++sequence);
    Scope scope(run);
    try { clear(scene->getRobotModel()->getModelFrame()); }
    catch (...) { RCLCPP_WARN(node_->get_logger(), "Could not clear previous capture display"); }
    const bool solved = planner(scene, req, res);
    // Never let export exceptions escape: MoveIt's adapter-chain fallback could
    // otherwise re-run the planner, changing the meaning of this record.
    try { finish(run, scene, req, res, solved); }
    catch (const std::exception& e) { reportFailure(run, e.what()); }
    catch (...) { reportFailure(run, "unknown_export_error"); }
    return solved;
  }
private:
  Marker marker(const Run& run, const std::string& ns, int type, float r, float g, float b, double scale) const
  {
    Marker result;
    result.header.frame_id = run.frame;
    result.ns = ns;
    result.id = 0;
    result.type = type;
    result.action = Marker::ADD;
    result.pose.orientation.w = 1;
    result.scale.x = result.scale.y = result.scale.z = scale;
    result.color.r = r; result.color.g = g; result.color.b = b; result.color.a = 1;
    return result;
  }
  Marker clearMarker(const std::string& frame) const
  {
    Marker result; result.header.frame_id = frame; result.action = Marker::DELETEALL; return result;
  }
  void clear(const std::string& frame) const
  {
    visualization_msgs::msg::MarkerArray message;
    message.markers.push_back(clearMarker(frame));
    markers_->publish(message);
    raw_->publish(Display()); final_->publish(Display());
  }
  void reportFailure(const Run& run, const std::string& reason) const noexcept
  {
    try
    {
      clear(run.frame.empty() ? "world" : run.frame);
      std::ostringstream out;
      out << "run_id: " << std::quoted(run.id) << "\ncapture_ok: false\nreason: " << std::quoted(reason) << '\n';
      std_msgs::msg::String message; message.data = out.str(); status_->publish(message);
      RCLCPP_ERROR(node_->get_logger(), "OMPL capture %s failed: %s", run.id.c_str(), reason.c_str());
    }
    catch (...) {}
  }
  void finish(Run& run, const planning_scene::PlanningSceneConstPtr& scene,
              const pi::MotionPlanRequest& req, const pi::MotionPlanResponse& res, bool solved) const
  {
    const auto before = Clock::now();
    if (run.solve_calls != 1) { run.captured = false; run.reason = "expected_one_internal_solve"; }
    const fs::path directory = output_ / run.id;
    fs::create_directories(directory);
    saveMessage(directory / "request.cdr", req);
    moveit_msgs::msg::PlanningScene scene_message;
    scene->getPlanningSceneMsg(scene_message);
    saveMessage(directory / "scene.cdr", scene_message);
    if (run.solve_calls)
    {
      saveMessage(directory / "context_request.cdr", run.context_request);
      if (run.captured) saveMessage(directory / "context_scene.cdr", run.context_scene);
    }
    visualization_msgs::msg::MarkerArray array;
    array.markers.push_back(clearMarker(scene->getRobotModel()->getModelFrame()));
    Display raw_message, final_message;
    size_t final_count = 0;
    if (run.captured)
    {
      const auto model = scene->getRobotModel();
      const auto* group = model->getJointModelGroup(req.group_name);
      auto nodes = marker(run, "tree_nodes", Marker::POINTS, .12, .55, 1, .008);
      auto branches = marker(run, "tree_edges", Marker::LINE_LIST, .55, .65, .75, .0015);
      branches.color.a = .5;
      auto vertices_file = file(directory / "nodes.csv");
      vertices_file << "id,parent,is_start,is_goal"; csvHeader(vertices_file, group);
      for (size_t i = 0; i < run.states.size(); ++i)
      {
        vertices_file << i << ',' << run.parents[i] << ',' << run.starts[i] << ',' << run.goals[i];
        csvState(vertices_file, run.states[i], group);
        nodes.points.push_back(point(run.states[i]));
      }
      auto edges_file = file(directory / "edges.csv"); edges_file << "source,target\n";
      for (const auto& edge : run.edges)
      {
        edges_file << edge.first << ',' << edge.second << '\n';
        const auto segment = curve(run.states[edge.first], run.states[edge.second], group);
        for (size_t k = 1; k < segment.size(); ++k)
        {
          branches.points.push_back(segment[k - 1]); branches.points.push_back(segment[k]);
        }
      }
      array.markers.push_back(std::move(branches)); array.markers.push_back(std::move(nodes));
      auto raw_line = marker(run, "raw_path", Marker::LINE_STRIP, 1, .75, .05, .006);
      auto raw_file = file(directory / "raw_path.csv"); raw_file << "waypoint,vertex_id"; csvHeader(raw_file, group);
      robot_trajectory::RobotTrajectory raw_trajectory(model, req.group_name);
      for (size_t k = 0; k < run.raw.size(); ++k)
      {
        const State& state = run.states[run.raw[k]];
        raw_file << k << ',' << run.raw[k]; csvState(raw_file, state, group);
        raw_trajectory.addSuffixWayPoint(state, 0.0); // Raw path has no time parameterization.
        if (k)
        {
          auto segment = curve(run.states[run.raw[k - 1]], state, group);
          raw_line.points.insert(raw_line.points.end(), segment.begin() + 1, segment.end());
        }
        else raw_line.points.push_back(point(state));
      }
      if (!run.raw.empty())
      {
        raw_message.model_id = model->getName();
        moveit::core::robotStateToRobotStateMsg(raw_trajectory.getFirstWayPoint(), raw_message.trajectory_start);
        raw_message.trajectory.emplace_back(); raw_trajectory.getRobotTrajectoryMsg(raw_message.trajectory.back());
        saveMessage(directory / "raw_trajectory.cdr", raw_message.trajectory.back());
        array.markers.push_back(std::move(raw_line));
      }
      auto final_file = file(directory / "final_path.csv"); final_file << "waypoint,time_from_start"; csvHeader(final_file, group);
      if (solved && res.trajectory_ && !res.trajectory_->empty())
      {
        final_message.model_id = model->getName();
        moveit::core::robotStateToRobotStateMsg(res.trajectory_->getFirstWayPoint(), final_message.trajectory_start);
        final_message.trajectory.emplace_back(); res.trajectory_->getRobotTrajectoryMsg(final_message.trajectory.back());
        saveMessage(directory / "final_trajectory.cdr", final_message.trajectory.back());
        auto final_line = marker(run, "final_path", Marker::LINE_STRIP, 1, .15, .8, .004);
        final_count = res.trajectory_->getWayPointCount();
        for (size_t k = 0; k < final_count; ++k)
        {
          State state(res.trajectory_->getWayPoint(k)); state.update();
          final_file << k << ',' << res.trajectory_->getWayPointDurationFromStart(k); csvState(final_file, state, group);
          if (k)
          {
            auto segment = curve(res.trajectory_->getWayPoint(k - 1), state, group);
            final_line.points.insert(final_line.points.end(), segment.begin() + 1, segment.end());
          }
          else final_line.points.push_back(point(state));
        }
        array.markers.push_back(std::move(final_line));
      }
    }
    std::ostringstream metadata;
    metadata << std::setprecision(17) << std::boolalpha
      << "run_id: " << std::quoted(run.id) << "\ncapture_ok: " << run.captured
      << "\nreason: " << std::quoted(run.reason) << "\nsolve_calls: " << run.solve_calls
      << "\nplanning_attempts: " << req.num_planning_attempts << "\nplanner_id: " << std::quoted(req.planner_id)
      << "\ngroup: " << std::quoted(req.group_name) << "\nframe: " << std::quoted(run.frame)
      << "\ntcp_link: scissor_tcp\nexact_solution: " << run.exact << "\nplanner_returned_success: " << solved
      << "\nmoveit_error_code: " << res.error_code_.val << "\nvertex_count: " << run.states.size()
      << "\nedge_count: " << run.edges.size() << "\nraw_waypoint_count: " << run.raw.size()
      << "\nfinal_waypoint_count: " << final_count << "\nresolved_range: " << run.range
      << "\ngoal_bias: " << run.goal_bias << "\ncontext_solve_wall_s: " << run.solve_wall_s
      << "\nmoveit_reported_planning_s: " << res.planning_time_ << "\ntree_capture_s: " << run.tree_capture_s
      << "\nexport_prepare_s: " << elapsed(before)
      << "\nfinal_stage: after_request_adapters_before_pipeline_validation"
      << "\ntree_data: retained_vertices_not_all_samples\nraw_path_vertex_ids: [";
    for (size_t k = 0; k < run.raw.size(); ++k) metadata << (k ? ", " : "") << run.raw[k];
    metadata << "]\noutput_directory: " << std::quoted(directory.string()) << '\n';
    file(directory / "summary.yaml") << metadata.str();
    markers_->publish(array); raw_->publish(raw_message); final_->publish(final_message);
    std_msgs::msg::String status; status.data = metadata.str(); status_->publish(status);
    RCLCPP_INFO(node_->get_logger(), "OMPL capture %s: %s; vertices=%zu raw=%zu final=%zu",
                run.id.c_str(), run.reason.c_str(), run.states.size(), run.raw.size(), final_count);
  }
  rclcpp::Node::SharedPtr node_;
  fs::path output_;
  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr markers_;
  rclcpp::Publisher<Display>::SharedPtr raw_, final_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_;
};
} // namespace capture

PLUGINLIB_EXPORT_CLASS(capture::PlannerManager, planning_interface::PlannerManager)
PLUGINLIB_EXPORT_CLASS(capture::CaptureResult, planning_request_adapter::PlanningRequestAdapter)
