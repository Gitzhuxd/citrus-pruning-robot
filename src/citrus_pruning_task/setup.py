from glob import glob

from setuptools import find_packages, setup

PACKAGE = 'citrus_pruning_task'

setup(
    name=PACKAGE,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + PACKAGE]),
        ('share/' + PACKAGE, ['package.xml']),
        ('share/' + PACKAGE + '/launch', glob('launch/*.launch.py')),
        ('share/' + PACKAGE + '/config', glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Xuedong Zhu',
    maintainer_email='zhuxuedong98@gmail.com',
    description='S01 citrus pruning task node and unified simulation launch',
    license='MIT',
    tests_require=['pytest'],
    entry_points={'console_scripts': [
        's01_task = citrus_pruning_task.task_node:main',
        's01_replay = citrus_pruning_task.replay_tool:main',
        'check_s01_result = citrus_pruning_task.acceptance:main',
    ]},
)
