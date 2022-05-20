load("@rules_python//python:defs.bzl", "py_runtime", "py_runtime_pair")

py_runtime(
    name = "python3_runtime",
    files = ["@com.github.doevelopper.rules-sdlc//src/main/resources/toolchain/python:files"],
    interpreter = "@com.github.doevelopper.rules-sdlc//src/main/resources/toolchain/python:python_bin",
    python_version = "PY3",
    visibility = ["//visibility:public"],
)

py_runtime_pair(
    name = "py_runtime_pair",
    py2_runtime = None,
    py3_runtime = ":python3_runtime",
)

toolchain(
    name = "py_3_toolchain",
    toolchain = ":py_runtime_pair",
    toolchain_type = "@bazel_tools//tools/python:toolchain_type",
)
