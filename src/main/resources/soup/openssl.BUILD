
load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)

configure_make(
    name = "openssl",
    lib_source = ":all",
    configure_command = "config",
    out_lib_dir = "lib",

    linkopts = select({
        "@bazel_tools//platforms:osx": [
            "-lpthread",
        ],
        "@bazel_tools//platforms:linux": [
            "-ldl",
            "-lpthread",
        ],
        "//conditions:default": [ ],
    }),

    # configure_env_vars = select({
    #     # "@bazel_tools//platforms:osx": {"AR": ""},
    #     "@bazel_tools//platforms:osx": {
    #         "OSX_DEPLOYMENT_TARGET": "10.15",
    #         "AR": "/usr/bin/ar",
    #     },
    #     "//conditions:default": {},
    # }),

    configure_options = [
        "zlib",
        "--with-zlib-include=\"$$EXT_BUILD_DEPS$$/zlib/include\"",
        "--with-zlib-lib=\"$$EXT_BUILD_DEPS$$/zlib/lib\"",
        "no-shared",
        "no-tests",
        "no-weak-ssl-ciphers",
        "no-idea",
        "no-comp",
    ] + select({
        "@bazel_tools//platforms:osx": [
            "enable-ec_nistp_64_gcc_128",
            "no-ssl2",
            "no-ssl3",
        ],
        "//conditions:default": []
    }),


    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "libssl.a",
            "libcrypto.a",
        ],

        "@bazel_tools//platforms:windows": [
            "libssl.lib",
            "libcrypto.lib",
        ],
        "//conditions:default": [
            "libssl.a",
            "libcrypto.a",
        ],
    }),

    # shared_libraries = select({
    #     "@platforms//os:macos": [
    #         "libssl.dylib",
    #         "libcrypto.dylib",
    #     ],
    #     "//conditions:default": [
    #         "libssl.so",
    #         "libssl.so.1.1",
    #         "libcrypto.so",
    #         "libcrypto.so.1.1",
    #     ],
    # }),

    deps = [
        # "@zlib//:zlib",
        "@net_zlib_fossils//:zlib",
    ],

    visibility = ["//visibility:public"],
)
