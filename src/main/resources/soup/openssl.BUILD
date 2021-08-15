
load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)

CONFIGURE_OPTIONS = [
    "no-weak-ssl-ciphers",
    "no-idea",
    "no-comp",
]

configure_make(
    name = "openssl",
    lib_source = "@openssl//:all",
    configure_command = "config",
    configure_env_vars = select({
        ":platform_osx": {"AR": ""},
        "//conditions:default": {},
    }),
    configure_options = [
        "no-shared",
      ] + select({
        "//bazel:darwin_build": [
            "enable-ec_nistp_64_gcc_128",
            "no-ssl2",
            "no-ssl3",
            "no-comp",
        ],
        "//conditions:default": []}
      ),

    configure_env_vars = select({
        "//bazel:darwin_build": {
            "OSX_DEPLOYMENT_TARGET": "10.15",
            "AR": "/usr/bin/ar",
        },
        "//conditions:default": {}}
    ),

    static_libraries = [
        "libssl.a",
        "libcrypto.a",
    ],

    visibility = ["//visibility:public"],
)
