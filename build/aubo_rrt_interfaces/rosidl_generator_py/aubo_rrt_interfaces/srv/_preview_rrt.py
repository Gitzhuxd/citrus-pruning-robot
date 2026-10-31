# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PreviewRRT_Request(type):
    """Metaclass of message 'PreviewRRT_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('aubo_rrt_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'aubo_rrt_interfaces.srv.PreviewRRT_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__preview_rrt__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__preview_rrt__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__preview_rrt__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__preview_rrt__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__preview_rrt__request

            from aubo_rrt_interfaces.msg import Endpoint
            if Endpoint.__class__._TYPE_SUPPORT is None:
                Endpoint.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PreviewRRT_Request(metaclass=Metaclass_PreviewRRT_Request):
    """Message class 'PreviewRRT_Request'."""

    __slots__ = [
        '_start',
        '_goal',
        '_step_size',
        '_goal_bias',
        '_collision_step',
        '_max_iterations',
        '_planning_time',
        '_seed',
        '_replay_step',
    ]

    _fields_and_field_types = {
        'start': 'aubo_rrt_interfaces/Endpoint',
        'goal': 'aubo_rrt_interfaces/Endpoint',
        'step_size': 'double',
        'goal_bias': 'double',
        'collision_step': 'double',
        'max_iterations': 'int32',
        'planning_time': 'double',
        'seed': 'int32',
        'replay_step': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['aubo_rrt_interfaces', 'msg'], 'Endpoint'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['aubo_rrt_interfaces', 'msg'], 'Endpoint'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from aubo_rrt_interfaces.msg import Endpoint
        self.start = kwargs.get('start', Endpoint())
        from aubo_rrt_interfaces.msg import Endpoint
        self.goal = kwargs.get('goal', Endpoint())
        self.step_size = kwargs.get('step_size', float())
        self.goal_bias = kwargs.get('goal_bias', float())
        self.collision_step = kwargs.get('collision_step', float())
        self.max_iterations = kwargs.get('max_iterations', int())
        self.planning_time = kwargs.get('planning_time', float())
        self.seed = kwargs.get('seed', int())
        self.replay_step = kwargs.get('replay_step', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.start != other.start:
            return False
        if self.goal != other.goal:
            return False
        if self.step_size != other.step_size:
            return False
        if self.goal_bias != other.goal_bias:
            return False
        if self.collision_step != other.collision_step:
            return False
        if self.max_iterations != other.max_iterations:
            return False
        if self.planning_time != other.planning_time:
            return False
        if self.seed != other.seed:
            return False
        if self.replay_step != other.replay_step:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def start(self):
        """Message field 'start'."""
        return self._start

    @start.setter
    def start(self, value):
        if __debug__:
            from aubo_rrt_interfaces.msg import Endpoint
            assert \
                isinstance(value, Endpoint), \
                "The 'start' field must be a sub message of type 'Endpoint'"
        self._start = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from aubo_rrt_interfaces.msg import Endpoint
            assert \
                isinstance(value, Endpoint), \
                "The 'goal' field must be a sub message of type 'Endpoint'"
        self._goal = value

    @builtins.property
    def step_size(self):
        """Message field 'step_size'."""
        return self._step_size

    @step_size.setter
    def step_size(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'step_size' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'step_size' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._step_size = value

    @builtins.property
    def goal_bias(self):
        """Message field 'goal_bias'."""
        return self._goal_bias

    @goal_bias.setter
    def goal_bias(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_bias' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'goal_bias' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._goal_bias = value

    @builtins.property
    def collision_step(self):
        """Message field 'collision_step'."""
        return self._collision_step

    @collision_step.setter
    def collision_step(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'collision_step' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'collision_step' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._collision_step = value

    @builtins.property
    def max_iterations(self):
        """Message field 'max_iterations'."""
        return self._max_iterations

    @max_iterations.setter
    def max_iterations(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_iterations' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_iterations' field must be an integer in [-2147483648, 2147483647]"
        self._max_iterations = value

    @builtins.property
    def planning_time(self):
        """Message field 'planning_time'."""
        return self._planning_time

    @planning_time.setter
    def planning_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'planning_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'planning_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._planning_time = value

    @builtins.property
    def seed(self):
        """Message field 'seed'."""
        return self._seed

    @seed.setter
    def seed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'seed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'seed' field must be an integer in [-2147483648, 2147483647]"
        self._seed = value

    @builtins.property
    def replay_step(self):
        """Message field 'replay_step'."""
        return self._replay_step

    @replay_step.setter
    def replay_step(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'replay_step' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'replay_step' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._replay_step = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PreviewRRT_Response(type):
    """Metaclass of message 'PreviewRRT_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('aubo_rrt_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'aubo_rrt_interfaces.srv.PreviewRRT_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__preview_rrt__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__preview_rrt__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__preview_rrt__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__preview_rrt__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__preview_rrt__response

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

            from moveit_msgs.msg import RobotState
            if RobotState.__class__._TYPE_SUPPORT is None:
                RobotState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PreviewRRT_Response(metaclass=Metaclass_PreviewRRT_Response):
    """Message class 'PreviewRRT_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_start_state',
        '_goal_state',
        '_start_pose',
        '_goal_pose',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'start_state': 'moveit_msgs/RobotState',
        'goal_state': 'moveit_msgs/RobotState',
        'start_pose': 'geometry_msgs/PoseStamped',
        'goal_pose': 'geometry_msgs/PoseStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'RobotState'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'RobotState'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        from moveit_msgs.msg import RobotState
        self.start_state = kwargs.get('start_state', RobotState())
        from moveit_msgs.msg import RobotState
        self.goal_state = kwargs.get('goal_state', RobotState())
        from geometry_msgs.msg import PoseStamped
        self.start_pose = kwargs.get('start_pose', PoseStamped())
        from geometry_msgs.msg import PoseStamped
        self.goal_pose = kwargs.get('goal_pose', PoseStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.start_state != other.start_state:
            return False
        if self.goal_state != other.goal_state:
            return False
        if self.start_pose != other.start_pose:
            return False
        if self.goal_pose != other.goal_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def start_state(self):
        """Message field 'start_state'."""
        return self._start_state

    @start_state.setter
    def start_state(self, value):
        if __debug__:
            from moveit_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'start_state' field must be a sub message of type 'RobotState'"
        self._start_state = value

    @builtins.property
    def goal_state(self):
        """Message field 'goal_state'."""
        return self._goal_state

    @goal_state.setter
    def goal_state(self, value):
        if __debug__:
            from moveit_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'goal_state' field must be a sub message of type 'RobotState'"
        self._goal_state = value

    @builtins.property
    def start_pose(self):
        """Message field 'start_pose'."""
        return self._start_pose

    @start_pose.setter
    def start_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'start_pose' field must be a sub message of type 'PoseStamped'"
        self._start_pose = value

    @builtins.property
    def goal_pose(self):
        """Message field 'goal_pose'."""
        return self._goal_pose

    @goal_pose.setter
    def goal_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'goal_pose' field must be a sub message of type 'PoseStamped'"
        self._goal_pose = value


class Metaclass_PreviewRRT(type):
    """Metaclass of service 'PreviewRRT'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('aubo_rrt_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'aubo_rrt_interfaces.srv.PreviewRRT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__preview_rrt

            from aubo_rrt_interfaces.srv import _preview_rrt
            if _preview_rrt.Metaclass_PreviewRRT_Request._TYPE_SUPPORT is None:
                _preview_rrt.Metaclass_PreviewRRT_Request.__import_type_support__()
            if _preview_rrt.Metaclass_PreviewRRT_Response._TYPE_SUPPORT is None:
                _preview_rrt.Metaclass_PreviewRRT_Response.__import_type_support__()


class PreviewRRT(metaclass=Metaclass_PreviewRRT):
    from aubo_rrt_interfaces.srv._preview_rrt import PreviewRRT_Request as Request
    from aubo_rrt_interfaces.srv._preview_rrt import PreviewRRT_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
