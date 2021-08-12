# Invoke bazel with --workspace_status_command=bazel/build-version.sh to
# get this invoked and populate bazel-out/volatile-status.sh
LOCAL_GIT_DATE="$(git log -n1 --date=short --format='%cd' 2>/dev/null)"
LOCAL_GIT_VERSION="$(git describe 2>/dev/null)"

# If we get these values above, overwrite potentially set environment variables.
test -z "$LOCAL_GIT_DATE" || GIT_DATE="$LOCAL_GIT_DATE"
test -z "$LOCAL_GIT_VERSION" || GIT_VERSION="$LOCAL_GIT_VERSION"

test -z "$GIT_DATE" || echo "GIT_DATE \"$GIT_DATE\""
test -z "$GIT_VERSION" || echo "GIT_DESCRIBE \"$GIT_VERSION\""