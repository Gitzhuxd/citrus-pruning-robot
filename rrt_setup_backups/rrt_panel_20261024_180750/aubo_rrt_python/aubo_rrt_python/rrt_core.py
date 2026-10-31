"""基础 RRT：在有界关节空间规划，碰撞检查由调用者提供。"""

import math
import time

import numpy as np


def interpolate_edge(a, b, resolution):
    """线性插值，包含两端，任一关节的相邻增量不超过 resolution。"""
    a = np.asarray(a, dtype=float)
    b = np.asarray(b, dtype=float)
    if a.ndim != 1 or a.size == 0 or a.shape != b.shape:
        raise ValueError('边的两端必须是长度相同的非空一维数组')
    if not np.all(np.isfinite(a)) or not np.all(np.isfinite(b)):
        raise ValueError('边的两端必须是有限数值')
    if not math.isfinite(resolution) or resolution <= 0:
        raise ValueError('插值分辨率必须是有限正数')
    count = max(1, math.ceil(float(np.max(np.abs(b - a))) / resolution))
    points = [a + (b - a) * (i / count) for i in range(count + 1)]
    # 显式保留原始端点，避免最后一次浮点运算改变目标值。
    points[0] = a.copy()
    points[-1] = b.copy()
    return points


class _TimeBudgetExceeded(Exception):
    """内部用于从碰撞检查或显示回调返回规划超时。"""


class RRTPlanner:
    """单树 RRT，不做角度环绕、重连、平滑或轨迹执行。"""

    def __init__(
        self, lower, upper, is_state_valid, *, step_size=0.3,
        goal_bias=0.1, collision_step=0.04, max_iterations=2500,
        max_seconds=60.0, seed=42, on_node=None,
    ):
        self.lower = np.asarray(lower, dtype=float).copy()
        self.upper = np.asarray(upper, dtype=float).copy()
        if (
            self.lower.ndim != 1 or self.lower.size == 0
            or self.lower.shape != self.upper.shape
            or not np.all(np.isfinite(self.lower))
            or not np.all(np.isfinite(self.upper))
            or np.any(self.lower >= self.upper)
        ):
            raise ValueError('关节上下限必须长度一致、数值有限，且下限小于上限')
        for name, value in (
            ('step_size', step_size), ('collision_step', collision_step),
            ('max_seconds', max_seconds),
        ):
            if not math.isfinite(value) or value <= 0:
                raise ValueError(f'{name} 必须是有限正数')
        if not math.isfinite(goal_bias) or not 0 <= goal_bias <= 1:
            raise ValueError('goal_bias 必须位于 [0, 1]')
        if (
            isinstance(max_iterations, bool)
            or not isinstance(max_iterations, (int, np.integer))
            or max_iterations <= 0
        ):
            raise ValueError('max_iterations 必须是正整数')

        self.is_state_valid = is_state_valid
        self.step_size = float(step_size)
        self.goal_bias = float(goal_bias)
        self.collision_step = float(collision_step)
        self.max_iterations = int(max_iterations)
        self.max_seconds = float(max_seconds)
        self.seed = seed
        self.on_node = on_node
        self.nodes = []
        self.parents = []
        self.iterations = 0
        self.collision_checks = 0
        self.rejected_edges = 0
        self.elapsed_seconds = 0.0
        self.outcome = 'not_started'

    def _check_time(self):
        if time.perf_counter() >= self._deadline:
            raise _TimeBudgetExceeded()

    def _within_bounds(self, q):
        return (
            q.shape == self.lower.shape
            and np.all(np.isfinite(q))
            and np.all(q >= self.lower)
            and np.all(q <= self.upper)
        )

    def _state_valid(self, q):
        self._check_time()
        if not self._within_bounds(q):
            return False
        self.collision_checks += 1
        # 服务异常向外传播；不能把通讯故障当作碰撞或检查成功。
        valid = bool(self.is_state_valid(q.copy()))
        self._check_time()
        return valid

    def _edge_valid(self, a, b):
        # a 已经是树中检查通过的节点，因此仅检查后续插值点。
        for q in interpolate_edge(a, b, self.collision_step)[1:]:
            if not self._state_valid(q):
                self.rejected_edges += 1
                return False
        return True

    def _add_node(self, q, parent):
        self._check_time()
        index = len(self.nodes)
        self.nodes.append(q.copy())
        self.parents.append(parent)
        if self.on_node is not None:
            self.on_node(index, q.copy(), parent)
        # 显示回调和服务调用所用的时间也计入整个规划预算。
        self._check_time()
        return index

    def _path_to(self, index):
        path = []
        while index != -1:
            path.append(index)
            index = self.parents[index]
        path.reverse()
        self.outcome = 'success'
        return path

    def plan(self, start, goal):
        """返回起点到精确目标的节点索引；超时或耗尽迭代返回 None。"""
        self.nodes = []
        self.parents = []
        self.iterations = 0
        self.collision_checks = 0
        self.rejected_edges = 0
        self.elapsed_seconds = 0.0
        self.outcome = 'running'
        started = time.perf_counter()
        self._deadline = started + self.max_seconds
        rng = np.random.default_rng(self.seed)

        try:
            start = np.asarray(start, dtype=float).copy()
            goal = np.asarray(goal, dtype=float).copy()
            for name, q in (('start', start), ('goal', goal)):
                if not self._within_bounds(q):
                    self.outcome = f'invalid_{name}'
                    raise ValueError(f'{name} 维度不符、含非有限值或超出关节限位')
                if not self._state_valid(q):
                    self.outcome = f'invalid_{name}'
                    raise ValueError(f'{name} 未通过状态有效性检查')

            self._add_node(start, -1)
            if np.array_equal(start, goal):
                return self._path_to(0)

            for iteration in range(1, self.max_iterations + 1):
                self._check_time()
                self.iterations = iteration
                sample = (
                    goal if rng.random() < self.goal_bias
                    else rng.uniform(self.lower, self.upper)
                )
                distances = np.linalg.norm(np.asarray(self.nodes) - sample, axis=1)
                nearest = int(np.argmin(distances))
                q_near = self.nodes[nearest]
                delta = sample - q_near
                distance = float(np.linalg.norm(delta))
                if distance <= 1e-12:
                    continue
                q_new = (
                    sample.copy() if distance <= self.step_size
                    else q_near + delta * (self.step_size / distance)
                )

                if not self._edge_valid(q_near, q_new):
                    continue
                new_index = self._add_node(q_new, nearest)
                if np.array_equal(q_new, goal):
                    return self._path_to(new_index)

                # 接近目标只意味着可以尝试连接，最后一段仍须检查整条边。
                if np.linalg.norm(goal - q_new) <= self.step_size:
                    if self._edge_valid(q_new, goal):
                        goal_index = self._add_node(goal, new_index)
                        return self._path_to(goal_index)

            self._check_time()
            self.outcome = 'max_iterations'
            return None
        except _TimeBudgetExceeded:
            self.outcome = 'timeout'
            return None
        except Exception:
            if self.outcome == 'running':
                self.outcome = 'error'
            raise
        finally:
            self.elapsed_seconds = time.perf_counter() - started
