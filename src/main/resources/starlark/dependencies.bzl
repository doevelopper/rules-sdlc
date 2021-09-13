"""All development and production dependencies of rules_sdlc."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# load("@rules_java//java:repositories.bzl", "rules_java_dependencies")
# rules_java_dependencies()
# Sanitize a dependency so that it works correctly from code that includes it as a submodule.

BUILD_ALL_CONTENT = """\
filegroup(
    name = "all",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"]
)
"""

def clean_dep(dep):
    return str(Label(dep))

grpc_grpc_version = "1.39.1"
eigen_version = "3.3.9"
think_version = "1.50"

COM_GOOGLE_PROTOBUF_SHA = "c6003e1d2e7fefa78a3039f19f383b4f3a61e81be8c19356f85b6461998ad3db"
COM_GOOGLE_PROTOBUF_VERSION = "3.17.3"

COM_GITHUB_OPENSSL_SHA = "b92f9d3d12043c02860e5e602e50a73ed21a69947bcc74d391f41148e9f6aa95"
COM_GITHUB_OPENSSL_VERSION = "1_1_1k"

dependencies_archives = {

    "font_roboto": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/third_party:font-roboto.BUILD",
        "url": "https://github.com/polymerelements/font-roboto/archive/v1.1.0.tar.gz",
        "strip_prefix": "font-roboto-1.1.0",
    },

    "com_google_protobuf": {
        "sha256": COM_GOOGLE_PROTOBUF_SHA,
        "strip_prefix": "protobuf-{}".format(COM_GOOGLE_PROTOBUF_VERSION),
        "urls": [
            "https://github.com/protocolbuffers/protobuf/archive/v{}.tar.gz".format(COM_GOOGLE_PROTOBUF_VERSION),
            "https://github.com/protocolbuffers/protobuf/archive/v{}.tar.gz".format(COM_GOOGLE_PROTOBUF_VERSION),
            # "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v{}.tar.gz".format(COM_GOOGLE_PROTOBUF_VERSION),
        ],
    },

    "com_github_tencent_rapidjson": {
        # "sha256": "71e2acc106ba5475bc5b1522b4a4b17183d3d0f2b6634cc621316346f84d8958",
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:rapidjson.BUILD",
        "strip_prefix": "rapidjson-master",
        "url": "https://github.com/Tencent/rapidjson/archive/master.zip",
    },

    # bazel query @org_apache_apr//...
    # bazel build @org_apache_apr//:apr
    "org_apache_apr": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apr.BUILD",
        "sha256": "48e9dbf45ae3fdc7b491259ffb6ccf7d63049ffacbc1c0977cced095e4c2d5a2",
        "strip_prefix": "apr-1.7.0",
        "urls": [
            "https://downloads.apache.org//apr/apr-1.7.0.tar.gz",
            "https://downloads.apache.org//apr/apr-1.7.0.tar.bz2",
            # "https://downloads.apache.org//apr/apr-1.7.0-win32-src.zip",
        ],
    },

    # bazel query @com_github_libexpat//...
    # bazel build @com_github_libexpat//:expat
    "com_github_libexpat": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:expat.BUILD",
        "sha256": "660e5852b26125f4508183dfa134e18eb33a892dbd8e06786ea38d92dbbb5b07",
        "strip_prefix": "libexpat-R_2_4_1/expat",
        "urls" : [
            "https://github.com/libexpat/libexpat/archive/refs/tags/R_2_4_1.tar.gz",
            "https://github.com/libexpat/libexpat/archive/refs/tags/R_2_4_1.zip",
        ],
    },

    # bazel query @org_apache_apr_util//...
    # bazel build @org_apache_apr_util//:aprutil
    "org_apache_apr_util": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apr-utils.BUILD",
        "sha256": "b65e40713da57d004123b6319828be7f1273fbc6490e145874ee1177e112c459",
        "strip_prefix": "apr-util-1.6.1",
        "urls": [
            "https://downloads.apache.org//apr/apr-util-1.6.1.tar.gz",
            "https://downloads.apache.org//apr/apr-util-1.6.1.tar.bz2",
            # "https://downloads.apache.org//apr/apr-util-1.6.1-win32-src.zip",
        ],
    },

    #  bazel build @net_zlib_fossils//:zlib
    "net_zlib_fossils": {
    "build_file_content": """load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
filegroup(
    name = "sources",
    srcs = glob(["**"]),
)

cmake(
    name = "zlib",
    cache_entries = {
    },
    lib_source = ":sources",

    out_static_libs = select({
        "@bazel_tools//platforms:osx": [
            "libz.a",
        ],

        "@bazel_tools//platforms:windows": [
            "libz.lib",
        ],
        "//conditions:default": [
            "libz.a",
        ],
    }),
    visibility = ["//visibility:public"],
)
""",
        # "build_file": "@com_google_absl_oss_federation//:zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            # Use the same URL twice to trick bazel into re-trying if connection fails
            "https://zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },

    "com_github_openssl": {
        "sha256": COM_GITHUB_OPENSSL_SHA,
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:openssl.BUILD",
        "strip_prefix": "openssl-OpenSSL_{}".format(COM_GITHUB_OPENSSL_VERSION),
        "urls": [
            "https://github.com/openssl/openssl/archive/refs/tags/OpenSSL_{}.tar.gz".format(COM_GITHUB_OPENSSL_VERSION),
            "https://github.com/openssl/openssl/archive/refs/tags/OpenSSL_{}.zip".format(COM_GITHUB_OPENSSL_VERSION),
            # "https://github.com/openssl/openssl/archive/refs/tags/openssl-3.0.0-beta2.tar.gz".format(COM_GITHUB_OPENSSL_VERSION),
            # "https://github.com/openssl/openssl/archive/refs/tags/openssl-3.0.0-beta2.zip".format(COM_GITHUB_OPENSSL_VERSION),
        ],
    },

    "org_apache_apriconv": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:apr_iconv.BUILD",
        # "sha256": "",
        "strip_prefix": "apr-iconv-1.2.2",
        "urls": [
            "https://downloads.apache.org//apr/apr-iconv-1.2.2.tar.gz",
            "https://downloads.apache.org//apr/apr-iconv-1.2.2.tar.bz2",
            "https://downloads.apache.org//apr/apr-iconv-1.2.2-win32-src.zip",
        ],
    },

    # https://github.com/<org>/<repo>/tarball/<sha>
    # https://github.com/apache/logging-log4cxx/tarball/249dd85494a430d95fd69d89f42b02fd950cda51
    # bazel query @org_apache_logging_log4cxx//...
    # bazel build @org_apache_logging_log4cxx//:log4cxx
    "org_apache_logging_log4cxx": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:log4cxx.BUILD",
        "sha256": "380a22e4422b0e68320a52b455a3f99ae142cb6b41ab5068a64561af20f976e7",
        # "strip_prefix": "apache-log4cxx-0.12.0",
        "strip_prefix": "logging-log4cxx-master",
        # "strip_prefix": "apache-logging-log4cxx-249dd85",
        # "strip_prefix": "logging-log4cxx-0.11.0",
        # "strip_prefix": "logging-log4cxx-rel-v0.12.0",
        "urls": [
    #         # "https://codeload.github.com/apache/logging-log4cxx/legacy.tar.gz/249dd85494a430d95fd69d89f42b02fd950cda51.tar.gz",
    #         # "https://codeload.github.com/apache/logging-log4cxx/legacy.tar.gz/249dd85494a430d95fd69d89f42b02fd950cda51.tar.gz",
            "https://github.com/apache/logging-log4cxx/archive/master.zip",
            "https://github.com/apache/logging-log4cxx/archive/master.zip",
    #         # "https://archive.apache.org/dist/logging/log4cxx/0.12.0/apache-log4cxx-0.12.0.tar.gz",
    #         # "https://downloads.apache.org/logging/log4cxx/0.12.0/apache-log4cxx-0.12.0.tar.gz",
    #         # "https://github.com/apache/logging-log4cxx/archive/v0.11.0.tar.gz",
    #         # "https://github.com/apache/logging-log4cxx/archive/v0.11.0.tar.gz",
    #         "https://github.com/apache/logging-log4cxx/archive/v0.12.0.tar.gz",
    #         "https://github.com/apache/logging-log4cxx/archive/v0.12.0.tar.gz",
            # "https://github.com/apache/logging-log4cxx/archive/refs/tags/rel/v0.12.0.tar.gz",
            # "https://github.com/apache/logging-log4cxx/archive/refs/tags/rel/v0.12.0.zip",
        ],
    },

    # bazel query @org_apache_xerces//...
    # bazel build @org_apache_xerces//:xerces
    "org_apache_xerces": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:xerces.BUILD",
        "sha256": "fb96fc49b1fb892d1e64e53a6ada8accf6f0e6d30ce0937956ec68d39bd72c7e",
        "strip_prefix": "xerces-c-3.2.3",
        "urls": [
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.gz",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.bz2",
            "https://downloads.apache.org/xerces/c/3/sources/xerces-c-3.2.3.tar.xz",
        ],
    },

    "com_github_grpc_grpc": {
        # "sha256": "acf247ec3a52edaee5dee28644a4e485c5e5badf46bdb24a80ca1d76cb8f1174",
        "strip_prefix": "grpc-{}".format(grpc_grpc_version),
        "urls": [
            "https://github.com/grpc/grpc/archive/v{}.tar.gz".format(grpc_grpc_version),
            "https://github.com/grpc/grpc/archive/v{}.tar.gz".format(grpc_grpc_version),
        ],
    },

    "com_github_gperftools_gperftools": {
        # "sha256": "2060769f2d4b0d3535ba594b2ab614d7f68a492f786ab94b4318788d45e3278a",
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:gperftools.BUILD",
        "strip_prefix": "gperftools-gperftools-2.9.1",
        "urls": [
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.9.1/gperftools-2.9.1.tar.gz",
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.9.1/gperftools-2.9.1.zip",
            "https://github.com/gperftools/gperftools/archive/refs/tags/gperftools-2.9.1.zip",
        ],
    },

    "com_google_crc32c": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:crc32.BUILD",
        # "sha256": "",
        "strip_prefix": "crc32c-1.1.1",
        "urls": [
            "https://github.com/google/crc32c/archive/1.1.1.tar.gz",
            "https://github.com/google/crc32c/archive/1.1.1.zip",
        ],
    },
}

dependencies_repositories = {
    # bazel query @com_github_nelhage_rules_boost//...
    # bazel query @boost//...
    "com_github_nelhage_rules_boost": {
        "commit": "fb9f3c9a6011f966200027843d894923ebc9cd0b", #//1.76.0
        "remote": "https://github.com/nelhage/rules_boost",
        # "shallow_since": "1591047380 -0700",
        "shallow_since": "1610386445 -0800"
    },

    "com_github_gflags_gflags": {
        "commit": "827c769e5fc98e0f2a34c47cef953cc6328abced",
        "remote": "https://github.com/gflags/gflags",
    },
    "com_github_baidu_braft": {
        "remote": "https://github.com/baidu/braft.git",
        "tag": "v1.1.2",
    },

    "com_github_brpc_brpc": {
        "remote": "https://github.com/apache/incubator-brpc.git",
        "tag": "1.0.0-rc01",
    },
}

dependencies_jar_repositories = {
    "com_google_code_gson_gson": {
        "artifact": "com.google.code.gson:gson:2.8.5",
        "sha1": "f645ed69d595b24d4cf8b3fbb64cc505bede8829",
    },
    "com_google_guava_guava": {
        "artifact": "com.google.guava:guava:26.0-jre",
        "sha1": "6a806eff209f36f635f943e16d97491f00f6bfab",
    },
}

def _archives_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_archives:
        if name not in ignores:
            maybe(http_archive, name, **dependencies_archives[name])

def _git_repo_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_repositories:
        if name not in ignores:
            maybe(git_repository, name, **dependencies_repositories[name])

def _java_dependencies(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_jar_repositories:
        if name not in ignores:
            maybe(native.maven_jar, name, **dependencies_jar_repositories[name])

def rules_sdlc_dependencies():
    _archives_deps()
    _git_repo_deps()
    # _java_dependencies()

"""
     " " "Dependencies and toolchains required to use rules_proto. " " "

    load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
    load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
    load("//repos/private:dependencies.bzl", "dependencies")

def rules_sdlc_dependencies():
    for name in dependencies:
        maybe(http_archive, name, **dependencies[name])

def rules_sdlc_toolchains():
    # Nothing to do here (yet).
    pass
"""
