import os
from glob import glob

from setuptools import find_packages, setup


package_name = 'aubo_i5_scissors_description'


setup(
    name=package_name,
    version='0.0.0',

    packages=find_packages(exclude=['test']),

    data_files=[
        (
            'share/ament_index/resource_index/packages',
            ['resource/' + package_name],
        ),

        (
            os.path.join('share', package_name),
            ['package.xml'],
        ),

        # 安装所有Python启动文件
        (
            os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py'),
        ),

        # 安装剪刀URDF和顶层Xacro
        (
            os.path.join('share', package_name, 'urdf'),
            glob('urdf/*.urdf') + glob('urdf/*.xacro'),
        ),

        # 安装剪刀显示模型
        (
            os.path.join(
                'share',
                package_name,
                'meshes',
                'scissors',
                'visual',
            ),
            glob('meshes/scissors/visual/*.stl'),
        ),

        # 安装转接板显示模型
                (
                    os.path.join(
                        'share',
                        package_name,
                        'meshes',
                        'transboard',
                        'visual',
                    ),
                    glob('meshes/transboard/visual/*.stl'),
                ),
                # 安装履带车显示模型
        (
            os.path.join(
                'share',
                package_name,
                'meshes',
                'car',
                'visual',
            ),
            glob('meshes/car/visual/*.dae'),
        ),

        # 安装履带车材质脚本
        (
            os.path.join(
                'share',
                package_name,
                'meshes',
                'car',
                'materials',
                'scripts',
            ),
            glob('meshes/car/materials/scripts/*'),
        ),

        # 安装履带车纹理图片
        (
            os.path.join(
                'share',
                package_name,
                'meshes',
                'car',
                'materials',
                'textures',
            ),
            glob('meshes/car/materials/textures/*'),
        ),
    ],

    install_requires=['setuptools'],
    zip_safe=True,

    maintainer='zhuxd',
    maintainer_email='zhuxd@todo.todo',

    description='AUBO i5 robot combined with an electric pruning scissor.',
    license='Apache-2.0',

    extras_require={
        'test': [
            'pytest',
        ],
    },

    entry_points={
        'console_scripts': [],
    },
)