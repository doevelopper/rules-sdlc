# Thanks to https://stackoverflow.com/questions/49937820/include-headers-h-installed-in-non-standard-location

package(
    default_visibility = ["//visibility:public"]
)

cc_library(
    name = "ace_tao_opendds",
    srcs = [
        "/opt/dds/opendds/lib/libACE.so",
        "/opt/dds/opendds/lib/tao_java.jar",
        "/opt/dds/opendds/lib/OpenDDS_DCPS.jar",
        "/opt/dds/opendds/lib/i2jrt.jar",
        "/opt/dds/opendds/lib/libACE.so",
        "/opt/dds/opendds/lib/libACE_XML_Utils.so",
        "/opt/dds/opendds/lib/libOpenDDS_DCPS_Java.so",
        "/opt/dds/opendds/lib/libOpenDDS_Dcps.so",
        "/opt/dds/opendds/lib/libOpenDDS_FACE.so",
        "/opt/dds/opendds/lib/libOpenDDS_Federator.so",
        "/opt/dds/opendds/lib/libOpenDDS_InfoRepoDiscovery.so",
        "/opt/dds/opendds/lib/libOpenDDS_InfoRepoLib.so",
        "/opt/dds/opendds/lib/libOpenDDS_InfoRepoServ.so",
        "/opt/dds/opendds/lib/libOpenDDS_Model.so",
        "/opt/dds/opendds/lib/libOpenDDS_Multicast.so",
        "/opt/dds/opendds/lib/libOpenDDS_QOS_XML_XSC_Handler.so",
        "/opt/dds/opendds/lib/libOpenDDS_Rtps.so",
        "/opt/dds/opendds/lib/libOpenDDS_RtpsRelay.so",
        "/opt/dds/opendds/lib/libOpenDDS_Rtps_Udp.so",
        "/opt/dds/opendds/lib/libOpenDDS_Security.so",
        "/opt/dds/opendds/lib/libOpenDDS_Shmem.so",
        "/opt/dds/opendds/lib/libOpenDDS_Tcp.so",
        "/opt/dds/opendds/lib/libOpenDDS_Udp.so",
        "/opt/dds/opendds/lib/libOpenDDS_monitor.so",
        "/opt/dds/opendds/lib/libTAO.so",
        "/opt/dds/opendds/lib/libTAO_AnyTypeCode.so",
        "/opt/dds/opendds/lib/libTAO_Async_IORTable.so",
        "/opt/dds/opendds/lib/libTAO_BiDirGIOP.so",
        "/opt/dds/opendds/lib/libTAO_CSD_Framework.so",
        "/opt/dds/opendds/lib/libTAO_CSD_ThreadPool.so",
        "/opt/dds/opendds/lib/libTAO_CodecFactory.so",
        "/opt/dds/opendds/lib/libTAO_Codeset.so",
        "/opt/dds/opendds/lib/libTAO_DynamicInterface.so",
        "/opt/dds/opendds/lib/libTAO_IDL_BE.so",
        "/opt/dds/opendds/lib/libTAO_IDL_FE.so",
        "/opt/dds/opendds/lib/libTAO_IORManip.so",
        "/opt/dds/opendds/lib/libTAO_IORTable.so",
        "/opt/dds/opendds/lib/libTAO_ImR_Client.so",
        "/opt/dds/opendds/lib/libTAO_Messaging.so",
        "/opt/dds/opendds/lib/libTAO_PI.so",
        "/opt/dds/opendds/lib/libTAO_PortableServer.so",
        "/opt/dds/opendds/lib/libTAO_Svc_Utils.so",
        "/opt/dds/opendds/lib/libTAO_Valuetype.so",
        "/opt/dds/opendds/lib/libidl2jni_runtime.so",
        "/opt/dds/opendds/lib/libtao_java.so",
    ],

    hdrs = glob([
        "/opt/dds/opendds/include/**/*.h",
        "/opt/dds/opendds/include/**/*.hpp",
    ]),

    includes = ["/opt/dds/opendds/include/"],

)

