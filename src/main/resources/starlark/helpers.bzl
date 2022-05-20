"""
Helper wrapper functions
"""

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@com_google_protobuf//:protobuf.bzl", "cc_proto_library", "py_proto_library")
load("@rules_python//python:defs.bzl", "py_binary", "py_library", "py_test")

def msvc_cpp_build_copts():
    return [
        "-WX",
        "-DWIN32",
        "-DWIN32_LEAN_AND_MEAN",
    ]

def gcc_cpp_build_copts():
    return [
        "-std=c++17",
        "-W",
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-Wconversion",
        "-Woverloaded-virtual",
        "-Wstack-protector",
    ]

def clang_cpp_build_copts():
    return [
        "-Wno-conversion",
        "-Wno-covered-switch-default",
        "-Wno-deprecated",
        "-Wno-disabled-macro-expansion",
        "-Wno-double-promotion",
        "-Wno-comma",
        "-Wno-extra-semi",
        "-Wno-packed",
        "-Wno-padded",
        "-Wno-sign-compare",
        "-Wno-float-conversion",
        "-Wno-float-equal",
        "-Wno-format-nonliteral",
        "-Wno-gcc-compat",
        "-Wno-global-constructors",
        "-Wno-exit-time-destructors",
        "-Wno-nested-anon-types",
        "-Wno-non-modular-include-in-module",
        "-Wno-old-style-cast",
        "-Wno-range-loop-analysis",
        "-Wno-reserved-id-macro",
        "-Wno-shorten-64-to-32",
        "-Wno-switch-enum",
        "-Wno-thread-safety-negative",
        "-Wno-undef",
        "-Wno-unknown-warning-option",
        "-Wno-unreachable-code",
        "-Wno-unused-macros",
        "-Wno-weak-vtables",
        "-Wbitfield-enum-conversion",
        "-Wbool-conversion",
        "-Wconstant-conversion",
        "-Wenum-conversion",
        "-Wint-conversion",
        "-Wliteral-conversion",
        "-Wnon-literal-null-conversion",
        "-Wnull-conversion",
        "-Wobjc-literal-conversion",
        "-Wno-sign-conversion",
        "-Wstring-conversion",
    ]

def clang_cpp_build_test_copts():
    return [
        "-Wno-missing-noreturn",
        "-Wno-missing-prototypes",
        "-Wno-missing-variable-declarations",
        "-Wno-null-conversion",
        "-Wno-shadow",
        "-Wno-shift-sign-overflow",
        "-Wno-sign-compare",
        "-Wno-unused-function",
        "-Wno-unused-member-function",
        "-Wno-unused-parameter",
        "-Wno-unused-private-field",
        "-Wno-unused-template",
        "-Wno-used-but-marked-unused",
        "-Wno-zero-as-null-pointer-constant",
        "-Wno-gnu-zero-variadic-macro-arguments",
    ]

def cpp_werror_build_copts():
    return [
        "-Werror=return-type",
        "-Werror=switch",
        "-Werror=reorder",
        "-Werror=non-virtual-dtor",
        "-fmax-errors=5",
        "-Werror=aggressive-loop-optimizations",
        "-Werror=missing-field-initializers",
        "-Werror=conversion",
        "-Werror=format-security",
        "-Werror=shadow",
        "-Werror=address",
        "-Werror=sequence-point",
        #"-Werror=conversion",
        #"-Werror=implicit-function-declaration",
    ]

def cpp_build_copts():
    return [
        "-Wsign-conversion",
        "-Wcomment",
        "-Wconversion",
        "-Wduplicated-cond",
        "-Wduplicated-branches",
        "-Winit-self",
        "-Wmissing-declarations",
        "-ftemplate-backtrace-limit=0",
        "-Wdouble-promotion",
        "-Wfloat-equal",
        "-Wimport",
        "-Wchar-subscripts",
        "-Wswitch-default",
        "-Wdisabled-optimization",
        "-Wcast-qual",
        "-Wold-style-cast",
        "-Wcast-align",
        "-Wctor-dtor-privacy",
        "-Wredundant-decls",
        "-Wvariadic-macros",
        "-Wwrite-strings",
        #"-Wmissing-include-dirs"
        "-Wlong-long",
        "-Wmissing-braces",
        "-Wmissing-format-attribute",
        "-Wmisleading-indentation",
        "-Wnoexcept",
        "-Wreturn-type",
        "-Wsequence-point",
        "-Wsign-compare",
        "-Wpacked",
        "-Wparentheses",
        "-Wpointer-arith",
        "-Wunused-variable",
        "-Wunused-parameter",
        "-Wunused-value",
        "-Wuninitialized",
        "-Wnull-dereference",
        "-Wuseless-cast",
        "-Wzero-as-null-pointer-constant",
        "-Wvolatile-register-var",
        "-Wformat=2",
        "-Wfloat-equal",
        "-Wformat",
        "-Wformat-nonliteral",
        "-Wvarargs",
        "-Wvla",  # variable-length array
        "-Wsign-promo",
    ]

def gcc_cpp_test_build_copts():
    return [
        "-Wno-conversion-null",
        "-Wno-missing-declarations",
        "-Wno-sign-compare",
        "-Wno-unused-function",
        "-Wno-unused-parameter",
        "-Wno-unused-private-field",
    ]

def cpp_memory_flags():
    return [
        "-fsanitize=memory",
        "-fsanitize-memory-track-origins=2",
        "-fno-omit-frame-pointer",
        "-fsanitize=null",
        "-fsanitize=unreachable",
        "-fstack-check",
        "-fvtable-verify=std",
        "-fsanitize=thread",
        "-fsanitize=address",
        "-fsanitize=undefined-trap",
        "-fsanitize-undefined-trap-on-error",
        "-fno-sanitize-recover",
        "-fsanitize=dataflow",
    ]

SDLC_COPTS = select({
    "@bazel_tools//toolchain:windows_x86_64": [
        "/std:c++17",  # This MUST match all other compilation units
        "/Zc:__cplusplus",
        "/Zc:inline",
        "/Zc:strictStrings",
        "/DWIN32_LEAN_AND_MEAN",
    ],
    "//conditions:default": [
        "-std=c++17",
        "-Werror",
    ],
})

PLATFORM_TAGS = {
    "@bazel_tools//toolchain:windows_x86_64": ["msvc"],
    "@bazel_tools//toolchain:macos_x86_64": ["darwin"],
    "//conditions:default": ["linux"],
}

SDLC_LINKOPTS = select({
    "@com_intel_plaidml//toolchain:windows_x86_64": [],
    "@com_intel_plaidml//toolchain:macos_x86_64": [],
    "//conditions:default": [
        "-pthread",
        "-lm",
        "-lrt",
    ],
})

def _shlib_name_patterns(name):
    return {
        "@bazel_tools//toolchain:windows_x86_64": ["{}.dll".format(name)],
        "@bazel_tools//toolchain:macos_x86_64": ["lib{}.dylib".format(name)],
        "//conditions:default": ["lib{}.so".format(name)],
    }

def sdlc_cc_shlib(
        name,
        shlib_name = None,
        copts = [],
        linkopts = [],
        visibility = None,
        **kwargs):
    if shlib_name == None:
        shlib_name = name

    names = _shlib_name_patterns(shlib_name)

    for key, name_list in names.items():
        for name_os in name_list:
            native.cc_binary(
                name = name_os,
                copts = SDLC_COPTS + copts,
                linkopts = SDLC_LINKOPTS + linkopts,
                linkshared = 1,
                tags = PLATFORM_TAGS[key],
                visibility = visibility,
                **kwargs
            )

    native.filegroup(
        name = name,
        srcs = select(names),
        visibility = visibility,
    )

def sdlc_cpp_library(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_library(**kwargs)

def sdlc_cpp_binary(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_binary(**kwargs)

def sdlc_cpp_test(**kwargs):
    kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts()
    cc_test(**kwargs)

PY_SRCS_VER = "PY2AND3"

def sdlc_py_library(**kwargs):
    py_library(srcs_version = PY_SRCS_VER, **kwargs)

def sdlc_py_binary(**kwargs):
    py_binary(srcs_version = PY_SRCS_VER, **kwargs)

def sdlc_py_test(**kwargs):
    py_test(srcs_version = PY_SRCS_VER, **kwargs)

def sdlc_py_proto_library(name, srcs, deps = (), srcs_version = PY_SRCS_VER, **kwargs):
    py_proto_library(
        name = name + "_py",
        srcs = srcs,
        srcs_version = srcs_version,
        deps = [d + "_py" for d in deps] + ["@com_google_protobuf//:protobuf_python"],
        protoc = "@com_google_protobuf//:protoc",
        default_runtime = "@com_google_protobuf//:protobuf_python",
        **kwargs
    )

def sdlc_cc_proto_library(name, srcs, deps = (), **kwargs):
    cc_proto_library(
        name = name + "_cc",
        srcs = srcs,
        deps = [d + "_cc" for d in deps] + ["@com_google_protobuf//:cc_wkt_protos"],
        copts = select({
            "@com.github.doevelopper.rules-sdlc//:windows_x86_64": [msvc_cpp_build_copts()],
            "//conditions:default": [gcc_cpp_build_copts()],
        }),
        #kwargs["copts"] = kwargs.get("copts", []) + gcc_cpp_build_copts(),
        protoc = "@com_google_protobuf//:protoc",
        default_runtime = "@com_google_protobuf//:protobuf",
        **kwargs
    )

def sdlc_proto_library(name, **kwargs):
    sdlc_cc_proto_library(name = name, **kwargs)
    sdlc_py_proto_library(name = name, **kwargs)
