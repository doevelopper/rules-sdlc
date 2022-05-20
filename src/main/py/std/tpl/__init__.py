# coding: utf-8

__title__ = 'rsdlc'
__author__ = 'ahl'
__license__ = 'MIT'
__copyright__ = 'Copyright 2015-present Rapptz'
__version__ = '0.0.0-SNAPSHOOT'
# __path__ = __import__('pkgutil').extend_path(__path__, __name__)

from __future__ import unicode_literals
from exceptions.loggers import setup_logging_pre

import codecs
import io
import logging
import os
import random
import sys


# logger = logging.getLogger('Main')
logger = logging.getLogger(__name__)

def _real_main(argv=None):
  pass

def main(argv=None):
    try:
        setup_logging_pre()
        _real_main(argv)
    except LoadError:
        sys.exit(1)
    except FileError:
        sys.exit('ERROR: fixed output name but more than one file to download')
    except KeyboardInterrupt:
        sys.exit('\nERROR: Interrupted by user')
    except SystemExit as e:  # pragma: no cover
        return_code = e
    except KeyboardInterrupt:
        logger.info('SIGINT received, aborting ...')
        return_code = 0
    except FreqtradeException as e:
        logger.error(str(e))
        return_code = 2
    except Exception:
        logger.exception('Fatal exception!')
    finally:
        sys.exit(return_code)

__all__ = ['main', 'Load', 'gen_extractors', 'list_extractors']
