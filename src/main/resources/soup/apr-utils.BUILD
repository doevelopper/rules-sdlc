load("@rules_foreign_cc//foreign_cc:defs.bzl", "configure_make")
package(default_visibility = ["//visibility:public"])

filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)

    # "--with-apr=$$EXT_BUILD_DEPS$$/apr",
    # "--with-expat=$$EXT_BUILD_DEPS$$/expat",
    # "-with-apr=../apr-1.7.0"
    # "--with-expat=../libexpat/expat",
    # $EXT_BUILD_ROOT/external/org_apache_apr
# CONFIGURE_OPTIONS = [
#   # "--with-apr=${EXT_BUILD_DEPS}/org_apache_apr",
#   "--with-apr=${EXT_BUILD_DEPS}/apr/",
#   "--with-expat=${EXT_BUILD_DEPS}/expat/",
#   # "--with-crypto",
#   "--with-openssl=${EXT_BUILD_DEPS}/openssl/",
# #   "$$EXT_BUILD_DEPS$$/apr",
# ]


CONFIGURE_OPTIONS = [
    "--with-apr=\"$$EXT_BUILD_DEPS$$/apr\"",
    "--with-expat=\"$$EXT_BUILD_DEPS$$/com_github_libexpat/expat\"",
    "--with-openssl=\"$$EXT_BUILD_DEPS$$/com_github_openssl/openssl\"",
    "--with-crypto",
]

configure_make(
    name = "aprutil",
    configure_command = "configure",

    # configure_env_vars = select({
    #     # "@bazel_tools//platforms:osx": {"AR": ""},
    #     "//conditions:default": {},
    # }),

    configure_in_place = True,

    configure_options = CONFIGURE_OPTIONS + select({
        "@bazel_tools//platforms:osx": [
            # "-fPIC",
        ] ,
        "@bazel_tools//platforms:linux": [
            # "--prefix=${INSTALLDIR}",
        ] ,
        "//conditions:default": [
            # "-fPIC",
            # "no-shared",
        ] ,
    }),

    lib_source = ":all",

    linkopts = select({
        "@bazel_tools//platforms:osx": [
            "-lpthread",
        ],
        "@bazel_tools//platforms:linux": [
            "-ldl",
        ],
        "//conditions:default": [ ],
    }),

    # out_include_dir = "include/apr",
    # out_lib_dir = "lib",

    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "libaprutil-1.a",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@bazel_tools//platforms:windows": [
            "libaprutil-1.lib",
        ],
        "//conditions:default": [
            "libaprutil-1.a",
        ],
    }),

    out_shared_libs = select({
        "@bazel_tools//platforms:osx": [
            "libaprutil.dylib",
        ],
        # considere using "@platforms//os:windows": or @bazel_tools//platforms:windows or "@bazel_tools//src/conditions:windows":
        "@bazel_tools//platforms:windows": [
            "libaprutil-1.lib",
        ],
        "//conditions:default": [
            "libaprutil-1.so",
            "libaprutil-1.so.0",
            "libaprutil-1.so.0.6.1"
        ],
    }),

    deps = [
        "@org_apache_apr//:apr",
        "@com_github_libexpat//:expat",
        "@com_github_openssl//:openssl",
    ],

    visibility = ["//visibility:public"],
)
