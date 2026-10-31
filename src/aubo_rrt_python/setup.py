from setuptools import find_packages, setup

package_name = 'aubo_rrt_python'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zhuxd',
    maintainer_email='zhuxd@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'rrt_demo = aubo_rrt_python.rrt_demo:main',
            'rrt_server = aubo_rrt_python.rrt_server:main',
        ],
    },
)
