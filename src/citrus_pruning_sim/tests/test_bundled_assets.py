"""Integration checks against the distributed scan-guided tree geometry."""
from collections import Counter
import math
from pathlib import Path
import unittest

from citrus_pruning_sim.model import PruningState, load_model


class BundledAssetsTests(unittest.TestCase):
    def test_cut_junctions_eight_leaves_and_collision_group_round_trip(self):
        model = load_model(Path(__file__).parents[1] / 'data' / 'tree_model.json')
        state = PruningState(model)
        self.assertEqual(len(state.target_ids), 8)
        counts = Counter(leaf['group'] for leaf in model['leaves'])
        baseline = state.collision_snapshot()
        distance = lambda a, b: math.sqrt(sum((x-y)**2 for x, y in zip(a, b)))
        for target in model['targets']:
            ident = target['id']
            self.assertEqual(counts[ident], 8)
            shoots = [s for s in model['segments'] if s['group'] == ident]
            self.assertEqual(len(shoots), 1)
            self.assertLess(distance(shoots[0]['start'], target['position']), 1e-8)
            old_ends = [s['end'] for s in model['segments'] if s['group'] == 'static']
            self.assertLess(min(distance(p, target['position']) for p in old_ends), 1e-8)
            state.commit(state.plan(ident))
            remaining = Counter(leaf['group'] for leaf in model['leaves'] if state.visible(leaf['group']))
            self.assertEqual(remaining['static'], counts['static'])
            self.assertEqual(remaining[ident], 0)
            for snapshot in state.collision_snapshot():
                if snapshot['group'] == ident:
                    self.assertEqual(snapshot['operation'], 'REMOVE')
                else:
                    self.assertEqual(snapshot['operation'], 'ADD')
            state.commit(state.plan('reset'))
            self.assertEqual(state.collision_snapshot(), baseline)
        state.commit(state.plan('cut_all'))
        self.assertEqual([s['group'] for s in state.collision_snapshot() if s['operation'] == 'ADD'], ['static'])
        state.commit(state.plan('reset'))
        self.assertEqual(state.collision_snapshot(), baseline)


if __name__ == '__main__':
    unittest.main()
