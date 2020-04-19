
workspace(
    name = "io_rules_sdlc"
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

load("@io_rules_sdlc//configs:version.bzl","MAX_VERSION", "MIN_VERSION", "check_version",)
check_version(MIN_VERSION, MAX_VERSION)

load("@io_rules_sdlc//repos:sw_dev.bzl","dev_repositories")
dev_repositories()

load("@io_rules_sdlc//repos:sw_qa.bzl","qa_repositories")
qa_repositories()

load("@io_rules_sdlc//repos:dependencies.bzl","dependencies_repositories")
dependencies_repositories()


load("@io_rules_sdlc//utils:pkg_config.bzl", "pkg_config_repository")

#load("@io_rules_sdlc//repos:local.bzl","usr_local_bin_repository")
#usr_local_bin_repository()

new_local_repository(
    name = "usr_local",
    path = "/usr/local",
    build_file = "@io_rules_sdlc//third_party:BUILD.opendds",
)

#load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")

#buildifier(
#    name = "buildifier",
#)
