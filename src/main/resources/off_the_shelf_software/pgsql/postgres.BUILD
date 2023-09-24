load("@rules_foreign_cc//tools/build_defs:configure.bzl", "configure_make")

config_setting(
    name = "darwin_build",
    values = {"cpu": "darwin"},
)

filegroup(
    name = "all",
    srcs = glob(["**"]),
)

configure_make(
    name = "postgres",
    lib_source = ":all",
    configure_env_vars = select({
        "@platforms//os:macos": {"AR": ""},
        "//conditions:default": {},
    }),
    configure_options = [
        "--without-readline",
        "--with-openssl",
        "--with-libraries=$EXT_BUILD_DEPS/openssl/lib",
        "--with-includes=$EXT_BUILD_DEPS/openssl/include",
        # See: https://github.com/bazelbuild/rules_foreign_cc/pull/362
        # `-fno-builtin` supresses a configure error on my macOS mojave
        "CFLAGS='-Dredacted=\\\"redacted\\\" -fno-builtin'",
    ],
    binaries = [
        "pg_ctl",
        "createdb",
        "initdb",
        "psql",
        "pg_config",
        "postgres",
    ],
    make_commands = [
        "make -j16",
        "make install",
    ],
    shared_libraries = select({
        # Workaround for libtool no output files specified on MacOS.
        # https://github.com/bazelbuild/rules_foreign_cc/issues/338
        # https://github.com/bazelbuild/rules_foreign_cc/issues/254
        ":darwin_build": [
            # "plpgsql.so",
            "libpq.dylib",
            # "libpgtypes.dylib",
        ],
        "//conditions:default": [
            # "plpgsql.so",
            "libpq.so",
            "libpq.so.5",
            # "libpgtypes.so",
        ],
    }),
    deps = [
        "@openssl//:openssl",
    ],
    visibility = ["//visibility:public"],
)
