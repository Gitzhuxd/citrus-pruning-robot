"""Run without ROS: python -m unittest discover -s tests -v."""
import copy
import math
from pathlib import Path
import unittest

from citrus_pruning_sim.model import PruningState, branch_triangles, cylinder, load_model, quaternion_z_to


def example():
    segment = dict(id='trunk', group='static', start=[0, 0, 0], end=[0, 0, 1],
                   radius_start=.03, radius_end=.01, color=[.2, .4, .1, 1])
    shoot = dict(id='tip', group='S01', start=[0, 0, 1], end=[.2, 0, 1.4],
                 radius_start=.004, radius_end=.001, color=[.4, .7, .2, 1])
    return {'units': 'm', 'frame_id': 'tree_base', 'segments': [segment, shoot], 'leaves': [],
            'targets': [{'id': 'S01', 'position': [0, 0, 1], 'precut_position': [0, -.1, 1],
                         'axis': [0, 0, 1], 'approach': [0, 1, 0], 'radius_m': .004}]}


class ModelTests(unittest.TestCase):
    def test_cut_is_planned_without_mutating_then_reset_restores(self):
        state = PruningState(example())
        original = state.collision_snapshot()
        desired = state.plan('S01')
        self.assertEqual(state.cut_ids, frozenset())
        self.assertEqual(state.collision_snapshot(desired=desired)[1]['operation'], 'REMOVE')
        state.commit(desired)
        self.assertEqual(state.revision, 1)
        self.assertFalse(state.visible('S01'))
        self.assertTrue(state.visible('static'))
        state.commit(state.plan('S01'))
        self.assertEqual(state.revision, 1)
        state.commit(state.plan('reset'))
        self.assertEqual(state.collision_snapshot(), original)

    def test_collision_snapshot_scopes_ids_and_preserves_static(self):
        state = PruningState(example())
        state.commit(state.plan('cut_all'))
        snapshots = state.collision_snapshot()
        self.assertEqual([s['id'] for s in snapshots], ['citrus_static', 'citrus_S01'])
        self.assertEqual([s['operation'] for s in snapshots], ['ADD', 'REMOVE'])
        self.assertEqual(snapshots[1]['cylinders'], [])

    def test_partial_s01_cut_retains_the_stump_without_padding_the_cut_face(self):
        model = example()
        axis = (1 / math.sqrt(5), 0.0, 2 / math.sqrt(5))
        model['targets'][0]['axis'] = axis
        state = PruningState(model, s01_cut_offset_m=.006)
        before = state.collision_snapshot()
        self.assertEqual(before[-1]['id'], 'citrus_S01_stump')
        self.assertEqual(before[-1]['operation'], 'REMOVE')
        self.assertFalse(state.visible('S01_stump'))
        state.commit(state.plan('S01'))
        after = state.collision_snapshot()
        self.assertEqual(after[0], before[0])
        self.assertEqual(after[1]['operation'], 'REMOVE')
        self.assertEqual(after[-1]['operation'], 'ADD')
        self.assertTrue(state.visible('S01_stump'))
        self.assertAlmostEqual(math.dist(state.s01_stump['start'], state.s01_stump['end']), .006)
        self.assertEqual(state.targets[0]['position'], state.s01_stump['end'])
        stump = after[-1]['cylinders'][0]
        self.assertAlmostEqual(stump['height'], .009)
        self.assertAlmostEqual(stump['radius'], .007)
        # The distal collision cap is at the visible cut plane.
        for center, cap, direction in zip(stump['center'], state.s01_stump['end'], axis):
            self.assertAlmostEqual(center + stump['height'] * direction / 2.0, cap)
        state.commit(state.plan('reset'))
        self.assertEqual(state.collision_snapshot(), before)
        self.assertFalse(state.visible('S01_stump'))

    def test_cylinder_margin_covers_both_ends_and_maximum_radius(self):
        result = cylinder(example()['segments'][0], .003)
        self.assertAlmostEqual(result['height'], 1.006)
        self.assertAlmostEqual(result['radius'], .033)
        self.assertEqual(result['center'], (0.0, 0.0, .5))

    def test_project_s07_stump_cap_matches_the_shifted_target(self):
        model_path = Path(__file__).parents[1] / 'data' / 'tree_model.json'
        state = PruningState(load_model(model_path), s01_cut_offset_m=.006, partial_cut_target='S07')
        before = {item['id']: item for item in state.collision_snapshot()}
        self.assertEqual(before['citrus_S07_stump']['operation'], 'REMOVE')
        self.assertEqual(state.s01_cut_offset_m, 0.0)
        state.commit(state.plan('S07'))
        after = {item['id']: item for item in state.collision_snapshot()}
        self.assertEqual(after['citrus_S07']['operation'], 'REMOVE')
        self.assertEqual(after['citrus_S07_stump']['operation'], 'ADD')
        self.assertEqual(after['citrus_S01'], before['citrus_S01'])
        self.assertFalse(state.visible('S01_stump'))
        self.assertAlmostEqual(math.dist(state.stump['start'], state.stump['end']), .006)
        target = next(t for t in state.targets if t['id'] == 'S07')
        stump = after['citrus_S07_stump']['cylinders'][0]
        for center, cap, direction in zip(stump['center'], target['position'], target['axis']):
            self.assertAlmostEqual(center + stump['height'] * direction / 2.0, cap)

    def test_quaternion_rotates_z_onto_oblique_and_antiparallel_axes(self):
        for axis in ([0, 0, -1], [1, 2, 3], [0, 0, 1], [0, 1, 0]):
            x, y, z, w = quaternion_z_to(axis)
            rotated = (2*(x*z+w*y), 2*(y*z-w*x), 1-2*(x*x+y*y))
            length = math.sqrt(sum(v*v for v in axis))
            for got, want in zip(rotated, axis):
                self.assertAlmostEqual(got, want/length, places=8)

    def test_branch_mesh_is_closed_and_tapered(self):
        points = branch_triangles(example()['segments'][0], sides=8)
        self.assertEqual(len(points), 8*12)
        edges = {}
        for i in range(0, len(points), 3):
            tri = points[i:i+3]
            for j in range(3):
                key = tuple(sorted((tri[j], tri[(j+1) % 3])))
                edges[key] = edges.get(key, 0) + 1
        self.assertTrue(all(count == 2 for count in edges.values()))

    def test_invalid_dimensions_and_ownership_rejected(self):
        for mutate in (
            lambda m: m['segments'][0].update(radius_start=-.1),
            lambda m: m['segments'][0].update(end=[float('nan'), 0, 1]),
            lambda m: m['segments'][1].update(group='missing'),
            lambda m: m['segments'][0].update(end=[0, 0, 0]),
        ):
            model = copy.deepcopy(example())
            mutate(model)
            with self.assertRaises(ValueError):
                PruningState(model)


if __name__ == '__main__':
    unittest.main()
