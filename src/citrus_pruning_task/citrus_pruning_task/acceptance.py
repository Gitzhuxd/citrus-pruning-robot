"""Acceptance rules for one S01 run (pure Python, usable without ROS).

The rules mirror what the verified record
``s01_stump_demo_v1/verified_stump_replay/result.json`` demonstrates, plus the
requirement that the transit is planned again (not reused from a file).
"""
import json
import sys
from pathlib import Path

SHOOT = "citrus_S01"
STUMP = "citrus_S01_stump"


def _stage_ok(stages, name):
    stage = stages.get(name) or {}
    if not stage:
        return False, "missing"
    if "fraction" in stage and stage["fraction"] < 1.0 - 1e-6:
        return False, f"fraction {stage['fraction']:.4f}"
    if stage.get("position_error_mm", 0.0) > 2.0 or stage.get("orientation_error_deg", 0.0) > 1.0:
        return False, "endpoint FK error above 2 mm / 1 deg"
    return True, f"{stage.get('waypoints', '?')} waypoints, {stage.get('validity_samples', '?')} checked states"


def evaluate(report):
    """Return ``{"passed": bool, "checks": {name: {"ok": bool, "detail": str}}}``."""
    stages = report.get("stages") or {}
    checks = {}

    ok, detail = _stage_ok(stages, "transit")
    reused = (stages.get("transit") or {}).get("reused")
    checks["transit_replanned"] = {"ok": ok and reused is False,
                                   "detail": detail + ("" if reused is False else "; transit was reused or missing")}

    ok, detail = _stage_ok(stages, "insertion")
    checks["insertion"] = {"ok": ok, "detail": detail}

    closure = stages.get("closure") or {}
    contacts = {tuple(pair) for pair in closure.get("target_contacts", [])}
    want = {(SHOOT, "scissor_active_blade_link"), (SHOOT, "scissor_mimic_blade_link")}
    checks["closure"] = {"ok": closure.get("status") == "passed" and want <= contacts,
                         "detail": f"status={closure.get('status')}, samples={closure.get('samples')}"}

    before, after = report.get("world_before") or {}, report.get("world_after") or {}
    expected_after = {k: v for k, v in before.items() if k != SHOOT}
    if report.get("scene_stump_length_mm"):
        expected_after[STUMP] = 1
    checks["scene_update"] = {"ok": bool(before) and SHOOT in before and after == expected_after,
                              "detail": f"S01 removed={SHOOT not in after}, stump present={STUMP in after}"}

    ok, detail = _stage_ok(stages, "withdrawal")
    if "disengagement" in stages:
        d_ok, d_detail = _stage_ok(stages, "disengagement")
        ok, detail = ok and d_ok, f"disengagement: {d_detail}; withdrawal: {detail}"
    checks["retreat"] = {"ok": ok, "detail": detail}

    checks["no_error"] = {"ok": bool(report.get("success")) and "error" not in report,
                          "detail": report.get("error", "success")}
    return {"passed": all(item["ok"] for item in checks.values()), "checks": checks}


def format_checks(result):
    lines = []
    for name, item in result["checks"].items():
        lines.append(f"  [{'PASS' if item['ok'] else 'FAIL'}] {name:<18} {item['detail']}")
    lines.append(f"  => S01 acceptance {'PASSED' if result['passed'] else 'FAILED'}")
    return "\n".join(lines)


def main(argv=None):
    """``ros2 run citrus_pruning_task check_s01_result <result.json>``"""
    argv = sys.argv[1:] if argv is None else argv
    if len(argv) != 1:
        print("usage: check_s01_result <result.json>", file=sys.stderr)
        return 2
    report = json.loads(Path(argv[0]).read_text(encoding="utf-8"))
    result = evaluate(report)
    print(format_checks(result))
    return 0 if result["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
