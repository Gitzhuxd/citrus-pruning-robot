from glob import glob
from pathlib import Path
from setuptools import find_packages, setup

PACKAGE = 'citrus_pruning_sim'
data_files = [
    ('share/ament_index/resource_index/packages', ['resource/' + PACKAGE]),
    ('share/' + PACKAGE, ['package.xml']),
    ('share/' + PACKAGE + '/launch', glob('launch/*.launch.py')),
    ('share/' + PACKAGE + '/config', glob('config/*')),
]
for folder in ('data', 'meshes', 'urdf'):
    for path in sorted(Path(folder).rglob('*')):
        if path.is_file():
            data_files.append(('share/' + PACKAGE + '/' + str(path.parent), [str(path)]))

setup(
    name=PACKAGE,
    version='0.1.0',
    packages=find_packages(exclude=['tests']),
    data_files=data_files,
    install_requires=['setuptools'],
    zip_safe=False,
    maintainer='Citrus model workspace',
    maintainer_email='maintainer@example.com',
    description='RViz citrus pruning and optional MoveIt collision synchronization',
    license='MIT',
    entry_points={'console_scripts': ['pruning_scene = citrus_pruning_sim.scene_node:main']},
)
