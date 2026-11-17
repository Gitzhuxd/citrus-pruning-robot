"""ROS-free tests: python -m unittest discover -s test -v (or pytest / colcon test)."""
import copy
import json
import unittest
from pathlib import Path

from citrus_pruning_task.acceptance import evaluate
from citrus_pruning_task.isolation import isolation_error

REFERENCE = Path(__file__).resolve().parents[3] / "experiments" / "s01_baseline" / "reference"


def load(name):
    return json.loads((REFERENCE / name).read_text(encoding="utf-8"))


class AcceptanceTests(unittest.TestCase):
    def test_verified_record_passes_everything_except_the_reused_transit(self):
        report = load("verified_stump_replay_result.json")
        result = evaluate(report)
        failed = {name for name, item in result["checks"].items() if not item["ok"]}
        self.assertEqual(failed, {"transit_replanned"})
        self.assertTrue(result["checks"]["scene_update"]["ok"])
        self.assertIn("disengagement", result["checks"]["retreat"]["detail"])

    def test_replanned_round_with_same_stages_passes(self):
        report = load("verified_stump_replay_result.json")
        report["stages"]["transit"]["reused"] = False
        self.assertTrue(evaluate(report)["passed"])

    def test_blocked_closure_or_missing_stump_fails(self):
        report = load("verified_stump_replay_result.json")
        report["stages"]["transit"]["reused"] = False
        blocked = copy.deepcopy(report)
        blocked["stages"]["closure"]["status"] = "blocked"
        self.assertFalse(evaluate(blocked)["checks"]["closure"]["ok"])
        no_stump = copy.deepcopy(report)
        no_stump["world_after"].pop("citrus_S01_stump")
        self.assertFalse(evaluate(no_stump)["checks"]["scene_update"]["ok"])

    def test_s07_acceptance_checks_the_reported_shoot_and_stump(self):
        report = load("verified_stump_replay_result.json")
        report["target"] = "S07"
        report["stages"]["transit"]["reused"] = False
        closure = report["stages"]["closure"]
        s01_contacts = closure["target_contacts"]
        closure["target_contacts"] = [("citrus_S07", blade) for _, blade in s01_contacts]
        s01_after = report["world_after"]
        report["world_after"] = report["world_before"].copy()
        report["world_after"].pop("citrus_S07")
        report["world_after"]["citrus_S07_stump"] = 1
        self.assertTrue(evaluate(report)["passed"])

        wrong_cut = dict(report, world_after=s01_after)
        self.assertFalse(evaluate(wrong_cut)["checks"]["scene_update"]["ok"])
        closure["target_contacts"] = s01_contacts
        self.assertFalse(evaluate(report)["checks"]["closure"]["ok"])

    def test_isolation_guard(self):
        self.assertIsNone(isolation_error({"ROS_DOMAIN_ID": "94", "ROS_LOCALHOST_ONLY": "1"}))
        self.assertTrue(isolation_error({"ROS_DOMAIN_ID": "0", "ROS_LOCALHOST_ONLY": "1"}))
        self.assertTrue(isolation_error({"ROS_DOMAIN_ID": "94"}))


if __name__ == "__main__":
    unittest.main()
