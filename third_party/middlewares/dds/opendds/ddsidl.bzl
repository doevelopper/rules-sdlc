
def tao_idl_gen(name, src, **kwargs):
    """Compile IDL sources for use with the ACE ORB (TAO)

    Both clients and servers should link against the object files for the stubs and skeletons,
    this is needed to transparently support collocated objects.
    """

    native.genrule(
        name = name,
        srcs = [src],
        outs = ["small_" + src],
        cmd = "tao_idl -Wb,pre_include=$(ACE_ROOT)/ace/pre.h -Wb,post_include=$(ACE_ROOT)/ace/post.h -I$(TAO_ROOT) -Sa -St -I$(DDS_ROOT) $@ -o $(GENDIR)/cfs/arkhe/gcs",
#        cmd = "./$(location create_foo.pl) > \"$@\"",
#        cmd = "cat $(locations //some:files) $(location //other:gen) > $@",
        **kwargs
    )


def opendds_idl_gen(name, src, **kwargs):
    native.genrule(
        name = name,
        srcs = [src],
        outs = ["small_" + src],
        cmd = "opendds_idl -Sa -St $@ -o $(GEN_DIR)",
    )

def TypeSupport_idl_gen(name, src, **kwargs):
    native.genrule(
        name = name,
        srcs = [src],
        outs = ["small_" + src],
        cmd = "tao_idl -Wb,pre_include=$(ACE_ROOT)/ace/pre.h -Wb,post_include=$(ACE_ROOT)/ace/post.h -I$(TAO_ROOT) -Sa -St -I$(DDS_ROOT) $(GEN_DIR)/*TypeSupport.idl -o $(GEN_DIR) $(TAO_INCLUDES)"
    )

"""
load("//src/main/resources/bazel:ddsidl.bzl", "tao_idl_gen")

tao_idl_gen(
    name = "idl_generated",
    src = "sensors.idl",
)

cc_binary(
    name = "idl_generated",
    srcs = ["my_app.cc"],
    data = [":logo_miniature"],
)
"""
