#!/usr/bin/env python3
"""Independently check a saved RRT export, including URDF forward kinematics."""

import csv
import json
import math
from pathlib import Path
import sys
import xml.etree.ElementTree as ET

import numpy as np
import yaml


TOLERANCE = 1e-8


def require(condition, message):
    if not condition:
        raise ValueError(message)


def read_rows(path):
    with path.open(encoding="utf-8", newline="") as stream:
        reader = csv.DictReader(stream)
        rows = list(reader)
        return reader.fieldnames or [], rows


def values(row, names):
    result = np.array([float(row[name]) for name in names], dtype=float)
    require(np.isfinite(result).all(), "Nonfinite coordinate in CSV")
    return result


def xyz(text, fallback):
    result = np.array([float(v) for v in (text or fallback).split()])
    require(result.shape == (3,), "URDF vector must have three components")
    return result


def rotation(axis, angle):
    norm = np.linalg.norm(axis)
    require(norm > 0, "URDF joint has a zero rotation axis")
    x, y, z = axis / norm
    skew = np.array([[0, -z, y], [z, 0, -x], [-y, x, 0]])
    return np.eye(3) + math.sin(angle) * skew + (1 - math.cos(angle)) * (skew @ skew)


def urdf_chain(urdf_path, srdf_path, frame, tcp):
    robot = ET.parse(urdf_path).getroot()
    joints = {joint.attrib["name"]: joint for joint in robot.findall("joint")}
    links = {link.attrib["name"] for link in robot.findall("link")}
    child_joints = {}
    for joint in joints.values():
        child = joint.find("child").attrib["link"]
        require(child not in child_joints, "Multiple URDF parents for " + child)
        child_joints[child] = joint
    roots = links - set(child_joints)
    require(len(roots) == 1, "URDF must have one root link")
    root = next(iter(roots))
    frame = frame.lstrip("/")
    if frame != root:
        virtual = ET.parse(srdf_path).getroot().findall("virtual_joint")
        require(any(j.get("type") == "fixed" and j.get("parent_frame") == frame
                    and j.get("child_link") == root for j in virtual),
                "Model frame is not the URDF root or an identity fixed virtual parent")

    require(tcp in links, "TCP link absent from URDF")
    chain, visited = [], set()
    link = tcp
    while link != root:
        require(link not in visited and link in child_joints, "Broken or cyclic TCP chain")
        visited.add(link)
        joint = child_joints[link]
        origin = joint.find("origin")
        offset = xyz(origin.get("xyz") if origin is not None else None, "0 0 0")
        roll, pitch, yaw = xyz(origin.get("rpy") if origin is not None else None, "0 0 0")
        transform = np.eye(4)
        transform[:3, :3] = (rotation(np.array([0, 0, 1]), yaw)
                             @ rotation(np.array([0, 1, 0]), pitch)
                             @ rotation(np.array([1, 0, 0]), roll))
        transform[:3, 3] = offset
        axis = joint.find("axis")
        chain.append((joint, transform, xyz(axis.get("xyz") if axis is not None else None, "1 0 0")))
        link = joint.find("parent").attrib["link"]
    chain.reverse()

    def joint_value(name, configuration, active=None):
        if name in configuration:
            return configuration[name]
        active = set() if active is None else active
        require(name not in active, "Cyclic URDF mimic relationship")
        active.add(name)
        mimic = joints[name].find("mimic")
        require(mimic is not None, "Missing joint value for TCP-chain joint " + name)
        return (float(mimic.get("multiplier", "1"))
                * joint_value(mimic.attrib["joint"], configuration, active)
                + float(mimic.get("offset", "0")))

    def fk(configuration):
        transform = np.eye(4)
        for joint, origin, axis in chain:
            transform = transform @ origin
            kind = joint.attrib["type"]
            if kind == "fixed":
                continue
            amount = joint_value(joint.attrib["name"], configuration)
            motion = np.eye(4)
            if kind in ("revolute", "continuous"):
                motion[:3, :3] = rotation(axis, amount)
            elif kind == "prismatic":
                require(np.linalg.norm(axis) > 0, "URDF joint has a zero translation axis")
                motion[:3, 3] = axis / np.linalg.norm(axis) * amount
            else:
                raise ValueError("Unsupported TCP-chain joint type: " + kind)
            transform = transform @ motion
        return transform[:3, 3]

    return root, [joint.attrib["name"] for joint, _, _ in chain], fk


def validate(directory):
    metadata = yaml.safe_load((directory / "metadata.yaml").read_text(encoding="utf-8"))
    require(isinstance(metadata, dict), "metadata.yaml must be a mapping")
    require(metadata.get("planner_type") == "geometric::RRT", "Actual planner is not geometric::RRT")
    require(metadata.get("planner_id") == "RRTkConfigDefault", "Unexpected planner ID")
    require(metadata.get("group") == "aubo_arm" and metadata.get("tcp_link") == "scissor_tcp",
            "Unexpected planning group or TCP")
    require(metadata.get("planning_attempts") == 1, "Export is not a single planning attempt")
    for key in ("invalid_vertices", "invalid_edges", "path_validation_failures"):
        require(key in metadata and metadata[key] == 0, key + " must be zero")
    for name in ("robot.urdf", "robot.srdf", "request.cdr", "planning_scene.cdr", "scene.rviz"):
        require((directory / name).is_file() and (directory / name).stat().st_size > 0,
                "Missing or empty artifact: " + name)

    headers, rows = read_rows(directory / "vertices.csv")
    excluded = {"id", "is_start", "is_goal", "tcp_x", "tcp_y", "tcp_z"}
    joint_names = [name for name in headers if name not in excluded]
    require(len(joint_names) == 6, "Expected exactly six joint coordinate columns")
    ids = [int(row["id"]) for row in rows]
    require(len(ids) == len(set(ids)), "Duplicate vertex IDs")
    vertices = {int(row["id"]): row for row in rows}
    _, edge_rows = read_rows(directory / "edges.csv")
    edge_list = [(int(row["source"]), int(row["target"])) for row in edge_rows]
    edges = set(edge_list)
    require(len(edges) == len(edge_list), "Duplicate tree edges")
    require(metadata.get("vertex_count") == len(rows), "Vertex count mismatch")
    require(metadata.get("edge_count") == len(edges), "Edge count mismatch")
    children = {vertex: set() for vertex in ids}
    indegree = {vertex: 0 for vertex in ids}
    for source, target in edges:
        require(source in vertices and target in vertices, "Edge references an unknown vertex")
        require(source != target, "Tree self-edge")
        children[source].add(target)
        indegree[target] += 1

    root_link, chain_names, fk = urdf_chain(directory / "robot.urdf", directory / "robot.srdf",
                                           metadata["frame"], metadata["tcp_link"])
    max_error, fk_rows = 0.0, 0

    def check_fk(table):
        nonlocal max_error, fk_rows
        for row in table:
            q = values(row, joint_names)
            expected = fk(dict(zip(joint_names, q)))
            actual = values(row, ["tcp_x", "tcp_y", "tcp_z"])
            max_error = max(max_error, float(np.linalg.norm(expected - actual)))
            fk_rows += 1

    check_fk(rows)
    stages = {}
    for stage in metadata.get("stages") or []:
        name = stage["name"]
        require(name in ("plan", "simplify", "interpolate") and name not in stages,
                "Unexpected or repeated path stage")
        stage_headers, table = read_rows(directory / (name + ".csv"))
        require(set(joint_names).issubset(stage_headers), "Stage joint columns mismatch")
        require(len(table) == stage["waypoint_count"], name + " waypoint count mismatch")
        require([int(row["waypoint"]) for row in table] == list(range(len(table))),
                name + " waypoint indices are not consecutive")
        check_fk(table)
        stages[name] = table
    require(max_error < TOLERANCE, "Independent FK disagrees with exported TCP: " + str(max_error))

    exact = metadata.get("exact_solution") is True
    raw_ids = []
    if exact:
        require(not metadata.get("approximate_solution"), "Exact and approximate flags conflict")
        require(metadata.get("moveit_error_code") == 1, "Exact plan lacks MoveIt SUCCESS")
        roots = [vertex for vertex in ids if indegree[vertex] == 0]
        require(len(roots) == 1 and len(edges) == len(rows) - 1, "Graph is not a single tree")
        root = roots[0]
        starts = [vertex for vertex in ids if int(vertices[vertex]["is_start"]) == 1]
        goals = {vertex for vertex in ids if int(vertices[vertex]["is_goal"]) == 1}
        require(starts == [root] and goals, "Tree start or goal flags are invalid")
        require(all(indegree[v] == 1 for v in ids if v != root), "Tree node has multiple parents")
        reached, pending = set(), [root]
        while pending:
            vertex = pending.pop()
            require(vertex not in reached, "Tree contains a cycle")
            reached.add(vertex)
            pending.extend(children[vertex])
        require(reached == set(ids), "Tree contains unreachable vertices")
        require("plan" in stages and stages["plan"], "Raw plan stage is absent or empty")
        configurations = np.array([values(vertices[v], joint_names) for v in ids])
        possible = {root: [root]}
        for index, row in enumerate(stages["plan"]):
            q = values(row, joint_names)
            matches = {ids[i] for i in np.flatnonzero(np.max(np.abs(configurations - q), axis=1) <= TOLERANCE)}
            require(matches, "Raw plan waypoint is absent from tree: " + str(index))
            if index == 0:
                require(root in matches, "Raw plan does not start at tree root")
                continue
            next_possible = {}
            for parent, path in possible.items():
                for target in children[parent] & matches:
                    next_possible[target] = path + [target]
            require(next_possible, "Raw plan segment is not an actual directed tree edge: " + str(index))
            possible = next_possible
        endings = goals & set(possible)
        require(endings, "Raw plan does not end at a goal vertex")
        raw_ids = possible[min(endings)]

    return {
        "passed": True,
        "exact_solution": exact,
        "vertex_count": len(rows),
        "edge_count": len(edges),
        "stage_waypoints": {name: len(table) for name, table in stages.items()},
        "raw_plan_vertex_ids": raw_ids,
        "fk_checked_rows": fk_rows,
        "max_tcp_error_m": max_error,
        "fk_tolerance_m": TOLERANCE,
        "urdf_root": root_link,
        "tcp_chain": chain_names,
        "cdr_payloads_parsed": False,
        "collision_checks": "Exporter counters only; this script independently checks graph and FK",
    }


def main():
    if len(sys.argv) != 2:
        print(json.dumps({"passed": False, "error": "Usage: validate_export.py RUN_DIRECTORY"}))
        return 2
    directory = Path(sys.argv[1]).expanduser().resolve()
    try:
        require(directory.is_dir(), "Run directory does not exist")
        result = validate(directory)
    except Exception as error:
        result = {"passed": False, "error": type(error).__name__ + ": " + str(error)}
    if directory.is_dir():
        (directory / "independent_validation.json").write_text(
            json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
        )
    print(json.dumps({key: value for key, value in result.items()
                      if key not in ("raw_plan_vertex_ids", "tcp_chain")}, ensure_ascii=False))
    return 0 if result["passed"] else 1


if __name__ == "__main__":
    sys.exit(main())
