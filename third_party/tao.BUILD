

cc_library(
    name = "tao",
    hdrs = glob([
        "/usr/local/include/tao/**/*.h"
        "/usr/local/include/tao/**/*.inl"
    ]),

    srcs = [
        "libTAO.so",
        "libTAO_AnyTypeCode.so",
        "TAO_IORManip",
        "TAO_ImR_Client",
        "TAO_Svc_Utils",
        "TAO_IORTable",
        "TAO_IDL_FE",
        "TAO_PortableServer",
        "TAO_BiDirGIOP",
        "TAO_PI",
        "TAO_CodecFactory",
        "TAO_AnyTypeCode",
    ],

    linkopts = [
       "-lrt",
       "-lpthread",
    ],
    visibility = ["//visibility:public"],
)

