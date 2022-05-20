#!/usr/bin/env python3

# This script will be run by bazel when the build process starts to
# generate key-value information that represents the status of the
# workspace. The output should be like
#
# KEY1 VALUE1
# KEY2 VALUE2
#
# If the script exits with non-zero code, it's considered as a failure
# and the output will be discarded.

from __future__ import print_function
import os
import subprocess
import sys

CMD = ['git', 'describe', '--always', '--match', 'v[0-9].*', '--dirty']


def main():
    git_hash = get_git_hash(".")
    git_is_dirty = is_git_dirty(".")

    print("STABLE_GIT_COMMIT_HASH {}".format(git_hash))
    print("STABLE_GIT_DIRTY {}".format("1" if git_is_dirty else "0"))
    print("STABLE_BUILD_QUOTA_LABEL %s" % revision())
    # print("STABLE_BUILD_GERRIT_LABEL %s" % modules_revision(ROOT, ROOT))
    # print('STABLE_BUILD_%s_LABEL %s' % (os.path.basename(p).upper(), v if v else 'unknown'))

def _platform_string():
    """Detect current platform"""
    if platform.system() == 'Windows':
        return 'windows'
    elif platform.system()[:7] == 'MSYS_NT':
        return 'windows'
    elif platform.system() == 'Darwin':
        return 'mac'
    elif platform.system() == 'Linux':
        return 'linux'
    else:
        return 'posix'

def revision():
    try:
        return subprocess.check_output(CMD).strip().decode("utf-8")
    except OSError as err:
        print('could not invoke git: %s' % err, file=sys.stderr)
        sys.exit(1)
    except subprocess.CalledProcessError as err:
        print('error using git: %s' % err, file=sys.stderr)
        sys.exit(1)

def modules_revision(directory, parent):
    try:
        os.chdir(directory)
        return subprocess.check_output(CMD).strip().decode("utf-8")
    except OSError as err:
        print('could not invoke git: %s' % err, file=sys.stderr)
        sys.exit(1)
    except subprocess.CalledProcessError as err:
        # ignore "not a git repository error" to report unknown version
        return None
    finally:
        os.chdir(parent)

def get_git_hash(path):
    p = subprocess.Popen(["git", "rev-parse", "HEAD"], cwd=path, stdout=subprocess.PIPE)
    (out, err) = p.communicate()
    if p.returncode != 0:
        sys.exit(p.returncode)
    return out.encode("ascii").strip()

def is_git_dirty(path):
    p = subprocess.Popen(["git", "status", "-s"], cwd=path, stdout=subprocess.PIPE)
    (out, err) = p.communicate()
    if p.returncode != 0:
        sys.exit(p.returncode)
    return not not out.encode("ascii").strip()

if __name__ == "__main__":
    main()
