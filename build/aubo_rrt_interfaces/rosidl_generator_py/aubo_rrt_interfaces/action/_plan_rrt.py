# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aubo_rrt_interfaces:action/PlanRRT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PlanRRT_Goal(type):
    """Metaclass of message 'PlanRRT_Goal'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__goal

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


class PlanRRT_Goal(metaclass=Metaclass_PlanRRT_Goal):
    """Message class 'PlanRRT_Goal'."""

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
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_Result(type):
    """Metaclass of message 'PlanRRT_Result'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_Result(metaclass=Metaclass_PlanRRT_Result):
    """Message class 'PlanRRT_Result'."""

    __slots__ = [
        '_success',
        '_message',
        '_output_directory',
        '_iterations',
        '_tree_nodes',
        '_path_nodes',
        '_planning_seconds',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'output_directory': 'string',
        'iterations': 'uint32',
        'tree_nodes': 'uint32',
        'path_nodes': 'uint32',
        'planning_seconds': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.output_directory = kwargs.get('output_directory', str())
        self.iterations = kwargs.get('iterations', int())
        self.tree_nodes = kwargs.get('tree_nodes', int())
        self.path_nodes = kwargs.get('path_nodes', int())
        self.planning_seconds = kwargs.get('planning_seconds', float())

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
        if self.output_directory != other.output_directory:
            return False
        if self.iterations != other.iterations:
            return False
        if self.tree_nodes != other.tree_nodes:
            return False
        if self.path_nodes != other.path_nodes:
            return False
        if self.planning_seconds != other.planning_seconds:
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
    def output_directory(self):
        """Message field 'output_directory'."""
        return self._output_directory

    @output_directory.setter
    def output_directory(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'output_directory' field must be of type 'str'"
        self._output_directory = value

    @builtins.property
    def iterations(self):
        """Message field 'iterations'."""
        return self._iterations

    @iterations.setter
    def iterations(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'iterations' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'iterations' field must be an unsigned integer in [0, 4294967295]"
        self._iterations = value

    @builtins.property
    def tree_nodes(self):
        """Message field 'tree_nodes'."""
        return self._tree_nodes

    @tree_nodes.setter
    def tree_nodes(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tree_nodes' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tree_nodes' field must be an unsigned integer in [0, 4294967295]"
        self._tree_nodes = value

    @builtins.property
    def path_nodes(self):
        """Message field 'path_nodes'."""
        return self._path_nodes

    @path_nodes.setter
    def path_nodes(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'path_nodes' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'path_nodes' field must be an unsigned integer in [0, 4294967295]"
        self._path_nodes = value

    @builtins.property
    def planning_seconds(self):
        """Message field 'planning_seconds'."""
        return self._planning_seconds

    @planning_seconds.setter
    def planning_seconds(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'planning_seconds' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'planning_seconds' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._planning_seconds = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_Feedback(type):
    """Metaclass of message 'PlanRRT_Feedback'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_Feedback(metaclass=Metaclass_PlanRRT_Feedback):
    """Message class 'PlanRRT_Feedback'."""

    __slots__ = [
        '_phase',
        '_iterations',
        '_tree_nodes',
        '_elapsed_seconds',
    ]

    _fields_and_field_types = {
        'phase': 'string',
        'iterations': 'uint32',
        'tree_nodes': 'uint32',
        'elapsed_seconds': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.phase = kwargs.get('phase', str())
        self.iterations = kwargs.get('iterations', int())
        self.tree_nodes = kwargs.get('tree_nodes', int())
        self.elapsed_seconds = kwargs.get('elapsed_seconds', float())

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
        if self.phase != other.phase:
            return False
        if self.iterations != other.iterations:
            return False
        if self.tree_nodes != other.tree_nodes:
            return False
        if self.elapsed_seconds != other.elapsed_seconds:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def phase(self):
        """Message field 'phase'."""
        return self._phase

    @phase.setter
    def phase(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'phase' field must be of type 'str'"
        self._phase = value

    @builtins.property
    def iterations(self):
        """Message field 'iterations'."""
        return self._iterations

    @iterations.setter
    def iterations(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'iterations' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'iterations' field must be an unsigned integer in [0, 4294967295]"
        self._iterations = value

    @builtins.property
    def tree_nodes(self):
        """Message field 'tree_nodes'."""
        return self._tree_nodes

    @tree_nodes.setter
    def tree_nodes(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tree_nodes' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tree_nodes' field must be an unsigned integer in [0, 4294967295]"
        self._tree_nodes = value

    @builtins.property
    def elapsed_seconds(self):
        """Message field 'elapsed_seconds'."""
        return self._elapsed_seconds

    @elapsed_seconds.setter
    def elapsed_seconds(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elapsed_seconds' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'elapsed_seconds' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._elapsed_seconds = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_SendGoal_Request(type):
    """Metaclass of message 'PlanRRT_SendGoal_Request'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__send_goal__request

            from aubo_rrt_interfaces.action import PlanRRT
            if PlanRRT.Goal.__class__._TYPE_SUPPORT is None:
                PlanRRT.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_SendGoal_Request(metaclass=Metaclass_PlanRRT_SendGoal_Request):
    """Message class 'PlanRRT_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'aubo_rrt_interfaces/PlanRRT_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['aubo_rrt_interfaces', 'action'], 'PlanRRT_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Goal
        self.goal = kwargs.get('goal', PlanRRT_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Goal
            assert \
                isinstance(value, PlanRRT_Goal), \
                "The 'goal' field must be a sub message of type 'PlanRRT_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_SendGoal_Response(type):
    """Metaclass of message 'PlanRRT_SendGoal_Response'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_SendGoal_Response(metaclass=Metaclass_PlanRRT_SendGoal_Response):
    """Message class 'PlanRRT_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_PlanRRT_SendGoal(type):
    """Metaclass of service 'PlanRRT_SendGoal'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__plan_rrt__send_goal

            from aubo_rrt_interfaces.action import _plan_rrt
            if _plan_rrt.Metaclass_PlanRRT_SendGoal_Request._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_SendGoal_Request.__import_type_support__()
            if _plan_rrt.Metaclass_PlanRRT_SendGoal_Response._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_SendGoal_Response.__import_type_support__()


class PlanRRT_SendGoal(metaclass=Metaclass_PlanRRT_SendGoal):
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_SendGoal_Request as Request
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_GetResult_Request(type):
    """Metaclass of message 'PlanRRT_GetResult_Request'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_GetResult_Request(metaclass=Metaclass_PlanRRT_GetResult_Request):
    """Message class 'PlanRRT_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_GetResult_Response(type):
    """Metaclass of message 'PlanRRT_GetResult_Response'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__get_result__response

            from aubo_rrt_interfaces.action import PlanRRT
            if PlanRRT.Result.__class__._TYPE_SUPPORT is None:
                PlanRRT.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_GetResult_Response(metaclass=Metaclass_PlanRRT_GetResult_Response):
    """Message class 'PlanRRT_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'aubo_rrt_interfaces/PlanRRT_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['aubo_rrt_interfaces', 'action'], 'PlanRRT_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Result
        self.result = kwargs.get('result', PlanRRT_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Result
            assert \
                isinstance(value, PlanRRT_Result), \
                "The 'result' field must be a sub message of type 'PlanRRT_Result'"
        self._result = value


class Metaclass_PlanRRT_GetResult(type):
    """Metaclass of service 'PlanRRT_GetResult'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__plan_rrt__get_result

            from aubo_rrt_interfaces.action import _plan_rrt
            if _plan_rrt.Metaclass_PlanRRT_GetResult_Request._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_GetResult_Request.__import_type_support__()
            if _plan_rrt.Metaclass_PlanRRT_GetResult_Response._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_GetResult_Response.__import_type_support__()


class PlanRRT_GetResult(metaclass=Metaclass_PlanRRT_GetResult):
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_GetResult_Request as Request
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PlanRRT_FeedbackMessage(type):
    """Metaclass of message 'PlanRRT_FeedbackMessage'."""

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
                'aubo_rrt_interfaces.action.PlanRRT_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__plan_rrt__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__plan_rrt__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__plan_rrt__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__plan_rrt__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__plan_rrt__feedback_message

            from aubo_rrt_interfaces.action import PlanRRT
            if PlanRRT.Feedback.__class__._TYPE_SUPPORT is None:
                PlanRRT.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanRRT_FeedbackMessage(metaclass=Metaclass_PlanRRT_FeedbackMessage):
    """Message class 'PlanRRT_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'aubo_rrt_interfaces/PlanRRT_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['aubo_rrt_interfaces', 'action'], 'PlanRRT_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Feedback
        self.feedback = kwargs.get('feedback', PlanRRT_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Feedback
            assert \
                isinstance(value, PlanRRT_Feedback), \
                "The 'feedback' field must be a sub message of type 'PlanRRT_Feedback'"
        self._feedback = value


class Metaclass_PlanRRT(type):
    """Metaclass of action 'PlanRRT'."""

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
                'aubo_rrt_interfaces.action.PlanRRT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__plan_rrt

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from aubo_rrt_interfaces.action import _plan_rrt
            if _plan_rrt.Metaclass_PlanRRT_SendGoal._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_SendGoal.__import_type_support__()
            if _plan_rrt.Metaclass_PlanRRT_GetResult._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_GetResult.__import_type_support__()
            if _plan_rrt.Metaclass_PlanRRT_FeedbackMessage._TYPE_SUPPORT is None:
                _plan_rrt.Metaclass_PlanRRT_FeedbackMessage.__import_type_support__()


class PlanRRT(metaclass=Metaclass_PlanRRT):

    # The goal message defined in the action definition.
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Goal as Goal
    # The result message defined in the action definition.
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Result as Result
    # The feedback message defined in the action definition.
    from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from aubo_rrt_interfaces.action._plan_rrt import PlanRRT_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
