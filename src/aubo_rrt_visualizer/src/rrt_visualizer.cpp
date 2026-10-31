#include <rclcpp/rclcpp.hpp>
#include <rclcpp/serialization.hpp>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/planning_scene/planning_scene.h>
#include <moveit/ompl_interface/ompl_interface.h>
#include <moveit/ompl_interface/model_based_planning_context.h>
#include <moveit/robot_state/conversions.h>
#include <moveit/kinematic_constraints/utils.h>
#include <moveit_msgs/srv/get_planning_scene.hpp>
#include <moveit_msgs/msg/planning_scene_components.hpp>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <ompl/base/PlannerData.h>
#include <ompl/base/ScopedState.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <ompl/util/RandomNumbers.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <unistd.h>

namespace fs = std::filesystem;
namespace ob = ompl::base;
using Marker = visualization_msgs::msg::Marker;
using State = moveit::core::RobotState;

class RRTVisualizer
{
public:
  explicit RRTVisualizer(rclcpp::Node::SharedPtr node) : node_(std::move(node)) {}

  void run()
  {
    const auto start_name = parameter<std::string>("start_state", "home");
    const auto goal_name = parameter<std::string>("goal_state", "pose1");
    const double budget = parameter<double>("planning_time", 5.0);
    const auto seed = parameter<int64_t>("seed", 42);
    if (budget <= 0 || seed <= 0) throw std::runtime_error("planning_time and seed must be positive");
    ompl::RNG::setSeed(static_cast<unsigned int>(seed));

    robot_model_loader::RobotModelLoader loader(node_, "robot_description");
    auto model = loader.getModel();
    if (!model) throw std::runtime_error("Robot model was not loaded");
    const std::string group = "aubo_arm", tcp = "scissor_tcp";
    const auto* jmg = model->getJointModelGroup(group);
    if (!jmg || !model->hasLinkModel(tcp)) throw std::runtime_error("aubo_arm or scissor_tcp is missing");

    auto client = node_->create_client<moveit_msgs::srv::GetPlanningScene>("/get_planning_scene");
    if (!client->wait_for_service(std::chrono::seconds(40)))
      throw std::runtime_error("/get_planning_scene unavailable; start the MoveIt demo first");
    auto query = std::make_shared<moveit_msgs::srv::GetPlanningScene::Request>();
    using C = moveit_msgs::msg::PlanningSceneComponents;
    query->components.components = C::SCENE_SETTINGS | C::ROBOT_STATE | C::ROBOT_STATE_ATTACHED_OBJECTS |
        C::WORLD_OBJECT_GEOMETRY | C::OCTOMAP | C::TRANSFORMS | C::ALLOWED_COLLISION_MATRIX |
        C::LINK_PADDING_AND_SCALING | C::OBJECT_COLORS;
    auto future = client->async_send_request(query);
    if (future.wait_for(std::chrono::seconds(20)) != std::future_status::ready)
      throw std::runtime_error("PlanningScene snapshot request timed out");
    auto snapshot = future.get()->scene;
    auto scene = std::make_shared<planning_scene::PlanningScene>(model);
    if (!scene->setPlanningSceneMsg(snapshot)) throw std::runtime_error("Invalid PlanningScene snapshot");

    for (const auto& name : jmg->getDefaultStateNames())
    {
      State test = scene->getCurrentState();
      test.setToDefaultValues(jmg, name);
      test.update();
      RCLCPP_INFO(node_->get_logger(), "Named state %s: bounds=%s collision_free=%s", name.c_str(),
          test.satisfiesBounds(jmg) ? "yes" : "no", scene->isStateValid(test, group) ? "yes" : "no");
    }
    State start = scene->getCurrentState(), goal = start;
    if (start_name != "current" && !start.setToDefaultValues(jmg, start_name))
      throw std::runtime_error("Unknown start named state: " + start_name);
    if (!goal.setToDefaultValues(jmg, goal_name)) throw std::runtime_error("Unknown goal named state: " + goal_name);
    start.update();
    goal.update();
    if (!start.satisfiesBounds(jmg) || !scene->isStateValid(start, group, true))
      throw std::runtime_error("Start state is invalid: " + start_name);
    if (!goal.satisfiesBounds(jmg) || !scene->isStateValid(goal, group, true))
      throw std::runtime_error("Goal state is invalid: " + goal_name);

    planning_interface::MotionPlanRequest request;
    request.group_name = group;
    request.planner_id = "RRTkConfigDefault";
    request.num_planning_attempts = 1;
    request.allowed_planning_time = budget;
    moveit::core::robotStateToRobotStateMsg(start, request.start_state);
    request.goal_constraints.push_back(kinematic_constraints::constructGoalConstraints(goal, jmg, 1e-4));
    ompl_interface::OMPLInterface interface(model, node_, "ompl");
    moveit_msgs::msg::MoveItErrorCodes error;
    auto context = interface.getPlanningContext(scene, request, error);
    if (!context) throw std::runtime_error("Cannot create OMPL context, error " + std::to_string(error.val));
    auto setup = context->getOMPLSimpleSetup();
    setup->setup();
    auto* rrt = dynamic_cast<ompl::geometric::RRT*>(setup->getPlanner().get());
    if (!rrt) throw std::runtime_error("Actual planner is not geometric::RRT");
    const double range = parameter<double>("range", 0.3);
    if (range <= 0) throw std::runtime_error("range must be positive");
    rrt->setRange(range);

    planning_interface::MotionPlanDetailedResponse response;
    const auto started = std::chrono::steady_clock::now();
    const bool solved = context->solve(response);  // One solve, keeping this context's actual tree.
    const double wall_seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - started).count();
    const bool exact = solved && setup->haveExactSolutionPath();
    ob::PlannerData data(setup->getSpaceInformation());
    setup->getPlanner()->getPlannerData(data);
    data.decoupleFromPlanner();
    const auto space = context->getOMPLStateSpace();
    const State reference = context->getCompleteInitialRobotState();
    auto to_robot = [&](const ob::State* s) {
      State robot = reference;
      space->copyToRobotState(robot, s);
      robot.update();
      return robot;
    };
    auto point = [&](const State& robot) {
      const auto& p = robot.getGlobalLinkTransform(tcp).translation();
      geometry_msgs::msg::Point result;
      result.x = p.x(); result.y = p.y(); result.z = p.z();
      return result;
    };
    auto interpolated_points = [&](const ob::State* a, const ob::State* b) {
      std::vector<geometry_msgs::msg::Point> result;
      const unsigned int count = std::max(4u, space->validSegmentCount(a, b));
      ob::ScopedState<> sample(space);
      for (unsigned int i = 0; i <= count; ++i)
      {
        space->interpolate(a, b, static_cast<double>(i) / count, sample.get());
        result.push_back(point(to_robot(sample.get())));
      }
      return result;
    };

    const auto home = std::string(std::getenv("HOME"));
    const fs::path base = parameter<std::string>("output_directory", home + "/aubo_ws/rrt_results");
    const auto now = std::time(nullptr);
    std::ostringstream name;
    name << std::put_time(std::localtime(&now), "%Y%m%d-%H%M%S") << '-' << getpid();
    const fs::path directory = base / name.str();
    fs::create_directories(directory);
    save_message(directory / "planning_scene.cdr", snapshot);
    save_message(directory / "request.cdr", request);
    file(directory / "robot.urdf") << node_->get_parameter("robot_description").as_string();
    file(directory / "robot.srdf") << node_->get_parameter("robot_description_semantic").as_string();
    auto vertices = file(directory / "vertices.csv");
    auto edges = file(directory / "edges.csv");
    vertices << "id,is_start,is_goal";
    write_header(vertices, jmg);
    edges << "source,target\n";

    frame_ = model->getModelFrame();
    auto nodes = marker("rrt_nodes", 0, Marker::POINTS, 0.25, 0.65, 1.0, 0.8, 0.007);
    auto branches = marker("rrt_edges", 1, Marker::LINE_LIST, 0.65, 0.7, 0.75, 0.4, 0.0015);
    size_t invalid_vertices = 0, invalid_edges = 0, invalid_path_edges = 0, edge_count = 0;
    for (unsigned int i = 0; i < data.numVertices(); ++i)
    {
      const auto* a = data.getVertex(i).getState();
      auto robot = to_robot(a);
      if (!setup->getSpaceInformation()->isValid(a)) ++invalid_vertices;
      nodes.points.push_back(point(robot));
      vertices << i << ',' << data.isStartVertex(i) << ',' << data.isGoalVertex(i);
      write_state(vertices, robot, jmg, point(robot));
      std::vector<unsigned int> targets;
      data.getEdges(i, targets);
      for (const auto target : targets)
      {
        const auto* b = data.getVertex(target).getState();
        edges << i << ',' << target << '\n';
        ++edge_count;
        if (!setup->getSpaceInformation()->checkMotion(a, b)) ++invalid_edges;
        const auto curve = interpolated_points(a, b);
        for (size_t k = 1; k < curve.size(); ++k)
        {
          branches.points.push_back(curve[k - 1]);
          branches.points.push_back(curve[k]);
        }
      }
    }
    Marker clear;
    clear.header.frame_id = frame_;
    clear.action = Marker::DELETEALL;
    markers_.markers = {clear, nodes, branches};

    auto metadata = file(directory / "metadata.yaml");
    metadata << std::boolalpha << "planner_type: geometric::RRT\nplanner_id: RRTkConfigDefault\n"
        << "group: " << group << "\ntcp_link: " << tcp << "\nframe: " << std::quoted(frame_)
        << "\nstart_named_state: " << std::quoted(start_name) << "\ngoal_named_state: " << std::quoted(goal_name)
        << "\nseed: " << seed << "\nplanning_attempts: 1\nallowed_planning_time_s: " << budget
        << "\nsolve_wall_time_s: " << wall_seconds << "\nexact_solution: " << exact
        << "\napproximate_solution: " << setup->getProblemDefinition()->hasApproximateSolution()
        << "\nmoveit_error_code: " << response.error_code_.val
        << "\nresolved_range: " << rrt->getRange() << "\ngoal_bias: " << rrt->getGoalBias()
        << "\nlongest_valid_segment_fraction: " << space->getLongestValidSegmentFraction()
        << "\nlongest_valid_segment_length: " << space->getLongestValidSegmentLength()
        << "\nedge_min_interpolation_segments: 4"
        << "\nvertex_count: " << data.numVertices() << "\nedge_count: " << edge_count
        << "\ninvalid_vertices: " << invalid_vertices << "\ninvalid_edges: " << invalid_edges
        << "\nworld_collision_objects: " << snapshot.world.collision_objects.size()
        << "\noctomap_bytes: " << snapshot.world.octomap.octomap.data.size()
        << "\ntree_collision_geometry_added: false\nnode_data: retained_planner_tree\nstages:\n";

    bool raw_stage_found = false;
    for (size_t i = 0; i < response.trajectory_.size(); ++i)
    {
      const auto& trajectory = response.trajectory_[i];
      const auto& stage = response.description_.at(i);
      auto csv = file(directory / (stage + ".csv"));
      csv << "waypoint";
      write_header(csv, jmg);
      std::vector<geometry_msgs::msg::Point> curve;
      double metric_length = 0.0, tcp_length = 0.0;
      ob::ScopedState<> a(space), b(space);
      for (size_t k = 0; k < trajectory->getWayPointCount(); ++k)
      {
        State robot = trajectory->getWayPoint(k);
        robot.update();
        csv << k;
        write_state(csv, robot, jmg, point(robot));
        space->copyToOMPLState(b.get(), robot);
        if (k)
        {
          metric_length += space->distance(a.get(), b.get());
          if (!setup->getSpaceInformation()->checkMotion(a.get(), b.get())) ++invalid_path_edges;
          auto segment = interpolated_points(a.get(), b.get());
          for (size_t j = 1; j < segment.size(); ++j)
          {
            const auto& p = segment[j - 1]; const auto& q = segment[j];
            tcp_length += std::sqrt(std::pow(p.x-q.x, 2) + std::pow(p.y-q.y, 2) + std::pow(p.z-q.z, 2));
          }
          curve.insert(curve.end(), segment.begin() + 1, segment.end());
        }
        else curve.push_back(point(robot));
        space->copyState(a.get(), b.get());
      }
      metadata << "  - name: " << stage << "\n    waypoint_count: " << trajectory->getWayPointCount()
          << "\n    processing_time_s: " << response.processing_time_.at(i)
          << "\n    ompl_metric_length: " << metric_length << "\n    tcp_curve_length_m: " << tcp_length << '\n';
      if (stage == "plan") raw_stage_found = true;
      if (exact && (stage == "plan" || i + 1 == response.trajectory_.size()))
      {
        auto path = marker(stage == "plan" ? "rrt_raw_path" : "rrt_processed_path",
            stage == "plan" ? 2 : 3, Marker::LINE_STRIP,
            stage == "plan" ? 1.0 : 0.2, stage == "plan" ? 0.55 : 1.0, 0.1, 1.0,
            stage == "plan" ? 0.01 : 0.005);
        path.points = std::move(curve);
        markers_.markers.push_back(std::move(path));
      }
    }
    metadata << "path_validation_failures: " << invalid_path_edges << '\n';
    if (invalid_vertices || invalid_edges || invalid_path_edges)
      throw std::runtime_error("Exported tree or path failed collision validation");
    if (exact && !raw_stage_found) throw std::runtime_error("Detailed response did not preserve the raw plan stage");
    auto endpoints = marker("rrt_endpoints", 4, Marker::SPHERE_LIST, 1.0, 0.25, 0.25, 1.0, 0.025);
    endpoints.points = {point(start), point(goal)};
    markers_.markers.push_back(std::move(endpoints));
    if (!exact)
    {
      auto status = marker("rrt_status", 5, Marker::TEXT_VIEW_FACING, 1.0, 0.3, 0.2, 1.0, 0.05);
      status.pose.position = point(start);
      status.pose.position.z += 0.1;
      status.text = "RRT: no exact solution";
      markers_.markers.push_back(std::move(status));
    }
    const fs::path rviz = parameter<std::string>("rviz_config", home + "/aubo_ws/src/aubo_i5_scissors_moveit_config/config/moveit.rviz");
    if (fs::is_regular_file(rviz)) fs::copy_file(rviz, directory / "scene.rviz");
    if (exact && !response.trajectory_.empty())
    {
      trajectory_.model_id = model->getName();
      moveit::core::robotStateToRobotStateMsg(start, trajectory_.trajectory_start);
      moveit_msgs::msg::RobotTrajectory msg;
      response.trajectory_.back()->getRobotTrajectoryMsg(msg);
      trajectory_.trajectory.push_back(std::move(msg));
    }
    metadata.close(); vertices.close(); edges.close();
    auto qos = rclcpp::QoS(1).reliable().transient_local();
    marker_pub_ = node_->create_publisher<visualization_msgs::msg::MarkerArray>("/rrt_exploration/markers", qos);
    trajectory_pub_ = node_->create_publisher<moveit_msgs::msg::DisplayTrajectory>("/display_planned_path", qos);
    // RViz subscribes before its asynchronously loaded robot model is ready.
    trajectory_not_before_ = std::chrono::steady_clock::now() + std::chrono::seconds(8);
    auto publish = [this]() {
      marker_pub_->publish(markers_);
      const auto count = trajectory_pub_->get_subscription_count();
      if (count && std::chrono::steady_clock::now() >= trajectory_not_before_ &&
          !trajectory_.trajectory.empty() && (!trajectory_sent_ || count > previous_subscribers_))
      {
        trajectory_pub_->publish(trajectory_);
        trajectory_sent_ = true;
      }
      previous_subscribers_ = count;
    };
    publish();
    timer_ = node_->create_wall_timer(std::chrono::seconds(2), publish);
    RCLCPP_INFO(node_->get_logger(), "RRT_EXPORT_READY exact=%s vertices=%u edges=%zu output=%s",
        exact ? "true" : "false", data.numVertices(), edge_count, directory.c_str());
  }

private:
  template<class T> T parameter(const std::string& name, const T& fallback)
  {
    if (!node_->has_parameter(name)) node_->declare_parameter<T>(name, fallback);
    return node_->get_parameter(name).get_value<T>();
  }
  static std::ofstream file(const fs::path& path)
  {
    std::ofstream out(path);
    if (!out) throw std::runtime_error("Cannot write " + path.string());
    out << std::setprecision(17);
    return out;
  }
  template<class T> static void save_message(const fs::path& path, const T& message)
  {
    rclcpp::Serialization<T> serializer;
    rclcpp::SerializedMessage serialized;
    serializer.serialize_message(&message, &serialized);
    const auto& bytes = serialized.get_rcl_serialized_message();
    std::ofstream out(path, std::ios::binary);
    if (!out.write(reinterpret_cast<const char*>(bytes.buffer), bytes.buffer_length))
      throw std::runtime_error("Cannot save " + path.string());
  }
  static void write_header(std::ofstream& out, const moveit::core::JointModelGroup* group)
  {
    for (const auto& name : group->getVariableNames()) out << ',' << name;
    out << ",tcp_x,tcp_y,tcp_z\n";
  }
  static void write_state(std::ofstream& out, const State& state, const moveit::core::JointModelGroup* group,
                          const geometry_msgs::msg::Point& point)
  {
    for (const auto& name : group->getVariableNames()) out << ',' << state.getVariablePosition(name);
    out << ',' << point.x << ',' << point.y << ',' << point.z << '\n';
  }
  Marker marker(const std::string& ns, int id, int type, double r, double g, double b, double alpha, double scale)
  {
    Marker result;
    result.header.frame_id = frame_; result.header.stamp = node_->now();
    result.ns = ns; result.id = id; result.type = type; result.action = Marker::ADD;
    result.pose.orientation.w = 1.0;
    result.color.r = r; result.color.g = g; result.color.b = b; result.color.a = alpha;
    result.scale.x = result.scale.y = result.scale.z = scale;
    return result;
  }
  rclcpp::Node::SharedPtr node_;
  std::string frame_;
  visualization_msgs::msg::MarkerArray markers_;
  moveit_msgs::msg::DisplayTrajectory trajectory_;
  rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr trajectory_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  bool trajectory_sent_ = false;
  std::chrono::steady_clock::time_point trajectory_not_before_;
  size_t previous_subscribers_ = 0;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("rrt_visualizer",
      rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  std::thread spin([&executor]() { executor.spin(); });
  int result = 0;
  try
  {
    RRTVisualizer demo(node);
    demo.run();
    spin.join();
  }
  catch (const std::exception& error)
  {
    RCLCPP_ERROR(node->get_logger(), "%s", error.what());
    executor.cancel(); rclcpp::shutdown();
    if (spin.joinable()) spin.join();
    result = 1;
  }
  rclcpp::shutdown();
  return result;
}
