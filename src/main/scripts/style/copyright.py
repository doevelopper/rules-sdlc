#!/usr/bin/env python
"""
    Checks and/or updates copyright headers in source files.
    It is used internally by several bash scripts to do copyright-relates tasks,
    but can also be invoked directly for some rare use cases.

    See docs/dev-manual/uncrustify.md for more details.
"""

import subprocess
import multiprocessing
import json
import datetime
import os.path
import re
import sys
import fileinput

from optparse import OptionParser

class CopyrightUtils():
    """scan a directory for cpp, hpp, idl extension files."""
    def findFiles(directory, files=[]):
        for filename in os.listdir(directory):
            path = os.path.join(directory, filename)
            if os.path.isfile(path) and (path.endswith(".cpp") or
                                         path.endswith(".hpp") or
                                         path.endswith(".idl")):
                if filename != "__init__.py" and filename != "version.py":
                    files.append(path)
            elif os.path.isdir(path):
                findFiles(path, files)
        return files

class CopyrightState(object):

    """Information about an existing (or non-existing) copyright header."""

    def __init__(self, has_copyright, is_correct, is_newstyle, years, other_copyrights):
        self.has_copyright = has_copyright
        self.is_correct = is_correct
        self.is_newstyle = is_newstyle
        self.years = years
        self.other_copyrights = other_copyrights

def usage(arg):
    sys.stderr.write('[Usage]: python %s <filename | path>\n' % arg)
    sys.exit(-1)

def main():
    """Do processing as a stand-alone script."""
#    if len(sys.argv) == 1:
#        usage(sys.argv[0])
    if len(sys.argv) < 2:
        usage(sys.argv[0])
    else:
        usage(sys.argv[0])

if __name__ == "__main__":
    main()
