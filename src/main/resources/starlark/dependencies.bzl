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

grpc_grpc_version = "1.37.1"
eigen_version = "3.3.9"
think_version = "1.50"

COM_GOOGLE_PROTOBUF_SHA = "c6003e1d2e7fefa78a3039f19f383b4f3a61e81be8c19356f85b6461998ad3db"
COM_GOOGLE_PROTOBUF_VERSION = "3.17.3"

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

    # bazel query @com_github_libexpat_libexpat//...
    # bazel build @com_github_libexpat_libexpat//:expat
    "com_github_libexpat_libexpat": {
        "build_file": "@com.github.doevelopper.rules-sdlc//src/main/resources/soup:expat.BUILD",
        "sha256": "b5dcb503e40f615a0296a18acc6d975f2f1a3d01c7b3a4b3bb69de27bc9475c3",
        "strip_prefix": "libexpat-R_2_2_4/expat",
        "urls" : [
            "https://mirror.bazel.build/github.com/libexpat/libexpat/archive/R_2_2_4.tar.gz",
            "https://github.com/libexpat/libexpat/archive/R_2_2_4.tar.gz",
        ],
    },
}

dependencies_repositories = {
    # bazel query @com_github_nelhage_rules_boost//...
    # bazel query @boost//...
    "com_github_nelhage_rules_boost": {
        "commit": "5cff96018ec4662cc61268cf248edfc6e6fe4635", #//1.74.0
        "remote": "https://github.com/nelhage/rules_boost",
        # "shallow_since": "1591047380 -0700",
        "shallow_since": "1610386445 -0800"
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
