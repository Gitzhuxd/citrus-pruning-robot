from setuptools import find_packages
from setuptools import setup

setup(
    name='aubo_ros2_driver',
    version='2.3.2',
    packages=find_packages(
        include=('aubo_ros2_driver', 'aubo_ros2_driver.*')),
)
