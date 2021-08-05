"""
Helper wrapper functions
"""

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@com_google_protobuf//:protobuf.bzl", "cc_proto_library", "py_proto_library")
load("@rules_python//python:defs.bzl", "py_library","py_binary","py_test")

def msvc_cpp_build_copts():
    return [
        "/std:c++17",  # This MUST match all other compilation units
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

    ] + select({
        ":with_glog": ["-DBRPCG=1"],
        "//conditions:default": ["-DBRPC=0"],
    }) + select({
        ":with_opendds": ["-DBRPC=1"]
            + select({
                ":linux_x86_64": [
                    "-DLINUX_UNIX",
                ],
                ":linux_aarch64": [
                    "-fpic",
                ],
                "//conditions:default": ["-DBRPC=0"],
            }),
        "//conditions:default": ["-DBRPC=0"],
    }) + select({
        ":with_fastrtps": ["-DUSE_MESALINK"]
            + select({
                ":linux_x86_64": [
                    "-DLINUX_UNIX",
                ],
                ":linux_aarch64": [
                    "-fpic",
                ],
                "//conditions:default": ["-DBRPC=0"],
            }),
        "//conditions:default": [""],
    }) + select({
        ":with_vortexdds": ["-DVORTEX_DDS=1",]
            + select({
                ":linux_x86_64": [
                    "-DLINUX_UNIX",
                ],
                ":linux_aarch64": [
                    "-fpic",
                ],
                "//conditions:default": ["-DBRPC_WITH_GLOG=0"],
            }),
        "//conditions:default": [""],
    }) + select({
        ":with_rtidds": [
                "-DRTI_DDS=1",
        ] + select({
                ":linux_x86_64": [
                    "-DRTI_UNIX",
                    "-DRTI_LINUX",
                    "-DRTI_64BIT",
                    "-DNDDSHOME=/opt/rti_connext_dds-5.3.1",
                    "-DCONNEXTDDS_ARCH=x64Linux3gcc5.4.0",
                    "-DRTICODEGEN_DIR=$NDDSHOME/bin",
                ],
                ":linux_aarch64": [
                    "-DRTI_UNIX",
                    "-DRTI_LINUX",
                    "-DRTI_64BIT",
                    "-fpic",
                ],
                "//conditions:default": ["-DBRPC_WITH_GLOG=0"],
#            "RTI_UNIX",
#            "RTI_DARWIN",
#            "RTI_DARWIN10",
#            "RTI_64BIT",
            }),
        "//conditions:default": [""],
    })

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

def sdlc_copts():
    return [
        "",
    ] + select({
        #"@bazel_tools//src/conditions:host_windows": "@rules_sdlc//:bin/protoc.bat"
        "@bazel_tools//src/conditions:windows": msvc_cpp_build_copts(),
        "@bazel_tools//src/conditions:windows_msvc": msvc_cpp_build_copts(),
        "@bazel_tools//src/conditions:windows_msys": msvc_cpp_build_copts(),
        "@bazel_tools//toolchain:windows_x86_64": [
            "/Zc:__cplusplus",
            "/Zc:inline",
            "/Zc:strictStrings",
            "/DWIN32_LEAN_AND_MEAN",
        ] + msvc_cpp_build_copts(),
        "//conditions:default": [
            "-std=c++17",
        ],
    })

def sdlc_cpp_deps():
    return [
        "@com_github_gflags_gflags//:gflags",
        "@com_google_protobuf//:protobuf",
    ] + select({
        ":with_glog": ["@com_github_google_glog//:glog"],
        "//conditions:default": [],
    })

#def _sdlc_platform_tag():

PLATFORM_TAGS = {
    "@bazel_tools//toolchain:windows_x86_64": ["msvc"],
    "@bazel_tools//toolchain:macos_x86_64": ["darwin"],
    "//conditions:default": ["linux"],
}

def sdlc_linkopts():
    return [
        "",
    ] + select({
        "@bazel_tools//src/conditions:windows": [],
        "@bazel_tools//src/conditions:darwin": [],
        "@bazel_tools//src/conditions:linux_x86_64": [
            "-L/usr/local/lib",
            "-lpthread",
            "-lm",
            "-lrt",
            "-lssl",
            "-lcrypto",
            "-lapr-1",
            "-laprutil-1",
            "-llog4cxx",
        ],
        "//conditions:default": [] ,
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
                copts = sdlc_copts() + copts,
                linkopts = sdlc_linkopts() + linkopts,
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
    kwargs["linkopts"] = kwargs.get("linkopts", []) + sdlc_linkopts()
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
            "@io_rules_sdlc//:windows_x86_64": [msvc_cpp_build_copts()],
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
