
cc_library(
    name = "ace",
    hdrs = glob([
        "/usr/local/include/ace/**/*.h"
        "/usr/local/include/ace/**/*.inl"
    ]),

    srcs = [
        "libACE.so",
        "libACE_SSL.so",
    ],

    linkopts = [
        "-lrt",
        "-lpthread",
    ],
    visibility = ["//visibility:public"],
)

