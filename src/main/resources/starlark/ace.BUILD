cc_library(
    name = "ace",
    srcs = [
        "libACE.so",
        "libACE_SSL.so",
    ],
    hdrs = glob([
        "/usr/local/include/ace/**/*.h",
        "/usr/local/include/ace/**/*.inl",
    ]),
    linkopts = [
        "-lrt",
        "-lpthread",
    ],
    visibility = ["//visibility:public"],
)
