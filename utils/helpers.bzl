"""
Helper wrapper functions
"""

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

def gcc_cpp_build_copts():
    return [
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-Wconversion"
    ]

def sdlc_cpp_library(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_library(**kwargs)

def sdlc_cpp_binary(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_binary(**kwargs)

def sdlc_cpp_test(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_test(**kwargs)

