"""Keep simulation traffic away from the real AUBO controller.

The real driver uses the default network setup. Simulation runs must use a
private domain (91-99, the range used by all earlier experiments) and
ROS_LOCALHOST_ONLY=1, so nothing published here can reach another machine.
"""
import os

ALLOWED_DOMAINS = {str(n) for n in range(91, 100)}


def isolation_error(environ=None):
    environ = os.environ if environ is None else environ
    domain = environ.get("ROS_DOMAIN_ID")
    if domain not in ALLOWED_DOMAINS or environ.get("ROS_LOCALHOST_ONLY") != "1":
        return (f"Simulation must run isolated: export ROS_DOMAIN_ID=94 ROS_LOCALHOST_ONLY=1 "
                f"(allowed domains 91-99; got ROS_DOMAIN_ID={domain!r}, "
                f"ROS_LOCALHOST_ONLY={environ.get('ROS_LOCALHOST_ONLY')!r})")
    return None
