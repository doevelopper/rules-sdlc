
#!/usr/bin/env bash

# Copyright 2021- AHL.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

# This file was inspired by:
# https://github.com/envoyproxy/envoy/blob/master/bazel/get_workspace_status

# This script will be run bazel when building process starts to
# generate key-value information that represents the status of the
# workspace. The output should be like
#
# KEY1 VALUE1
# KEY2 VALUE2
#
# If the script exits with non-zero code, it's considered as a failure
# and the output will be discarded.

# If this VERSION file exists then it must have been placed here by a
# distribution doing a non-git, source build.
# Distributions would be expected to echo the commit/tag as BUILD_SCM_REVISION.

# @see http://manpages.ubuntu.com/manpages/jammy/en/man1/set.1posix.html
set -o errexit
set -o nounset
set -o pipefail

# Handle target-triple.
if [ -z "${1+x}" ]
then
    TARGET_TRIPLE=$(CC -dumpmachine)
else
    TARGET_TRIPLE="$1"
    shift 1
fi

# Handle build-channel.
if [ -z "${1+x}" ]
then
    BUILD_CHANNEL="unknown"
else
    BUILD_CHANNEL="$1"
    shift 1
fi

# Handle build-tag.
if [ -z "${1+x}" ]
then
    BUILD_TAG=$(git describe --tags --dirty --match=v[0-9]* 2> /dev/null || git rev-parse --short HEAD;)
else
    BUILD_TAG="$1"
    shift 1
fi

# Handle build-type.
if [ -z "${1+x}" ]
then
    BUILD_TYPE="SNAPSHOOT"
else
    BUILD_TYPE="$1"
    shift 1
fi

if [ "$BUILD_TYPE" = "release" ]
then
    CRASH_REPORT_ENV="$BUILD_TAG"
else
    CRASH_REPORT_ENV="SNAPSHOOT"
fi

BUILD_REV=$(git rev-parse HEAD)
BUILD_UTCTIME=$(date -u '+%Y/%m/%d %H:%M:%S')

# Variables beginning with "STABLE" will be written to stable-status.txt, and
# others will be written to volatile-status.txt.
# Go binaries will be re-linked by Bazel upon changes to stable-status.txt, but
# not if only volatile-status.txt has changed.
# Ref:
# * https://docs.bazel.build/versions/main/user-manual.html#workspace_status
# * https://github.com/bazelbuild/rules_go/blob/master/go/core.rst#defines-and-stamping
cat <<EOF
STABLE_BUILD_CHANNEL ${BUILD_CHANNEL-}
STABLE_BUILD_TARGET_TRIPLE ${TARGET_TRIPLE-}
STABLE_BUILD_TYPE ${BUILD_TYPE-}
STABLE_CRASH_REPORT_ENV ${CRASH_REPORT_ENV-}
BUILD_REV ${BUILD_REV-}
BUILD_TAG ${BUILD_TAG-}
BUILD_UTCTIME ${BUILD_UTCTIME-}
EOF


# ROOT=$(dirname "${BASH_SOURCE[0]}")/..

# git=(git --work-tree "${ROOT}")
# GIT_COMMIT=$("${git[@]}" rev-parse "HEAD^{commit}" 2>/dev/null)
# GIT_TAG=$(git describe --tag --always)

# if [[ -f "VERSION" && -f "GIT_COMMIT" ]];
# then
#     echo "STABLE_BUILD_SCM_REVISION $(cat GIT_COMMIT)"
#     echo "STABLE_BUILD_TAG $(cat VERSION)"
#     echo "STABLE_BUILD_NUMBER ${BUILD_NUMBER}"
#     echo "STABLE_BUILD_SCM_STATUS Distribution"

#     exit 0
# fi

# The code below presents an implementation that works for git repository.
# git_rev=$(git rev-parse HEAD)
# if [[ $? != 0 ]];
# then
#     exit 1
# fi
# echo "STABLE_BUILD_SCM_REVISION ${git_rev}"


# Check whether there are any uncommitted changes.
# git diff-index --quiet HEAD --
# if [[ $? == 0 ]];
# then
#     tree_status="Clean"
# else
#     tree_status="Modified"
# fi

# echo "STABLE_BUILD_SCM_STATUS ${tree_status}"

# Use 0.0.0-dev for all dev build versions. We don't have a version number that is
# shared accross all our binaries which makes it hard to semantically version.
# echo "BUILD_TAG 0.0.0-dev"
# echo "STABLE_BUILD_TAG 0.0.0-dev"
# echo "STABLE_BUILD_NUMBER 0"

# echo "BUILD_TAG 0.0.0-dev"
# echo "BUILD_NUMBER 0"


# Invoke bazel with --workspace_status_command=bazel/build-version.sh to
# get this invoked and populate bazel-out/volatile-status.sh
# LOCAL_GIT_DATE="$(git log -n1 --date=short --format='%cd' 2>/dev/null)"
# LOCAL_GIT_VERSION="$(git describe 2>/dev/null)"

# # If we get these values above, overwrite potentially set environment variables.
# test -z "$LOCAL_GIT_DATE" || GIT_DATE="$LOCAL_GIT_DATE"
# test -z "$LOCAL_GIT_VERSION" || GIT_VERSION="$LOCAL_GIT_VERSION"

# test -z "$GIT_DATE" || echo "GIT_DATE \"$GIT_DATE\""
# test -z "$GIT_VERSION" || echo "GIT_DESCRIBE \"$GIT_VERSION\""

# Prefix with STABLE_ so that these values are saved to stable-status.txt
# instead of volatile-status.txt.
# Stamped rules will be retriggered by changes to stable-status.txt, but not by
# changes to volatile-status.txt.
# cat <<EOF
# GIT_COMMIT ${GIT_COMMIT-}
# GIT_TAG ${GIT_TAG-}
# EOF

# (
#     name = "test",
#     ....
#     tag = "test_{GIT_TAG}",
# )
