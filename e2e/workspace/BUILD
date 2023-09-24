"""Provides a simple way to test your rules as an external workspace.
Add a basic smoke-test target below.
"""

load("@bazel_skylib//src/main/resources/starlark/rules:build_test.bzl", "build_test")
# load("@com.github.doevelopper.rules-sdlc//src/main/resources/starlark/rules:defs.bzl", "...")

# Replace with a usage of your rule/macro
filegroup(name = "empty")

build_test(
    name = "smoke_test",
    targets = [
        # targets you add above
        ":empty",
    ],
)
