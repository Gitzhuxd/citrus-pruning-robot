from setuptools import find_packages
from setuptools import setup

setup(
    name='aubo_dashboard_msgs',
    version='2.3.2',
    packages=find_packages(
        include=('aubo_dashboard_msgs', 'aubo_dashboard_msgs.*')),
)
