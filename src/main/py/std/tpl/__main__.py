#!/usr/bin/env python3
from __future__ import unicode_literals

# Execute with
# $ python <project-folder>/__main__.py (2.6+)
# $ python -m project-name          (2.7+)

import project
import sys

if __package__ is None and not hasattr(sys, 'frozen'):
    # direct call of __main__.py
    import os.path
    path = os.path.realpath(os.path.abspath(__file__))
    sys.path.insert(0, os.path.dirname(os.path.dirname(path)))

if __name__ == '__main__':
    project.main()
