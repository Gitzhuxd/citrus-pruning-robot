# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetRRTInfo_Request(type):
    """Metaclass of message 'GetRRTInfo_Request'."""

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
                'aubo_rrt_interfaces.srv.GetRRTInfo_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_rrt_info__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_rrt_info__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_rrt_info__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_rrt_info__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_rrt_info__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetRRTInfo_Request(metaclass=Metaclass_GetRRTInfo_Request):
    """Message class 'GetRRTInfo_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetRRTInfo_Response(type):
    """Metaclass of message 'GetRRTInfo_Response'."""

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
                'aubo_rrt_interfaces.srv.GetRRTInfo_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_rrt_info__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_rrt_info__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_rrt_info__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_rrt_info__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_rrt_info__response

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


class GetRRTInfo_Response(metaclass=Metaclass_GetRRTInfo_Response):
    """Message class 'GetRRTInfo_Response'."""

    __slots__ = [
        '_ready',
        '_message',
        '_named_states',
        '_current_pose',
        '_current_state',
    ]

    _fields_and_field_types = {
        'ready': 'boolean',
        'message': 'string',
        'named_states': 'sequence<string>',
        'current_pose': 'geometry_msgs/PoseStamped',
        'current_state': 'moveit_msgs/RobotState',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['moveit_msgs', 'msg'], 'RobotState'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ready = kwargs.get('ready', bool())
        self.message = kwargs.get('message', str())
        self.named_states = kwargs.get('named_states', [])
        from geometry_msgs.msg import PoseStamped
        self.current_pose = kwargs.get('current_pose', PoseStamped())
        from moveit_msgs.msg import RobotState
        self.current_state = kwargs.get('current_state', RobotState())

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
        if self.ready != other.ready:
            return False
        if self.message != other.message:
            return False
        if self.named_states != other.named_states:
            return False
        if self.current_pose != other.current_pose:
            return False
        if self.current_state != other.current_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ready(self):
        """Message field 'ready'."""
        return self._ready

    @ready.setter
    def ready(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ready' field must be of type 'bool'"
        self._ready = value

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
    def named_states(self):
        """Message field 'named_states'."""
        return self._named_states

    @named_states.setter
    def named_states(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'named_states' field must be a set or sequence and each value of type 'str'"
        self._named_states = value

    @builtins.property
    def current_pose(self):
        """Message field 'current_pose'."""
        return self._current_pose

    @current_pose.setter
    def current_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'current_pose' field must be a sub message of type 'PoseStamped'"
        self._current_pose = value

    @builtins.property
    def current_state(self):
        """Message field 'current_state'."""
        return self._current_state

    @current_state.setter
    def current_state(self, value):
        if __debug__:
            from moveit_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'current_state' field must be a sub message of type 'RobotState'"
        self._current_state = value


class Metaclass_GetRRTInfo(type):
    """Metaclass of service 'GetRRTInfo'."""

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
                'aubo_rrt_interfaces.srv.GetRRTInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_rrt_info

            from aubo_rrt_interfaces.srv import _get_rrt_info
            if _get_rrt_info.Metaclass_GetRRTInfo_Request._TYPE_SUPPORT is None:
                _get_rrt_info.Metaclass_GetRRTInfo_Request.__import_type_support__()
            if _get_rrt_info.Metaclass_GetRRTInfo_Response._TYPE_SUPPORT is None:
                _get_rrt_info.Metaclass_GetRRTInfo_Response.__import_type_support__()


class GetRRTInfo(metaclass=Metaclass_GetRRTInfo):
    from aubo_rrt_interfaces.srv._get_rrt_info import GetRRTInfo_Request as Request
    from aubo_rrt_interfaces.srv._get_rrt_info import GetRRTInfo_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
