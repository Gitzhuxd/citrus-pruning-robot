"""不依赖 ROS 的面板输入校验及姿态计算。"""

import math

import numpy as np


DEFAULTS = {
    'step_size': 0.3, 'goal_bias': 0.1, 'collision_step': 0.04,
    'max_iterations': 2500, 'planning_time': 60.0, 'seed': 42,
    'replay_step': 0.08,
}


def validate_settings(settings):
    """限制计算量及离散碰撞检查分辨率，返回普通 Python 数值。"""
    bounds = {
        'step_size': (0.001, 6.3), 'goal_bias': (0.0, 1.0),
        'collision_step': (0.001, 0.2), 'planning_time': (0.1, 600.0),
        'replay_step': (0.0, 2.0),
    }
    result = {}
    for name, (lower, upper) in bounds.items():
        value = float(settings[name])
        if not math.isfinite(value) or not lower <= value <= upper:
            raise ValueError(f'{name} 必须在 [{lower}, {upper}] 范围内且为有限数值')
        result[name] = value
    for name, lower, upper in (
        ('max_iterations', 1, 100000), ('seed', 0, 2147483647),
    ):
        value = settings[name]
        if isinstance(value, bool) or not isinstance(value, (int, np.integer)):
            raise ValueError(f'{name} 必须为整数')
        if not lower <= value <= upper:
            raise ValueError(f'{name} 必须在 [{lower}, {upper}] 范围内')
        result[name] = int(value)
    return result


def validate_pose_values(position, quaternion):
    """验证米制位置、xyzw单位四元数；仅消除容差内的浮点归一化误差。"""
    position = np.asarray(position, dtype=float)
    quaternion = np.asarray(quaternion, dtype=float)
    if position.shape != (3,) or not np.all(np.isfinite(position)):
        raise ValueError('目标位置必须包含三个有限数值')
    if quaternion.shape != (4,) or not np.all(np.isfinite(quaternion)):
        raise ValueError('姿态四元数必须包含四个有限数值')
    norm = float(np.linalg.norm(quaternion))
    if abs(norm - 1.0) > 1e-3:
        raise ValueError('姿态四元数必须归一化，长度应为 1')
    return position, quaternion / norm


def pose_error(position_a, quaternion_a, position_b, quaternion_b):
    """返回平移误差(米)、最短旋转角误差(弧度)，q与-q等价。"""
    a, qa = validate_pose_values(position_a, quaternion_a)
    b, qb = validate_pose_values(position_b, quaternion_b)
    dot = min(1.0, abs(float(np.dot(qa, qb))))
    return float(np.linalg.norm(a - b)), 2.0 * math.acos(dot)


def rotation_matrix(quaternion):
    """xyzw单位四元数对应的工具到world旋转矩阵。"""
    _, q = validate_pose_values([0.0, 0.0, 0.0], quaternion)
    x, y, z, w = q
    return np.array([
        [1 - 2*(y*y + z*z), 2*(x*y - z*w), 2*(x*z + y*w)],
        [2*(x*y + z*w), 1 - 2*(x*x + z*z), 2*(y*z - x*w)],
        [2*(x*z - y*w), 2*(y*z + x*w), 1 - 2*(x*x + y*y)],
    ])
