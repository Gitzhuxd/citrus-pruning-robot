from setuptools import find_packages
from setuptools import setup

setup(
    name='aubo_rrt_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('aubo_rrt_interfaces', 'aubo_rrt_interfaces.*')),
)
