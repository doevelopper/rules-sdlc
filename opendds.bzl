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

