#include "aubo_rrt_panel/rrt_panel.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <utility>

#include <QComboBox>
#include <QCoreApplication>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMetaObject>
#include <QPushButton>
#include <QScrollArea>
#include <QSignalBlocker>
#include <QSpinBox>
#include <QTimer>
#include <QToolButton>
#include <QVBoxLayout>

#include <pluginlib/class_list_macros.hpp>
#include <rviz_common/display_context.hpp>
#include <rviz_common/ros_integration/ros_node_abstraction_iface.hpp>

namespace aubo_rrt_panel
{
namespace
{
constexpr double kPi = 3.14159265358979323846;
constexpr const char * kPoseKeys[] = {"X", "Y", "Z", "Roll", "Pitch", "Yaw"};

// Unknown CURRENT/NAMED coordinates must not look like real zero-valued poses.
class PoseSpinBox : public QDoubleSpinBox
{
public:
  explicit PoseSpinBox(QWidget * parent) : QDoubleSpinBox(parent) {}
  void setKnown(bool known)
  {
    known_ = known;
    lineEdit()->setText(textFromValue(value()));
  }
protected:
  QString textFromValue(double value) const override
  {
    return known_ ? QDoubleSpinBox::textFromValue(value) : QString::fromUtf8("—");
  }
private:
  bool known_ = false;
};

QDoubleSpinBox * number(
  QWidget * parent, double min, double max, double value, int decimals, double step)
{
  auto * spin = new QDoubleSpinBox(parent);
  spin->setRange(min, max);
  spin->setDecimals(decimals);
  spin->setSingleStep(step);
  spin->setValue(value);
  spin->setKeyboardTracking(false);
  return spin;
}

QString failure(const std::exception & error)
{
  return QString::fromUtf8(error.what());
}

bool validPose(const geometry_msgs::msg::PoseStamped & pose)
{
  const auto & p = pose.pose.position;
  const auto & q = pose.pose.orientation;
  const double norm = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
  return pose.header.frame_id == "world" && std::isfinite(p.x) && std::isfinite(p.y) &&
         std::isfinite(p.z) && std::isfinite(norm) && norm > 1.e-12;
}
}  // namespace

RRTPanel::RRTPanel(QWidget * parent)
: rviz_common::Panel(parent), lifetime_(std::make_shared<Lifetime>())
{
  lifetime_->panel = this;
  loading_ = true;
  auto * outer = new QVBoxLayout(this);
  outer->setContentsMargins(3, 3, 3, 3);
  auto * scroll = new QScrollArea(this);
  scroll->setWidgetResizable(true);
  scroll->setFrameShape(QFrame::NoFrame);
  auto * content = new QWidget(scroll);
  auto * layout = new QVBoxLayout(content);
  layout->setContentsMargins(5, 5, 5, 5);
  layout->setSpacing(7);
  connection_ = new QLabel("等待连接 RRT 后端", content);
  connection_->setWordWrap(true);
  layout->addWidget(connection_);
  auto * frame = new QLabel("参考系：world　工具：scissor_tcp", content);
  frame->setWordWrap(true);
  layout->addWidget(frame);

  buildEndpoint(start_, "起点", Endpoint::CURRENT);
  buildEndpoint(goal_, "终点", Endpoint::NAMED);
  goal_.name->addItem("pose1");
  layout->addWidget(start_.group);
  layout->addWidget(goal_.group);

  auto * parameter_toggle = new QToolButton(content);
  parameter_toggle->setText("规划参数");
  parameter_toggle->setCheckable(true);
  parameter_toggle->setArrowType(Qt::RightArrow);
  parameter_toggle->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  layout->addWidget(parameter_toggle);
  parameters_ = new QWidget(content);
  auto * form = new QFormLayout(parameters_);
  form->setContentsMargins(2, 0, 2, 0);
  form->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
  step_ = number(parameters_, .001, 6.3, .3, 3, .05);
  bias_ = number(parameters_, 0., 1., .1, 3, .05);
  collision_step_ = number(parameters_, .001, .2, .04, 3, .01);
  iterations_ = new QSpinBox(parameters_);
  iterations_->setRange(1, 100000);
  iterations_->setValue(2500);
  time_ = number(parameters_, .1, 600., 60., 1, 5.);
  seed_ = new QSpinBox(parameters_);
  seed_->setRange(0, std::numeric_limits<int>::max());
  seed_->setValue(42);
  replay_step_ = number(parameters_, 0., 2., .08, 3, .01);
  form->addRow("扩展步长（弧度）", step_);
  form->addRow("目标采样概率", bias_);
  form->addRow("碰撞检查步长（弧度）", collision_step_);
  form->addRow("最大迭代数", iterations_);
  form->addRow("搜索时限（秒）", time_);
  form->addRow("随机种子", seed_);
  form->addRow("节点回放间隔（秒）", replay_step_);
  step_->setToolTip("六维关节空间欧氏距离中的最大扩展量。");
  collision_step_->setToolTip("每条边插值检查时，单个关节的最大间隔。");
  replay_step_->setToolTip("逐个显示探索节点的时间间隔；0 表示立即显示全部探索树。");
  layout->addWidget(parameters_);
  parameters_->hide();
  connect(parameter_toggle, &QToolButton::toggled, this,
    [this, parameter_toggle](bool expanded) {
      parameters_->setVisible(expanded);
      parameter_toggle->setArrowType(expanded ? Qt::DownArrow : Qt::RightArrow);
    });
  for (auto * spin : {step_, bias_, collision_step_, time_, replay_step_}) {
    connect(spin, qOverload<double>(&QDoubleSpinBox::valueChanged),
      this, [this](double) {inputsChanged();});
  }
  for (auto * spin : {iterations_, seed_}) {
    connect(spin, qOverload<int>(&QSpinBox::valueChanged),
      this, [this](int) {inputsChanged();});
  }

  auto * buttons = new QGridLayout();
  preview_button_ = new QPushButton("检查并预览", content);
  plan_button_ = new QPushButton("开始规划", content);
  cancel_button_ = new QPushButton("取消规划", content);
  replay_button_ = new QPushButton("回放结果", content);
  save_button_ = new QPushButton("保存任务", content);
  buttons->addWidget(preview_button_, 0, 0);
  buttons->addWidget(plan_button_, 0, 1);
  buttons->addWidget(cancel_button_, 1, 0);
  buttons->addWidget(replay_button_, 1, 1);
  buttons->addWidget(save_button_, 2, 0, 1, 2);
  layout->addLayout(buttons);
  connect(preview_button_, &QPushButton::clicked, this, &RRTPanel::requestPreview);
  connect(plan_button_, &QPushButton::clicked, this, &RRTPanel::startPlanning);
  connect(cancel_button_, &QPushButton::clicked, this, &RRTPanel::cancelPlanning);
  connect(replay_button_, &QPushButton::clicked, this, [this]() {trigger(false);});
  connect(save_button_, &QPushButton::clicked, this, [this]() {trigger(true);});

  status_ = new QLabel("启动 rrt_server 后可在此设置任务。", content);
  status_->setWordWrap(true);
  status_->setTextFormat(Qt::PlainText);
  status_->setTextInteractionFlags(Qt::TextSelectableByMouse);
  metrics_ = new QLabel("探索节点：—　迭代：—\n搜索耗时：—", content);
  metrics_->setWordWrap(true);
  layout->addWidget(status_);
  layout->addWidget(metrics_);
  auto * note = new QLabel(
    "位置用米，姿态用度（Rz·Ry·Rx）。\n"
    "本面板用于仿真预览。RRT 运动途中朝向自由；果树外观不等于碰撞体。", content);
  note->setWordWrap(true);
  note->setStyleSheet("color: #77808b; font-size: 11px;");
  layout->addWidget(note);
  layout->addStretch(1);
  scroll->setWidget(content);
  outer->addWidget(scroll);
  poll_timer_ = new QTimer(this);
  poll_timer_->setInterval(1000);
  connect(poll_timer_, &QTimer::timeout, this, &RRTPanel::pollConnection);
  loading_ = false;
  updateControls();
}

RRTPanel::~RRTPanel()
{
  // Posted lambdas inspect this token only on the same Qt thread as destruction.
  lifetime_->panel = nullptr;
  poll_timer_->stop();
  if (goal_handle_ && plan_client_) {
    try {plan_client_->async_cancel_goal(goal_handle_);} catch (const std::exception &) {}
  }
}

void RRTPanel::deliver(
  std::shared_ptr<Lifetime> lifetime, std::function<void(RRTPanel &)> callback)
{
  if (auto * app = QCoreApplication::instance()) {
    QMetaObject::invokeMethod(app, [lifetime, callback = std::move(callback)]() {
      if (lifetime->panel) {callback(*lifetime->panel);}
    }, Qt::QueuedConnection);
  }
}

void RRTPanel::onInitialize()
{
  try {
    auto abstraction = getDisplayContext()->getRosNodeAbstraction().lock();
    if (!abstraction) {throw std::runtime_error("RViz ROS 节点尚未创建");}
    node_ = abstraction->get_raw_node();
    info_client_ = node_->create_client<Info>("/rrt_python/info");
    preview_client_ = node_->create_client<Preview>("/rrt_python/preview");
    replay_client_ = node_->create_client<Trigger>("/rrt_python/replay");
    save_client_ = node_->create_client<Trigger>("/rrt_python/save_task");
    plan_client_ = rclcpp_action::create_client<Plan>(node_, "/rrt_python/plan");
    poll_timer_->start();
    pollConnection();
  } catch (const std::exception & error) {
    setStatus("面板初始化失败：" + failure(error), true);
  }
}

void RRTPanel::buildEndpoint(EndpointWidgets & endpoint, const QString & title, int mode)
{
  endpoint.group = new QGroupBox(title, this);
  auto * grid = new QGridLayout(endpoint.group);
  grid->setContentsMargins(7, 9, 7, 7);
  grid->setHorizontalSpacing(4);
  endpoint.mode = new QComboBox(endpoint.group);
  endpoint.mode->addItem("当前机械臂状态", Endpoint::CURRENT);
  endpoint.mode->addItem("命名姿态", Endpoint::NAMED);
  endpoint.mode->addItem("手动输入位姿", Endpoint::POSE);
  endpoint.mode->setCurrentIndex(mode);
  endpoint.name = new QComboBox(endpoint.group);
  endpoint.name->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
  endpoint.name->setMinimumContentsLength(5);
  grid->addWidget(endpoint.mode, 0, 0, 1, 3);
  grid->addWidget(endpoint.name, 1, 0, 1, 3);
  for (std::size_t i = 0; i < endpoint.values.size(); ++i) {
    auto * spin = new PoseSpinBox(endpoint.group);
    const bool position = i < 3;
    spin->setRange(position ? -100. : -360., position ? 100. : 360.);
    spin->setDecimals(position ? 5 : 3);
    spin->setSingleStep(position ? .01 : 5.);
    spin->setKeyboardTracking(false);
    spin->setMinimumWidth(68);
    endpoint.values[i] = spin;
    const int row = position ? 2 : 4;
    const int column = static_cast<int>(i % 3);
    grid->addWidget(new QLabel(
        QString::fromLatin1(kPoseKeys[i]) + (position ? "（米）" : "（°）"), endpoint.group),
      row, column);
    grid->addWidget(spin, row + 1, column);
    connect(spin, qOverload<double>(&QDoubleSpinBox::valueChanged),
      this, [this](double) {inputsChanged();});
  }
  endpoint.read = new QPushButton("填入当前末端位姿", endpoint.group);
  endpoint.read->setToolTip("读取当前 TCP 位置和朝向，并切换到手动输入，方便在此基础上修改。");
  grid->addWidget(endpoint.read, 6, 0, 1, 3);
  endpoint.note = new QLabel(endpoint.group);
  endpoint.note->setWordWrap(true);
  grid->addWidget(endpoint.note, 7, 0, 1, 3);
  auto * target = &endpoint;
  connect(endpoint.mode, qOverload<int>(&QComboBox::currentIndexChanged), this,
    [this, target](int) {
      if (loading_) {return;}
      if (target->mode->currentData().toInt() != Endpoint::POSE) {target->known = false;}
      updateEndpoint(*target);
      inputsChanged();
    });
  connect(endpoint.name, qOverload<int>(&QComboBox::currentIndexChanged), this,
    [this, target](int) {
      if (loading_) {return;}
      target->known = false;
      updateEndpoint(*target);
      inputsChanged();
    });
  connect(endpoint.read, &QPushButton::clicked, this,
    [this, target]() {requestInfo(target == &start_ ? 0 : 1);});
  updateEndpoint(endpoint);
}

void RRTPanel::updateEndpoint(EndpointWidgets & endpoint)
{
  const int mode = endpoint.mode->currentData().toInt();
  const bool manual = mode == Endpoint::POSE;
  endpoint.name->setVisible(mode == Endpoint::NAMED);
  for (auto * spin : endpoint.values) {
    spin->setEnabled(manual);
    static_cast<PoseSpinBox *>(spin)->setKnown(manual || endpoint.known);
  }
  if (manual) {
    endpoint.note->setText("设置 scissor_tcp 的位置与朝向。");
  } else if (endpoint.known) {
    endpoint.note->setText(mode == Endpoint::CURRENT ?
      "已读取当前位姿；规划时重新读取当前关节状态。" : "已解析命名姿态的末端位姿。");
  } else {
    endpoint.note->setText("位姿尚未解析，点击“检查并预览”读取。");
  }
}

void RRTPanel::showPose(
  EndpointWidgets & endpoint, const geometry_msgs::msg::PoseStamped & pose)
{
  if (!validPose(pose)) {return;}
  const auto & p = pose.pose.position;
  const auto & q = pose.pose.orientation;
  const double norm = std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
  const double x = q.x / norm, y = q.y / norm, z = q.z / norm, w = q.w / norm;
  const double sin_pitch = std::clamp(2. * (w * y - z * x), -1., 1.);
  const bool singular = std::abs(sin_pitch) > 1. - 1.e-12;
  // At pitch = +/-90 degrees, choose roll = 0 and retain the equivalent yaw.
  const double roll = singular ? 0. :
    std::atan2(2. * (w * x + y * z), 1. - 2. * (x * x + y * y));
  const double yaw = singular ?
    std::atan2(2. * (w * z - x * y), 1. - 2. * (x * x + z * z)) :
    std::atan2(2. * (w * z + x * y), 1. - 2. * (y * y + z * z));
  const std::array<double, 6> values = {
    p.x, p.y, p.z, roll * 180. / kPi, std::asin(sin_pitch) * 180. / kPi,
    yaw * 180. / kPi};
  for (std::size_t i = 0; i < values.size(); ++i) {
    const QSignalBlocker blocker(endpoint.values[i]);
    endpoint.values[i]->setValue(values[i]);
  }
  endpoint.known = true;
  updateEndpoint(endpoint);
}

RRTPanel::Endpoint RRTPanel::endpointRequest(const EndpointWidgets & endpoint) const
{
  Endpoint request;
  request.mode = static_cast<uint8_t>(endpoint.mode->currentData().toInt());
  request.name = endpoint.name->currentText().toStdString();
  request.pose.header.frame_id = "world";
  auto & pose = request.pose.pose;
  pose.position.x = endpoint.values[0]->value();
  pose.position.y = endpoint.values[1]->value();
  pose.position.z = endpoint.values[2]->value();
  const double r = endpoint.values[3]->value() * kPi / 360.;
  const double p = endpoint.values[4]->value() * kPi / 360.;
  const double y = endpoint.values[5]->value() * kPi / 360.;
  pose.orientation.x = std::sin(r) * std::cos(p) * std::cos(y) -
    std::cos(r) * std::sin(p) * std::sin(y);
  pose.orientation.y = std::cos(r) * std::sin(p) * std::cos(y) +
    std::sin(r) * std::cos(p) * std::sin(y);
  pose.orientation.z = std::cos(r) * std::cos(p) * std::sin(y) -
    std::sin(r) * std::sin(p) * std::cos(y);
  pose.orientation.w = std::cos(r) * std::cos(p) * std::cos(y) +
    std::sin(r) * std::sin(p) * std::sin(y);
  return request;
}

RRTPanel::Plan::Goal RRTPanel::planRequest() const
{
  Plan::Goal request;
  request.start = endpointRequest(start_);
  request.goal = endpointRequest(goal_);
  request.step_size = step_->value();
  request.goal_bias = bias_->value();
  request.collision_step = collision_step_->value();
  request.max_iterations = iterations_->value();
  request.planning_time = time_->value();
  request.seed = seed_->value();
  request.replay_step = replay_step_->value();
  return request;
}

void RRTPanel::inputsChanged()
{
  if (loading_) {return;}
  save_available_ = false;
  replay_available_ = false;
  if (status_) {setStatus("输入已修改，请检查预览或开始规划。");}
  updateControls();
  Q_EMIT configChanged();
}

void RRTPanel::setStatus(const QString & text, bool error)
{
  status_->setText(text);
  status_->setStyleSheet(error ? "color: #d8665a;" : "");
}

void RRTPanel::updateControls()
{
  const bool idle = operation_ == Operation::Idle;
  start_.group->setEnabled(idle);
  goal_.group->setEnabled(idle);
  parameters_->setEnabled(idle);
  start_.read->setEnabled(idle && ready_);
  goal_.read->setEnabled(idle && ready_);
  preview_button_->setEnabled(idle && ready_);
  plan_button_->setEnabled(idle && ready_);
  cancel_button_->setEnabled(operation_ == Operation::Plan && !cancel_requested_);
  replay_button_->setEnabled(idle && ready_ && replay_available_);
  save_button_->setEnabled(idle && ready_ && save_available_);
}

void RRTPanel::begin(Operation operation)
{
  operation_ = operation;
  ++operation_id_;
  operation_timer_.restart();
  updateControls();
}

void RRTPanel::finish()
{
  operation_ = Operation::Idle;
  goal_handle_.reset();
  cancel_requested_ = false;
  updateControls();
}

void RRTPanel::pollConnection()
{
  if (!info_client_) {return;}
  const bool connected = info_client_->service_is_ready() &&
    preview_client_->service_is_ready() && replay_client_->service_is_ready() &&
    save_client_->service_is_ready() && plan_client_->action_server_is_ready();
  if (!connected) {
    connection_->setText("未连接：请启动 aubo_rrt_python rrt_server");
    if (reachable_) {
      ready_ = false;
      save_available_ = false;
      replay_available_ = false;
      initial_preview_ = true;
      ++operation_id_;
      finish();
      setStatus("RRT 后端连接已断开，等待重新连接。", true);
    }
    reachable_ = false;
    updateControls();
    return;
  }
  reachable_ = true;
  if (operation_ != Operation::Idle && operation_ != Operation::Plan &&
    operation_timer_.elapsed() > 30000)
  {
    // Remove abandoned rclcpp promises as well as ignoring any late Qt callbacks.
    info_client_->prune_pending_requests();
    preview_client_->prune_pending_requests();
    replay_client_->prune_pending_requests();
    save_client_->prune_pending_requests();
    ++operation_id_;
    save_available_ = false;
    replay_available_ = false;
    finish();
    setStatus("服务响应超时，请检查后端终端后重试。", true);
  }
  if (!ready_ && operation_ == Operation::Idle &&
    (!retry_timer_.isValid() || retry_timer_.elapsed() > 3000))
  {
    requestInfo();
  }
}

void RRTPanel::requestInfo(int fill_endpoint)
{
  if (operation_ != Operation::Idle || !info_client_ || !info_client_->service_is_ready()) {
    return;
  }
  begin(Operation::Info);
  retry_timer_.restart();
  if (fill_endpoint >= 0) {setStatus("正在读取当前末端位姿…");}
  const auto id = operation_id_;
  try {
    info_client_->async_send_request(std::make_shared<Info::Request>(),
      [life = lifetime_, id, fill_endpoint](rclcpp::Client<Info>::SharedFuture future) {
        try {
          const auto result = future.get();
          deliver(life, [id, fill_endpoint, result](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.finish();
            panel.handleInfo(*result, fill_endpoint);
          });
        } catch (const std::exception & error) {
          const auto text = failure(error);
          deliver(life, [id, text](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.finish();
            panel.setStatus("读取状态失败：" + text, true);
          });
        }
      });
  } catch (const std::exception & error) {
    finish();
    setStatus("读取状态失败：" + failure(error), true);
  }
}

void RRTPanel::handleInfo(const Info::Response & response, int fill_endpoint)
{
  ready_ = response.ready;
  connection_->setText(ready_ ? "已连接 · RRT 后端就绪" : "已连接 · 等待 MoveIt 就绪");
  if (!ready_) {
    setStatus(QString::fromStdString(response.message), true);
    updateControls();
    return;
  }
  for (auto * endpoint : {&start_, &goal_}) {
    const QString desired = endpoint->name->currentText();
    const QSignalBlocker blocker(endpoint->name);
    endpoint->name->clear();
    for (const auto & name : response.named_states) {
      endpoint->name->addItem(QString::fromStdString(name));
    }
    const int index = endpoint->name->findText(desired);
    // A removed/unknown saved name remains visible, so the backend can explain the error.
    if (index < 0 && !desired.isEmpty()) {endpoint->name->addItem(desired);}
    endpoint->name->setCurrentIndex(index >= 0 ? index : endpoint->name->findText(desired));
    if (endpoint->name->currentIndex() < 0 && endpoint->name->count()) {
      endpoint->name->setCurrentIndex(0);
    }
    if (endpoint->mode->currentData().toInt() == Endpoint::CURRENT) {
      showPose(*endpoint, response.current_pose);
    }
  }
  if (fill_endpoint >= 0) {
    if (!validPose(response.current_pose)) {
      setStatus("后端返回的当前末端位姿无效，请检查 FK 服务。", true);
    } else {
      auto & endpoint = fill_endpoint == 0 ? start_ : goal_;
      {
        const QSignalBlocker blocker(endpoint.mode);
        endpoint.mode->setCurrentIndex(Endpoint::POSE);
      }
      showPose(endpoint, response.current_pose);
      inputsChanged();
      setStatus("已填入当前末端位置和朝向，可修改后检查预览。");
    }
  }
  updateControls();
  if (initial_preview_ && fill_endpoint < 0) {
    initial_preview_ = false;
    requestPreview();
  }
}

void RRTPanel::requestPreview()
{
  if (!ready_ || operation_ != Operation::Idle) {return;}
  save_available_ = false;
  replay_available_ = false;
  begin(Operation::Preview);
  setStatus("正在解析起终点并检查限位、碰撞和逆运动学…");
  const auto parameters = planRequest();
  auto request = std::make_shared<Preview::Request>();
  request->start = parameters.start;
  request->goal = parameters.goal;
  request->step_size = parameters.step_size;
  request->goal_bias = parameters.goal_bias;
  request->collision_step = parameters.collision_step;
  request->max_iterations = parameters.max_iterations;
  request->planning_time = parameters.planning_time;
  request->seed = parameters.seed;
  request->replay_step = parameters.replay_step;
  const auto id = operation_id_;
  try {
    preview_client_->async_send_request(request,
      [life = lifetime_, id](rclcpp::Client<Preview>::SharedFuture future) {
        try {
          const auto result = future.get();
          deliver(life, [id, result](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.save_available_ = result->success;
            if (result->success) {
              // Preserve typed POSE values exactly; show resolved values for other modes.
              if (panel.start_.mode->currentData().toInt() != Endpoint::POSE) {
                panel.showPose(panel.start_, result->start_pose);
              }
              if (panel.goal_.mode->currentData().toInt() != Endpoint::POSE) {
                panel.showPose(panel.goal_, result->goal_pose);
              }
            }
            panel.finish();
            panel.setStatus(QString::fromStdString(result->message), !result->success);
          });
        } catch (const std::exception & error) {
          const auto text = failure(error);
          deliver(life, [id, text](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.finish();
            panel.setStatus("预览失败：" + text, true);
          });
        }
      });
  } catch (const std::exception & error) {
    finish();
    setStatus("预览失败：" + failure(error), true);
  }
}

void RRTPanel::startPlanning()
{
  if (!ready_ || operation_ != Operation::Idle) {return;}
  save_available_ = false;
  replay_available_ = false;
  cancel_requested_ = false;
  begin(Operation::Plan);
  setStatus("正在提交规划任务并检查起终点…");
  metrics_->setText("探索节点：—　迭代：—\n搜索耗时：—");
  const auto id = operation_id_;
  auto options = rclcpp_action::Client<Plan>::SendGoalOptions();
  options.goal_response_callback = [life = lifetime_, id](GoalHandle::SharedPtr handle) {
      deliver(life, [id, handle](RRTPanel & panel) {
        if (id != panel.operation_id_) {return;}
        if (!handle) {
          panel.finish();
          panel.setStatus("规划请求被拒绝：后端可能正在处理其他任务。", true);
          return;
        }
        panel.goal_handle_ = handle;
        if (panel.cancel_requested_) {
          panel.cancel_requested_ = false;
          panel.cancelPlanning();
        } else {
          panel.setStatus("任务已接受，正在解析起终点…");
        }
      });
    };
  options.feedback_callback = [life = lifetime_, id](
    GoalHandle::SharedPtr, const std::shared_ptr<const Plan::Feedback> feedback) {
      deliver(life, [id, feedback](RRTPanel & panel) {
        if (id != panel.operation_id_ || panel.operation_ != Operation::Plan) {return;}
        if (!panel.cancel_requested_) {
          panel.setStatus(QString::fromStdString(feedback->phase));
        }
        panel.metrics_->setText(QString("探索节点：%1　迭代：%2\n耗时：%3 秒")
          .arg(feedback->tree_nodes).arg(feedback->iterations)
          .arg(feedback->elapsed_seconds, 0, 'f', 2));
      });
    };
  options.result_callback = [life = lifetime_, id](const GoalHandle::WrappedResult & wrapped) {
      deliver(life, [id, wrapped](RRTPanel & panel) {
        if (id != panel.operation_id_) {return;}
        const auto & result = wrapped.result;
        const bool success = wrapped.code == rclcpp_action::ResultCode::SUCCEEDED &&
          result && result->success;
        panel.replay_available_ = success;
        panel.save_available_ = success;
        panel.finish();
        if (result) {
          panel.metrics_->setText(QString("探索节点：%1　迭代：%2\n路径节点：%3　搜索耗时：%4 秒")
            .arg(result->tree_nodes).arg(result->iterations).arg(result->path_nodes)
            .arg(result->planning_seconds, 0, 'f', 2));
          QString message = QString::fromStdString(result->message);
          if (success && !result->output_directory.empty()) {
            message += "\n结果：" + QString::fromStdString(result->output_directory);
          }
          panel.setStatus(message, !success && wrapped.code != rclcpp_action::ResultCode::CANCELED);
        } else {
          panel.setStatus("未收到有效规划结果，请检查后端终端。", true);
        }
      });
    };
  try {
    plan_client_->async_send_goal(planRequest(), options);
  } catch (const std::exception & error) {
    finish();
    setStatus("规划请求失败：" + failure(error), true);
  }
}

void RRTPanel::cancelPlanning()
{
  if (operation_ != Operation::Plan || cancel_requested_) {return;}
  cancel_requested_ = true;
  updateControls();
  setStatus("已请求取消，等待后端停止…");
  if (!goal_handle_) {return;}
  const auto id = operation_id_;
  try {
    plan_client_->async_cancel_goal(goal_handle_,
      [life = lifetime_, id](rclcpp_action::Client<Plan>::CancelResponse::SharedPtr response) {
        deliver(life, [id, response](RRTPanel & panel) {
          if (id != panel.operation_id_ || panel.operation_ != Operation::Plan) {return;}
          if (response->goals_canceling.empty()) {
            panel.cancel_requested_ = false;
            panel.updateControls();
            panel.setStatus("取消未被接受，任务可能已完成；等待最终结果。", true);
          }
        });
      });
  } catch (const std::exception & error) {
    cancel_requested_ = false;
    updateControls();
    setStatus("取消请求失败：" + failure(error), true);
  }
}

void RRTPanel::trigger(bool save_task)
{
  if (!ready_ || operation_ != Operation::Idle ||
    (save_task ? !save_available_ : !replay_available_)) {return;}
  begin(save_task ? Operation::Save : Operation::Replay);
  setStatus(save_task ? "正在保存任务…" : "正在请求回放…");
  const auto id = operation_id_;
  try {
    auto client = save_task ? save_client_ : replay_client_;
    client->async_send_request(std::make_shared<Trigger::Request>(),
      [life = lifetime_, id](rclcpp::Client<Trigger>::SharedFuture future) {
        try {
          const auto result = future.get();
          deliver(life, [id, result](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.finish();
            panel.setStatus(QString::fromStdString(result->message), !result->success);
          });
        } catch (const std::exception & error) {
          const auto text = failure(error);
          deliver(life, [id, text](RRTPanel & panel) {
            if (id != panel.operation_id_) {return;}
            panel.finish();
            panel.setStatus("操作失败：" + text, true);
          });
        }
      });
  } catch (const std::exception & error) {
    finish();
    setStatus("操作失败：" + failure(error), true);
  }
}

void RRTPanel::saveEndpoint(
  rviz_common::Config config, const EndpointWidgets & endpoint) const
{
  config.mapSetValue("Mode", endpoint.mode->currentData().toInt());
  config.mapSetValue("Name", endpoint.name->currentText());
  for (std::size_t i = 0; i < endpoint.values.size(); ++i) {
    config.mapSetValue(kPoseKeys[i], endpoint.values[i]->value());
  }
}

void RRTPanel::loadEndpoint(const rviz_common::Config & config, EndpointWidgets & endpoint)
{
  int mode;
  if (config.mapGetInt("Mode", &mode) && mode >= Endpoint::CURRENT && mode <= Endpoint::POSE) {
    endpoint.mode->setCurrentIndex(mode);
  }
  QString name;
  if (config.mapGetString("Name", &name) && !name.isEmpty()) {
    if (endpoint.name->findText(name) < 0) {endpoint.name->addItem(name);}
    endpoint.name->setCurrentText(name);
  }
  for (std::size_t i = 0; i < endpoint.values.size(); ++i) {
    const QVariant value = config.mapGetChild(kPoseKeys[i]).getValue();
    bool ok = false;
    const double parsed = value.toDouble(&ok);
    if (ok && std::isfinite(parsed)) {endpoint.values[i]->setValue(parsed);}
  }
  endpoint.known = false;
  updateEndpoint(endpoint);
}

void RRTPanel::save(rviz_common::Config config) const
{
  rviz_common::Panel::save(config);
  saveEndpoint(config.mapMakeChild("Start"), start_);
  saveEndpoint(config.mapMakeChild("Goal"), goal_);
  auto parameters = config.mapMakeChild("Parameters");
  parameters.mapSetValue("step_size", step_->value());
  parameters.mapSetValue("goal_bias", bias_->value());
  parameters.mapSetValue("collision_step", collision_step_->value());
  parameters.mapSetValue("max_iterations", iterations_->value());
  parameters.mapSetValue("planning_time", time_->value());
  parameters.mapSetValue("seed", seed_->value());
  parameters.mapSetValue("replay_step", replay_step_->value());
}

void RRTPanel::load(const rviz_common::Config & config)
{
  rviz_common::Panel::load(config);
  loading_ = true;
  loadEndpoint(config.mapGetChild("Start"), start_);
  loadEndpoint(config.mapGetChild("Goal"), goal_);
  const auto parameters = config.mapGetChild("Parameters");
  const std::array<std::pair<const char *, QDoubleSpinBox *>, 5> doubles = {{
    {"step_size", step_}, {"goal_bias", bias_}, {"collision_step", collision_step_},
    {"planning_time", time_}, {"replay_step", replay_step_}}};
  for (const auto & item : doubles) {
    bool ok = false;
    const double parsed = parameters.mapGetChild(item.first).getValue().toDouble(&ok);
    if (ok && std::isfinite(parsed)) {item.second->setValue(parsed);}
  }
  int value;
  if (parameters.mapGetInt("max_iterations", &value)) {iterations_->setValue(value);}
  if (parameters.mapGetInt("seed", &value)) {seed_->setValue(value);}
  loading_ = false;
  save_available_ = false;
  replay_available_ = false;
  initial_preview_ = true;
  updateControls();
}

}  // namespace aubo_rrt_panel

PLUGINLIB_EXPORT_CLASS(aubo_rrt_panel::RRTPanel, rviz_common::Panel)
