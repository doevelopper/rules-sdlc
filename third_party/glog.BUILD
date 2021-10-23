
cc_library(
    name = "glog",
    hdrs = glob(["glog/*.h"]),
    includes = ["."],
    linkopts = [
        "-L/usr/local/lib/ -lglog",
    ],
    visibility = ["//visibility:public"],
    deps = ["@//:gflags"],
)

