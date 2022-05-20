from __future__ import print_function
from __future__ import with_statement

import os
import logging.config

logging.config.fileConfig(os.path.dirname(__file__)+"/logger.conf")
logger = logging.getLogger("pgclient")


class BaseSession(object):

    def __init__(self, transport, oprot_factory, container, timeout):
        self._transport = transport                     # TPegasusTransport
        self._oprot_factory = oprot_factory
        self._container = container
        self._seqid = 0
        self._requests = {}
        self._default_timeout = timeout

    def __del__(self):
        self.close()

    def operate(self, op, timeout=None):
        if not isinstance(timeout, int) or timeout <= 0:
            timeout = self._default_timeout
