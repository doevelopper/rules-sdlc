load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "git_repository"
)

load(
    "@bazel_tools//tools/build_defs/repo:http.bzl",
    "http_archive"
)

BAZEL_TOOLCHAIN_TAG = "0.8.2"
BAZEL_TOOLCHAIN_SHA = "0fc3a2b0c9c929920f4bed8f2b446a8274cad41f5ee823fd3faa0d7641f20db0"

LLVM_COMMIT = "499bce3abab8a362b9b4197944bd40b826c736c4"
LLVM_BAZEL_TAG = "llvm-project-%s" % (LLVM_COMMIT,)
LLVM_BAZEL_SHA256 = "a05a83300b6b4d8b45c9ba48296c06217f3ea27ed06b7e698896b5a3b2ed498d"
LLVM_SHA256 = "a154965dfeb2b5963acc2193bc334ce90b314acbe48430ba310d8a7c7a20de8b"
def cc_bdd_deps():
    if "com_grail_bazel_toolchain" not in native.existing_rules():

        http_archive(
            name = "com_grail_bazel_toolchain",
            sha256 = BAZEL_TOOLCHAIN_SHA,
            strip_prefix = "bazel-toolchain-{tag}".format(tag = BAZEL_TOOLCHAIN_TAG),
            canonical_id = BAZEL_TOOLCHAIN_TAG,
            url = "https://github.com/grailbio/bazel-toolchain/archive/refs/tags/{tag}.tar.gz".format(tag = BAZEL_TOOLCHAIN_TAG),
        )

        http_archive(
            name = "llvm-bazel",
            sha256 = LLVM_BAZEL_SHA256,
            strip_prefix = "llvm-bazel-{tag}/llvm-bazel".format(tag = LLVM_BAZEL_TAG),
            url = "https://github.com/google/llvm-bazel/archive/{tag}.tar.gz".format(tag = LLVM_BAZEL_TAG),
        )

        http_archive(
            name = "llvm-project-raw",
            build_file_content = "#empty",
            sha256 = LLVM_SHA256,
            strip_prefix = "llvm-project-" + LLVM_COMMIT,
            urls = [
                "https://storage.googleapis.com/mirror.tensorflow.org/github.com/llvm/llvm-project/archive/{commit}.tar.gz".format(commit = LLVM_COMMIT),
                "https://github.com/llvm/llvm-project/archive/{commit}.tar.gz".format(commit = LLVM_COMMIT),
            ]
        )

def enable_build_cpp_compiler_selection():

    load("@com_grail_bazel_toolchain//toolchain:deps.bzl", "bazel_toolchain_dependencies")
    bazel_toolchain_dependencies()
    load("@com_grail_bazel_toolchain//toolchain:rules.bzl", "llvm_toolchain")

    llvm_toolchain(
        name = "llvm_toolchain",
        llvm_version = "15.0.6",
    )

    load("@llvm_toolchain//:toolchains.bzl", "llvm_register_toolchains")
    llvm_register_toolchains()

def aspect_build_cpp_compiler_selection():
