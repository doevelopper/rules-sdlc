"""All development and production dependencies of rules_sdlc."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# Sanitize a dependency so that it works correctly from code that includes it as a submodule.
def clean_dep(dep):
    return str(Label(dep))

dependencies_archives = {

    "com_google_protobuf": {
        "sha256": "afaa4f65e7e97adb10b32b7c699b7b6be4090912b471028ef0f40ccfb271f96a",
        "strip_prefix": "protobuf-3.12.0-rc2",
        "urls": [
            "https://mirror.bazel.build/github.com/protocolbuffers/protobuf/archive/v3.12.0-rc2.tar.gz",
            "https://github.com/protocolbuffers/protobuf/archive/v3.12.0-rc2.tar.gz",
        ],
    },

    # Dependency of `com_google_protobuf`.
    "six": {
        ##build_file = clean_dep("@io_rules_sdlc//third_party:six.BUILD"),
        "build_file": "@com_google_protobuf//:third_party/six.BUILD",
        "sha256": "d16a0141ec1a18405cd4ce8b4613101da75da0e9a7aec5bdd4fa804d0e0eba73",
        "urls": [
            "https://mirror.bazel.build/pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
            "https://pypi.python.org/packages/source/s/six/six-1.12.0.tar.gz",
        ],
    },

    # Dependency of `com_google_protobuf`.
    "zlib": {
        "build_file": "@com_google_protobuf//:third_party/zlib.BUILD",
        "sha256": "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        "strip_prefix": "zlib-1.2.11",
        "urls": [
            "https://mirror.bazel.build/zlib.net/zlib-1.2.11.tar.gz",
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    },

    "org_tuxfamily_eigen": {
        "build_file": "@io_rules_sdlc//third_party:eigen.BUILD",
        #"sha256": "ca7beac153d4059c02c8fc59816c82d54ea47fe58365e8aded4082ded0b820c4",
        "strip_prefix": "eigen-eigen-323c052e1731",
        "urls": [
            "http://bitbucket.org/eigen/eigen/get/3.3.7.tar.bz2",
            "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
        ],
    },

    "png_archive": {
        "build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
         "strip_prefix": "libpng-1.2.53",
        "urls": [
#            "https://freefr.dl.sourceforge.net/project/libpng/libpng16/1.6.37/libpng-1.6.37.tar.gz",
            "https://freefr.dl.sourceforge.net/project/libpng/libpng16/1.6.35/libpng-1.6.35.tar.gz",
            "https://github.com/glennrp/libpng/archive/v1.6.35.tar.gz",
        ],
    },


    "com_googlesource_code_cctz": {
        #"build_file": "@io_rules_sdlc//third_party:png.BUILD",
        #"sha256": "todo",
        "strip_prefix" : "cctz-master",
        "urls": ["https://github.com/google/cctz/archive/master.zip"],
    },

}

dependencies_repositories = {

    "com_google_absl": {
        #"build_file": "@io_rules_sdlc//third_party:png.BUILD",
        "commit" : "df3ea785d8c30a9503321a3d35ee7d35808f190d",  # LTS 2020-02-25
        "remote" : "https://github.com/abseil/abseil-cpp.git",
        "shallow_since" : "1583355457 -0500"
    },

    "com_github_gflags_gflags": {
        "commit":"addd749114fab4f24b7ea1e0f2f837584389e52c",
        "remote": "https://github.com/gflags/gflags",
    },

    "bazel_compilation_database": {
        #"commit":"addd749114fab4f24b7ea1e0f2f837584389e52c",
        "remote": "https://github.com/grailbio/bazel-compilation-database.git",
        "tag" : "0.4.1",
    },
}

def _archives_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_archives:
        if name not in ignores:
            maybe(http_archive, name, **dependencies_archives[name])

def _git_repo_deps(excludes = []):
    ignores = native.existing_rules().keys() + excludes
    for name in dependencies_archives:
        if name not in ignores:
            maybe(git_repository, name, **dependencies_repositories[name])

def rules_sdlc_dependencies():
    _archives_deps()
    _git_repo_deps()






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
