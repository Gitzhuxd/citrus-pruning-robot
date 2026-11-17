"""Scene helpers reused from the verified experiment script ``benchmark.py``.

``tree_transform``, ``world_counts`` and ``verify_world`` are copied verbatim.
"""
import time
from collections import Counter

import numpy as np
import rclpy
from moveit_msgs.msg import PlanningSceneComponents
from moveit_msgs.srv import GetPlanningScene
from rclpy.time import Time
from scipy.spatial.transform import Rotation
from tf2_ros import Buffer, TransformException, TransformListener

from .planner import FRAME


def tree_transform(node):
    buffer = Buffer()
    listener = TransformListener(buffer, node)
    until = time.monotonic() + 5
    while time.monotonic() < until:
        try:
            transform = buffer.lookup_transform(FRAME, "tree_base", Time()).transform
        except TransformException:
            rclpy.spin_once(node, timeout_sec=0.10)
            continue
        t, q = transform.translation, transform.rotation
        node.destroy_subscription(listener.tf_sub)
        node.destroy_subscription(listener.tf_static_sub)
        return np.array([t.x, t.y, t.z]), Rotation.from_quat([q.x, q.y, q.z, q.w])
    raise RuntimeError("Missing world to tree_base TF")


def world_counts(planner):
    client = planner.node.create_client(GetPlanningScene, "/get_planning_scene")
    request = GetPlanningScene.Request()
    request.components.components = PlanningSceneComponents.WORLD_OBJECT_GEOMETRY
    objects = planner.call(client, request).scene.world.collision_objects
    planner.node.destroy_client(client)
    return {item.id: len(item.primitives) for item in objects}


def verify_world(planner, model, obstacle):
    actual = world_counts(planner)
    expected = {"citrus_" + k: n for k, n in Counter(s["group"] for s in model["segments"]).items()}
    if obstacle is not None:
        raise ValueError("Neighbor obstacles belong to the archived benchmark scripts")
    if actual != expected:
        raise RuntimeError(f"Unexpected collision world: {actual}; expected {expected}")
    return actual
