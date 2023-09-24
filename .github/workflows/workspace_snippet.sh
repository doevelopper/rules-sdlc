#!/usr/bin/env bash

set -o errexit -o nounset -o pipefail

# Set by GH actions, see
# https://docs.github.com/en/actions/learn-github-actions/environment-variables#default-environment-variables
TAG=${GITHUB_REF_NAME}
PREFIX="rules_infra-${TAG:1}"
SHA=$(git archive --format=tar --prefix=${PREFIX}/ ${TAG} | gzip | shasum -a 256 | awk '{print $1}')

cat << EOF
WORKSPACE snippet:
\`\`\`starlark
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "com.github.doevelopper.rules-sdlc",
    sha256 = "${SHA}",
    strip_prefix = "${PREFIX}",
    url = "https://github.com/doevelopper/rules_infra/archive/refs/tags/${TAG}.tar.gz",
)

load(
  "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:sw_dev.bzl",
  "dev_repositories"
)
dev_repositories()

load(
  "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:sw_qa.bzl",
  "qa_repositories"
)
qa_repositories()

load(
  "@com.github.doevelopper.rules-sdlc//src/main/resources/starlark:dependencies.bzl",
  "rules_sdlc_dependencies"
)
rules_sdlc_dependencies()

EOF

awk 'f;/--SNIP--/{f=1}' e2e/workspace/WORKSPACE
echo "\`\`\`"
