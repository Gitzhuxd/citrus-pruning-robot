#ifndef AUBO_RRT_PANEL__RRT_PANEL_HPP_
#define AUBO_RRT_PANEL__RRT_PANEL_HPP_

#include <array>
#include <cstdint>
#include <functional>
#include <memory>

#include <QElapsedTimer>
#include <QString>
#include <rviz_common/panel.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <aubo_rrt_interfaces/action/plan_rrt.hpp>
#include <aubo_rrt_interfaces/msg/endpoint.hpp>
#include <aubo_rrt_interfaces/srv/get_rrt_info.hpp>
#include <aubo_rrt_interfaces/srv/preview_rrt.hpp>
#include <std_srvs/srv/trigger.hpp>

class QComboBox;
class QDoubleSpinBox;
class QGroupBox;
class QLabel;
class QPushButton;
class QSpinBox;
class QTimer;
class QWidget;

namespace aubo_rrt_panel
{

class RRTPanel : public rviz_common::Panel
{
  Q_OBJECT

public:
  explicit RRTPanel(QWidget * parent = nullptr);
  ~RRTPanel() override;
  void onInitialize() override;
  void load(const rviz_common::Config & config) override;
  void save(rviz_common::Config config) const override;

private:
  using Info = aubo_rrt_interfaces::srv::GetRRTInfo;
  using Preview = aubo_rrt_interfaces::srv::PreviewRRT;
  using Plan = aubo_rrt_interfaces::action::PlanRRT;
  using GoalHandle = rclcpp_action::ClientGoalHandle<Plan>;
  using Trigger = std_srvs::srv::Trigger;
  using Endpoint = aubo_rrt_interfaces::msg::Endpoint;

  struct EndpointWidgets
  {
    QGroupBox * group = nullptr;
    QComboBox * mode = nullptr;
    QComboBox * name = nullptr;
    std::array<QDoubleSpinBox *, 6> values{};
    QLabel * note = nullptr;
    QPushButton * read = nullptr;
    bool known = false;
  };

  // Only the Qt thread accesses panel. ROS callbacks just post closures holding this token.
  struct Lifetime {RRTPanel * panel = nullptr;};
  static void deliver(
    std::shared_ptr<Lifetime> lifetime, std::function<void(RRTPanel &)> callback);

  enum class Operation {Idle, Info, Preview, Plan, Replay, Save};
  void buildEndpoint(EndpointWidgets & endpoint, const QString & title, int mode);
  void updateEndpoint(EndpointWidgets & endpoint);
  void showPose(EndpointWidgets & endpoint, const geometry_msgs::msg::PoseStamped & pose);
  Endpoint endpointRequest(const EndpointWidgets & endpoint) const;
  Plan::Goal planRequest() const;
  void inputsChanged();
  void updateControls();
  void setStatus(const QString & text, bool error = false);
  void pollConnection();
  void requestInfo(int fill_endpoint = -1);
  void requestPreview();
  void startPlanning();
  void cancelPlanning();
  void trigger(bool save_task);
  void begin(Operation operation);
  void finish();
  void handleInfo(const Info::Response & response, int fill_endpoint);
  void saveEndpoint(rviz_common::Config config, const EndpointWidgets & endpoint) const;
  void loadEndpoint(const rviz_common::Config & config, EndpointWidgets & endpoint);

  std::shared_ptr<Lifetime> lifetime_;
  rclcpp::Node::SharedPtr node_;
  rclcpp::Client<Info>::SharedPtr info_client_;
  rclcpp::Client<Preview>::SharedPtr preview_client_;
  rclcpp::Client<Trigger>::SharedPtr replay_client_;
  rclcpp::Client<Trigger>::SharedPtr save_client_;
  rclcpp_action::Client<Plan>::SharedPtr plan_client_;
  GoalHandle::SharedPtr goal_handle_;

  EndpointWidgets start_;
  EndpointWidgets goal_;
  QWidget * parameters_ = nullptr;
  QDoubleSpinBox * step_ = nullptr;
  QDoubleSpinBox * bias_ = nullptr;
  QDoubleSpinBox * collision_step_ = nullptr;
  QSpinBox * iterations_ = nullptr;
  QDoubleSpinBox * time_ = nullptr;
  QSpinBox * seed_ = nullptr;
  QDoubleSpinBox * replay_step_ = nullptr;
  QPushButton * preview_button_ = nullptr;
  QPushButton * plan_button_ = nullptr;
  QPushButton * cancel_button_ = nullptr;
  QPushButton * replay_button_ = nullptr;
  QPushButton * save_button_ = nullptr;
  QLabel * connection_ = nullptr;
  QLabel * status_ = nullptr;
  QLabel * metrics_ = nullptr;
  QTimer * poll_timer_ = nullptr;
  QElapsedTimer operation_timer_;
  QElapsedTimer retry_timer_;

  Operation operation_ = Operation::Idle;
  uint64_t operation_id_ = 0;
  bool loading_ = false;
  bool reachable_ = false;
  bool ready_ = false;
  bool save_available_ = false;
  bool replay_available_ = false;
  bool initial_preview_ = true;
  bool cancel_requested_ = false;
};

}  // namespace aubo_rrt_panel
#endif  // AUBO_RRT_PANEL__RRT_PANEL_HPP_
