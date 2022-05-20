#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

#this script will be run by bazel when the build process starts to
# generate key-value information that represents the status of the
# workspace. The output should be like
#
# KEY1 VALUE1
# KEY2 VALUE2
#
# If the script exits with non-zero code, it's considered as a failure
# and the output will be discarded.

function rev() {
  cd $1; git describe --always --match "v[0-9].*" --dirty
}

BUILD_HOTS=$(hostname)
BUILD_TIME=$(LC_ALL=en_EN.utf8 date)
BUILD_TIMESTAMP=$(date +%s000)
BUILD_DATE=$(date -u "+%b-%d-%Y")
BUILD_USERS=${USER:-root}
BUILD_WHOAMI=$(whoami)
BUILD_HOST_TYPE=$(arch)
BUILD_UNAME_OS=$(uname -s)
BUILD_OS_KERNEL=$(uname -r)
BUILD_GIT_COMMIT=$(git rev-parse --short HEAD)
BUILD_GIT_TAG=$(git describe --abbrev=0 --tags 2>/dev/null || echo "0.0.0")
BUILD_GIT_REV=$(git rev-parse HEAD)
BUILD_PROJECT_NAME=$(basename $PWD)
BUILD_VERSION=$(git describe --tags --long --dirty --always | \
    sed 's/v\([0-9]*\)\.\([0-9]*\)\.\([0-9]*\)-\?.*-\([0-9]*\)-\(.*\)/\1 \2 \3 \4 \5/g')
BUILD_SHORT_SHA1=$(git rev-parse --short=5 HEAD)
BUILD_GIT_STATUS=$(git status --porcelain)
BUILD_GIT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
BUILD_GIT_BRANCH_STR=$(git rev-parse --abbrev-ref HEAD | tr '/' '_')
BUILD_GIT_REPO=$(git config --local remote.origin.url | \
    sed -e 's/.git//g' -e 's/^.*\.com[:/]//g' | tr '/' '_' 2> /dev/null)
BUILD_GIT_REPOS_URL=$(git config --get remote.origin.url)
BUILD_CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
BUILD_GIT_BRANCHES=$(git for-each-ref --format='%(refname:short)' refs/heads/ | xargs echo)
BUILD_GIT_REMOTES=$(git remote | xargs echo )
BUILD_GIT_ROOTDIR=$(git rev-parse --show-toplevel)
BUILD_GIT_DIRTY=$(git diff --shortstat 2> /dev/null | tail -n1 )
BUILD_LAST_TAG_COMMIT=$(git rev-list --tags --max-count=1)
BUILD_GIT_COMMIT_COUNT=$(git rev-list --all --count)
#BUILD_GIT_REVISION=$(git rev-parse --short=8 HEAD || echo unknown)
#BUILD_LAST_TAG=$(git describe --tags ${BUILD_LAST_TAG_COMMIT} )
#BUILD_GIT_COMMITS=$(git log --oneline ${BUILD_LAST_TAG}..HEAD | wc -l | tr -d ' ')
#BUILD_GIT_LAST_TAG=$(git log --first-parent --pretty="%d" | \
#    grep -E "tag: v[0-9]+\.[0-9]+\.[0-9]+(\)|,)" -o | \
#    grep "v[0-9]*\.[0-9]*\.[0-9]*" -o | head -n 1)

if [[ $BUILD_CURRENT_BRANCH == *"develop"* ]]; then
    echo "It's there!"
fi

if [[ $BUILD_CURRENT_BRANCH =~ "feature" ]]
then
    echo "Still features branch"
fi

#SEM_VERSION=$([ -f VERSION ] && head VERSION || echo "0.0.1")
#PREVIOUS_VERSIONFILE_COMMIT=$(git log -1 --pretty=%h $VERSIONFILE 2>/dev/null )
#PREVIOUS_VERSION=$([ -n "$PREVIOUS_VERSIONFILE_COMMIT" ] && git show $PREVIOUS_VERSIONFILE_COMMIT^:$PWD/$VERSIONFILE)
#MAJOR=$(echo $(SEM_VERSION) | sed "s/^\([0-9]*\).*/\1/")
#MINOR=$(echo $(SEM_VERSION) | sed "s/[0-9]*\.\([0-9]*\).*/\1/")
#PATCH=$(echo $(SEM_VERSION) | sed "s/[0-9]*\.[0-9]*\.\([0-9]*\).*/\1/")
#STAGE=$(PATCH:$(SEM_VERSION)=0)
#BUILD=$(git log --oneline | wc -l | sed -e "s/[ \t]*//g")
#NEXT_MAJOR_VERSION=$(expr $(MAJOR) + 1).0.0-b$(BUILD)
#NEXT_MINOR_VERSION=$(MAJOR).$(expr $(MINOR) + 1).0-b$(BUILD)
#NEXT_PATCH_VERSION=$(MAJOR).$(MINOR).$(expr $(PATCH) + 1)-b$(BUILD)
echo BUILD_SCM_HASH $(git rev-parse HEAD)

# Prefix with STABLE_ so that these values are saved to stable-status.txt
# instead of volatile-status.txt.
# Stamped rules will be retriggered by changes to stable-status.txt, but not by
# changes to volatile-status.txt.

cat <<EOF
WS_HASH ${GIT_COMMIT-}
WS_DATE ${BUILD_TIME-}
WS_BRANCH ${BUILD_GIT_BRANCH-}
WS_GIT_COMMIT_DESC ${BUILD_GIT_BRANCH-}
WS_COUNT_GIT_COMMIT ${BUILD_GIT_COMMIT_COUNT-}
WS_HOST_PROC ${BUILD_HOST_TYPE-}
WS_SOURCE_DIR ${BUILD_GIT_ROOTDIR-}
WS_VENDOR "A.H.L SW Engineering"
WS_LEGAL "(c) 2015-2020 A.H.L SW Engineering Labs"
WS_FILEVERSION  "0.0.1"
WS_HOST_OS ${BUILD_UNAME_OS-}
WS_HOST_KERNEL ${BUILD_OS_KERNEL-}
EOF