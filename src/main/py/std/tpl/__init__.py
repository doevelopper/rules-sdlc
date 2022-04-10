
#!/usr/bin/env python3
# coding: utf-8

from __future__ import unicode_literals

__license__ = 'Public Domain'

import codecs
import io
import os
import random
import sys

def _real_main(argv=None):
  pass

def main(argv=None):
    try:
        _real_main(argv)
    except LoadError:
        sys.exit(1)
    except FileError:
        sys.exit('ERROR: fixed output name but more than one file to download')
    except KeyboardInterrupt:
        sys.exit('\nERROR: Interrupted by user')

__all__ = ['main', 'Load', 'gen_extractors', 'list_extractors']
