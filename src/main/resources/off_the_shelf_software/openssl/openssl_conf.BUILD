# -*- bazel -*-

package(default_visibility = ["//visibility:public"])

load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")

filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])

config_setting(
    name = "platform_osx",
    constraint_values = [
        "@bazel_tools//src/conditions:darwin",
    ],
)

config_setting(
    name = "platform_linux",
    constraint_values = [
        "@bazel_tools//src/conditions:linux",
    ],
)

CONFIGURE_OPTIONS = [
    "no-weak-ssl-ciphers",
    "no-idea",
    "no-comp",
]

configure_make(
    name = "openssl",
    configure_command = "config",
    configure_env_vars = select({
        ":platform_osx": {"AR": ""},
        "//conditions:default": {},
    }),
    configure_in_place = True,
    configure_options = select({
        ":platform_osx": [
            "-fPIC",
            "no-asm",
            "no-afalgeng",
            "no-shared",
            "ARFLAGS=r",
        ] + CONFIGURE_OPTIONS,
        "//conditions:default": [
            "-fPIC",
            "no-shared",
        ] + CONFIGURE_OPTIONS,
    }),

    lib_source = ":all",
    out_lib_dir = "lib",
    linkopts = [
        "-ldl",
        "-lpthread",
    ],
    static_libraries = [
        "libssl.a",
        "libcrypto.a",
    ],
    visibility = ["//visibility:public"],
)
