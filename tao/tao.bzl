
def _file_name(filePathName):
    if '/' in filePathName:
        return filePathName.rsplit('/', -1)[1]
    else:
        return filePathName

def _base_name(fileName):
    return fileName.split('.')[0]


def tao_idl_gen(name, src, **kwargs):
    """Compile IDL sources for use with the ACE ORB (TAO)

    Both clients and servers should link against the object files for the stubs and skeletons,
    this is needed to transparently support collocated objects.
    """

    for idl in src:
        base_name = _base_name(_file_name(idl))
        native.genrule(
            name = base_name ,
            srcs = [idl],
            outs = [ "%C.cpp" % base_name,
                 "%C.h" % base_name,
                 "%C.inl" % base_name,
                 "%S.cpp" % base_name,
                 "%S.h" % base_name,
            ],
            cmd = "/opt/dds/opendds/bin/tao_idl $@ -o $(GENDIR)/cfs/com",
        **kwargs
    )
"""
 cmd = "tao_idl -Wb,pre_include=$(ACE_ROOT)/ace/pre.h -Wb,post_include=$(ACE_ROOT)/ace/post.h -I$(TAO_ROOT) -Sa -St -I$(DDS_ROOT) $@ -o $(GENDIR)/cfs/com",
#       cmd = "./$(location create_foo.pl) > \"$@\"",
#        cmd = "cat $(locations //some:files) $(location //other:gen) > $@",
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

