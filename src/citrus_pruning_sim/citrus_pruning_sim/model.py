"""Validated geometry and reversible pruning state, independent of ROS."""
import json
import math
from pathlib import Path


S01_STUMP = 'S01_stump'


def vector(values, size=3):
    if not isinstance(values, (list, tuple)) or len(values) != size:
        raise ValueError('Invalid vector size')
    if any(isinstance(x, bool) or not isinstance(x, (int, float)) for x in values):
        raise ValueError('Vector components must be numbers')
    out = tuple(float(x) for x in values)
    if not all(math.isfinite(x) for x in out):
        raise ValueError('Non-finite geometry')
    return out


def subtract(a, b):
    return tuple(x - y for x, y in zip(a, b))


def unit(axis):
    axis = vector(axis)
    length = math.sqrt(sum(x * x for x in axis))
    if length < 1e-10:
        raise ValueError('Zero-length direction')
    return tuple(x / length for x in axis)


def cross(a, b):
    return (a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0])


def quaternion_z_to(axis):
    """Unit xyzw quaternion rotating local +Z onto axis, including -Z."""
    x, y, z = unit(axis)
    if z < -1.0 + 1e-10:
        return (1.0, 0.0, 0.0, 0.0)
    q = (-y, x, 0.0, 1.0 + z)
    length = math.sqrt(sum(v * v for v in q))
    return tuple(v / length for v in q)


def cylinder(segment, margin=0.0, *, pad_end=True):
    if not math.isfinite(margin) or margin < 0:
        raise ValueError('Collision margin must be finite and nonnegative')
    start, end = vector(segment['start']), vector(segment['end'])
    delta = subtract(end, start)
    length = math.sqrt(sum(x*x for x in delta))
    center = tuple((a+b)/2.0 for a, b in zip(start, end))
    end_margin = margin if pad_end else 0.0
    if end_margin != margin:
        center = tuple(c - margin * d / 2.0 for c, d in zip(center, unit(delta)))
    return {
        'height': length + margin + end_margin,
        'radius': max(segment['radius_start'], segment['radius_end']) + margin,
        'center': center,
        'quaternion_xyzw': quaternion_z_to(delta),
    }


def branch_triangles(segment, sides=16):
    """Capped tapered branch, returned as a flat TRIANGLE_LIST vertex list."""
    a, b = vector(segment['start']), vector(segment['end'])
    axis = unit(subtract(b, a))
    u = unit(cross(axis, (0, 0, 1) if abs(axis[2]) < .9 else (0, 1, 0)))
    v = cross(axis, u)
    rings = []
    for center, radius in ((a, segment['radius_start']), (b, segment['radius_end'])):
        rings.append([tuple(center[k] + radius*(math.cos(i*math.tau/sides)*u[k]
                     + math.sin(i*math.tau/sides)*v[k]) for k in range(3))
                     for i in range(sides)])
    points = []
    for i in range(sides):
        j = (i+1) % sides
        points.extend((rings[0][i], rings[0][j], rings[1][j],
                       rings[0][i], rings[1][j], rings[1][i],
                       a, rings[0][j], rings[0][i], b, rings[1][i], rings[1][j]))
    return points


def validate_model(model):
    if model.get('units') != 'm' or model.get('frame_id') != 'tree_base':
        raise ValueError('Expected meters in tree_base')
    targets = model['targets']
    ids = [t['id'] for t in targets]
    if not ids or len(ids) != len(set(ids)) or 'static' in ids:
        raise ValueError('Cut target IDs must be nonempty and unique')
    groups = {'static', *ids}
    for target in targets:
        if (not target['id'].isascii() or not target['id'].isalnum()
                or not target['id'][0].isalpha()
                or target['id'] in ('static', 'reset', 'cut_all', 'resync_moveit')):
            raise ValueError('Target IDs must be distinct ASCII ROS name components starting with a letter')
        vector(target['position'])
        vector(target['precut_position'])
        unit(target['axis'])
        unit(target['approach'])
        if not math.isfinite(target['radius_m']) or target['radius_m'] <= 0:
            raise ValueError('Invalid cut radius')
    segment_ids = set()
    present_groups = set()
    for seg in model['segments']:
        if seg['id'] in segment_ids or seg['group'] not in groups:
            raise ValueError('Duplicate segment ID or unknown group')
        segment_ids.add(seg['id'])
        present_groups.add(seg['group'])
        unit(subtract(vector(seg['end']), vector(seg['start'])))
        radii = vector([seg['radius_start'], seg['radius_end']], 2)
        if min(radii) <= 0:
            raise ValueError('Branch radii must be positive')
        if not all(0 <= c <= 1 for c in vector(seg['color'], 4)):
            raise ValueError('Invalid segment color')
    if present_groups != groups:
        raise ValueError('Each cut target and static group needs branch geometry')
    leaf_ids = set()
    for leaf in model['leaves']:
        if leaf['id'] in leaf_ids or leaf['group'] not in groups:
            raise ValueError('Duplicate leaf ID or unknown group')
        leaf_ids.add(leaf['id'])
        for point in leaf['vertices']:
            vector(point)
        for face in leaf['triangles']:
            if len(face) != 3 or any(type(i) is not int or not 0 <= i < len(leaf['vertices']) for i in face):
                raise ValueError('Invalid leaf triangle indices')
        if not all(0 <= c <= 1 for c in vector(leaf['color'], 4)):
            raise ValueError('Invalid leaf color')
    return model


def load_model(path):
    return validate_model(json.loads(Path(path).read_text(encoding='utf-8')))


class PruningState:
    """Plan first, commit only after the caller confirms collision synchronization."""
    def __init__(self, model, s01_cut_offset_m=0.0, *, partial_cut_target='S01'):
        self.model = validate_model(model)
        self.target_ids = tuple(t['id'] for t in model['targets'])
        self.targets = tuple(model['targets'])
        self.partial_cut_target = partial_cut_target
        self.stump_group = partial_cut_target + '_stump'
        self.stump = None
        if not math.isfinite(s01_cut_offset_m) or s01_cut_offset_m < 0.0:
            raise ValueError('s01_cut_offset_m must be finite and nonnegative')
        self.cut_offset_m = s01_cut_offset_m
        if self.cut_offset_m:
            self._configure_stump()
        self.s01_cut_offset_m = self.cut_offset_m if partial_cut_target == 'S01' else 0.0
        self.s01_stump = self.stump if partial_cut_target == 'S01' else None
        self.cut_ids = frozenset()
        self.revision = 0

    def _configure_stump(self):
        target_id = self.partial_cut_target
        offset = self.cut_offset_m
        segments = [segment for segment in self.model['segments'] if segment['group'] == target_id]
        if len(segments) != 1:
            raise ValueError(f'A partial {target_id} cut requires exactly one shoot segment')
        shoot = segments[0]
        start, end = vector(shoot['start']), vector(shoot['end'])
        length = math.dist(start, end)
        axis = unit(subtract(end, start))
        target = next(t for t in self.targets if t['id'] == target_id)
        if math.dist(start, target['position']) > 1e-6 or math.dist(axis, unit(target['axis'])) > 1e-6:
            raise ValueError(f'The {target_id} cut target must start at the shoot base and point along the shoot')
        if not 1e-10 <= offset < length:
            raise ValueError(f's01_cut_offset_m must lie strictly inside the {target_id} shoot')
        shift = tuple(offset * d for d in axis)
        cut = tuple(a + b for a, b in zip(start, shift))
        radius = shoot['radius_start'] + (shoot['radius_end'] - shoot['radius_start']) * offset / length
        self.stump = dict(shoot, id=self.stump_group, group=self.stump_group, end=cut, radius_end=radius)
        precut = tuple(a + b for a, b in zip(target['precut_position'], shift))
        self.targets = tuple(dict(t, position=cut, precut_position=precut) if t['id'] == target_id else t
                             for t in self.targets)

    def stump_cylinder(self, margin):
        # Pad into the attached base and radially, but do not fill the removed side of the cut.
        return cylinder(self.stump, margin, pad_end=False)

    def plan(self, command):
        if command == 'reset':
            return frozenset()
        if command == 'cut_all':
            return frozenset(self.target_ids)
        if command not in self.target_ids:
            raise ValueError('Unknown target: ' + command)
        return self.cut_ids | {command}

    def commit(self, desired):
        desired = frozenset(desired)
        if not desired.issubset(self.target_ids):
            raise ValueError('Unknown cut target')
        if desired != self.cut_ids:
            self.cut_ids = desired
            self.revision += 1

    def visible(self, group, desired=None):
        desired = self.cut_ids if desired is None else desired
        if group == self.stump_group:
            return self.stump is not None and self.partial_cut_target in desired
        if group == S01_STUMP:
            return False
        return group == 'static' or group not in desired

    def collision_snapshot(self, margin=0.003, desired=None):
        """All owned groups, including explicit REMOVE for every cut group."""
        desired = self.cut_ids if desired is None else desired
        result = []
        for group in ('static', *self.target_ids):
            geometry = [cylinder(s, margin) for s in self.model['segments'] if s['group'] == group]
            result.append({'id': 'citrus_' + group, 'group': group,
                           'operation': 'ADD' if self.visible(group, desired) else 'REMOVE',
                           'cylinders': geometry if self.visible(group, desired) else []})
        if self.stump is not None:
            visible = self.visible(self.stump_group, desired)
            result.append({'id': 'citrus_' + self.stump_group, 'group': self.stump_group,
                           'operation': 'ADD' if visible else 'REMOVE',
                           'cylinders': [self.stump_cylinder(margin)] if visible else []})
        return result
