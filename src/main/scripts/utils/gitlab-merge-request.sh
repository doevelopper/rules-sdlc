#!/usr/bin/env bash
# source https://about.gitlab.com/blog/2017/09/05/how-to-automatically-create-a-new-mr-on-gitlab-with-gitlab-ci/
set -e

if [ -z "$GITLAB_PRIVATE_TOKEN" ]; then
  echo "GITLAB_PRIVATE_TOKEN not set"
  echo "Please set the GitLab Private Token as GITLAB_PRIVATE_TOKEN"
  exit 1
fi

# Extract the host where the server is running, and add the URL to the APIs
[[ $HOST =~ ^https?://[^/]+ ]] && HOST="${BASH_REMATCH[0]}/api/v4/projects/"

# Look which is the default branch
TARGET_BRANCH=`curl --silent "${HOST}${CI_PROJECT_ID}" --header "PRIVATE-TOKEN:${PRIVATE_TOKEN}" | python3 -c "import sys, json; print(json.load(sys.stdin)['default_branch'])"`;
#TARGET_BRANCH=`curl --silent "${HOST}${CI_PROJECT_ID}" --header "PRIVATE-TOKEN:${GITLAB_PRIVATE_TOKEN}" | jq --raw-output '.default_branch'`;

# Look for title in variables, otherwise use branch name
if [ -z "$MERGE_REQUEST_TITLE" ]; then
  MERGE_REQUEST_TITLE=$CI_COMMIT_REF_NAME
fi

# The description of our new MR, we want to remove the branch after the MR has
# been closed
BODY="{
    \"id\": ${CI_PROJECT_ID},
    \"source_branch\": \"${MERGE_REQUEST_TITLE}\",
    \"target_branch\": \"${TARGET_BRANCH}\",
    \"remove_source_branch\": true,
    \"title\": \"WIP: ${MERGE_REQUEST_TITLE}\",
    \"assignee_id\":\"${GITLAB_USER_ID}\"
}";

# Require a list of all the merge request and take a look if there is already
# one with the same source branch
LISTMR=`curl --silent "${HOST}${CI_PROJECT_ID}/merge_requests?state=opened" --header "PRIVATE-TOKEN:${PRIVATE_TOKEN}"`;
COUNTBRANCHES=`echo ${LISTMR} | grep -o "\"source_branch\":\"${CI_COMMIT_REF_NAME}\"" | wc -l`;
#${TARGET_BRANCH}

# No MR found, let's create a new one
if [ ${COUNTBRANCHES} -eq "0" ]; then
    curl -X POST "${HOST}${CI_PROJECT_ID}/merge_requests" \
        --header "PRIVATE-TOKEN:${PRIVATE_TOKEN}" \
        --header "Content-Type: application/json" \
        --data "${BODY}";

    echo "Opened a new merge request: WIP: ${CI_COMMIT_REF_NAME} and assigned to ${GITLAB_USER_LOGIN}";
    exit;
fi

echo "No new merge request opened";
