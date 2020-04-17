
load(
    "//src/main/resources/bazel:copts.bzl",
    "GCC_FLAGS",
    "GCC_TEST_FLAGS",
    "WERROR",
)

DEFAULT_COPTS = select({
    "//conditions:default": GCC_FLAGS,
})

# in absence of modules (--compiler=gcc or -c opt), cc_tests leak their copts
# to their (included header) dependencies and fail to build outside absl
TEST_COPTS = DEFAULT_COPTS + select({
    "//conditions:default": GCC_TEST_FLAGS,
})

DEFAULT_LINKOPTS = select({
    "//conditions:default": [],
})


