# https://bazel.build/extending/rules#actions
# https://bazel.build/rules/lib/actions

def _is_windows():
    return select({
        "@bazel_tools//src/conditions:windows": True,
        "//conditions:default": False,
    })

def _GetPath(ctx, path):
    if ctx.label.workspace_root:
        return ctx.label.workspace_root + "/" + path
    else:
        return path

def _SourceDir(ctx):
    if not ctx.attr.idls:
        return ctx.label.workspace_root
    if not ctx.attr.idls[0]:
        return _GetPath(ctx, ctx.label.package)
    if not ctx.label.package:
        return _GetPath(ctx, ctx.attr.idls[0])
    return _GetPath(ctx, ctx.label.package + "/" + ctx.attr.idls[0])

def _generate_idl2cpp(ctx):
    full_outdir = ctx.bin_dir.path + "/"
    if ctx.label.workspace_root:
        full_outdir += ctx.label.workspace_root + "/"
    if ctx.label.package:
        full_outdir += ctx.label.package + "/"

    # full_outdir += ctx.label.name
    print("IDL root apout dir {} ".format(full_outdir))
    print("ctx.attr.idls[0] {} ".format(ctx.attr.idls[0]))
    print("ctx.label.package {} ".format(ctx.label.package))
    print("ctx.build_file_path {} ".format(ctx.build_file_path))

    files = []

    for idl_file in ctx.files.idls:
        idl_file_path = idl_file.path.split("/idl/")[1].rpartition("/")[0]
        print("idl file path: {} ".format(idl_file_path))
        print("ctx.genfiles_dir.path: {} ".format(ctx.genfiles_dir.path))

        file_name = idl_file.path[0:-len(idl_file.extension) - 1]

        print("File name: {} ".format(file_name))
        file_base_name = idl_file.basename[0:-len(idl_file.extension) - 1]
        print("File: {} ".format(file_base_name))

        full_outdir += idl_file_path
        print("IDL output dir {} ".format(full_outdir))

        otschdr = ctx.actions.declare_file("{}/{}C.h".format(idl_file_path, file_base_name))
        otsidl = ctx.actions.declare_file("{}/{}TypeSupport.idl".format(idl_file_path, file_base_name))
        otshdr = ctx.actions.declare_file("{}/{}TypeSupportImpl.h".format(idl_file_path, file_base_name))
        otssrc = ctx.actions.declare_file("{}/{}TypeSupportImpl.cpp".format(idl_file_path, file_base_name))
        files.append(otschdr)
        files.append(otsidl)
        files.append(otshdr)
        files.append(otssrc)

        opendds_args = ctx.actions.args()
        opendds_args.add("-Sa")
        opendds_args.add("-St")
        opendds_args.add("-Cw")
        opendds_args.add("-Lc++11")
        opendds_args.add("-Lspcpp")
        opendds_args.add(idl_file)
        opendds_args.add("--idl-version")
        opendds_args.add("4")
        opendds_args.add("-v")
        opendds_args.add("--unknown-annotations")
        opendds_args.add("ignore")
        opendds_args.add("-o")
        opendds_args.add(full_outdir)


        hdrinl = ctx.actions.declare_file("{}/{}Client.inl".format(idl_file_path, file_base_name))
        clthdr = ctx.actions.declare_file("{}/{}Client.hpp".format(idl_file_path, file_base_name))
        cltsrc = ctx.actions.declare_file("{}/{}Client.cpp".format(idl_file_path, file_base_name))
        srvhdr = ctx.actions.declare_file("{}/{}Server.hpp".format(idl_file_path, file_base_name))
        srvsrc = ctx.actions.declare_file("{}/{}Server.cpp".format(idl_file_path, file_base_name))
        files.append(hdrinl)
        files.append(clthdr)
        files.append(cltsrc)
        files.append(srvhdr)
        files.append(srvsrc)

        tao_idl_in_args = ctx.actions.args()
        tao_idl_in_args.add(idl_file)
        tao_idl_in_args.add("-in")
        tao_idl_in_args.add("-Sa")
        tao_idl_in_args.add("-St")
        tao_idl_in_args.add("--idl-version")
        tao_idl_in_args.add("4")
        tao_idl_in_args.add("--unknown-annotations")
        tao_idl_in_args.add("ignore")
        tao_idl_in_args.add("-ae")
        tao_idl_in_args.add("-GC")
        tao_idl_in_args.add("-Sg")
        tao_idl_in_args.add("-TS 4")
        tao_idl_in_args.add("-Wb,pre_include=ace/pre.h")
        tao_idl_in_args.add("-Wb,post_include=ace/post.h")
        tao_idl_in_args.add("-I{}".format(full_outdir))
        tao_idl_in_args.add("-ci")
        tao_idl_in_args.add("Client.inl")
        tao_idl_in_args.add("-hc")
        tao_idl_in_args.add("Client.hpp")
        tao_idl_in_args.add("-cs")
        tao_idl_in_args.add("Client.cpp")
        tao_idl_in_args.add("-hs")
        tao_idl_in_args.add("Server.hpp")
        tao_idl_in_args.add("-ss")
        tao_idl_in_args.add("Server.cpp")
        tao_idl_in_args.add("-hT")
        tao_idl_in_args.add("ServerTemplateSkeleton.hpp")
        tao_idl_in_args.add("-sT")
        tao_idl_in_args.add("ServerTemplateSkeleton.cpp")
        tao_idl_in_args.add("-o")
        tao_idl_in_args.add(full_outdir)

        ctx.actions.run(
            outputs = [
                hdrinl,
                clthdr,
                cltsrc,
                srvhdr,
                srvsrc,
            ],
            inputs = [idl_file],
            unused_inputs_list = None,
            executable = "tao_idl",
            arguments = [tao_idl_in_args],
            progress_message = "TAO IDL: Generating srs  from {} in folder {}".format(idl_file, full_outdir),
            use_default_shell_env = True,
            env = ctx.attr.env,
            execution_requirements = None,
            input_manifests = None,
        )

        typesupport_idl = "{}/{}TypeSupport.idl".format(full_outdir, file_base_name)
        print("TypeSupport idl: {} ".format(typesupport_idl))

        ts_hdr_inl = ctx.actions.declare_file("{}/{}TypeSupportClient.inl".format(idl_file_path, file_base_name))
        ts_clt_hdr = ctx.actions.declare_file("{}/{}TypeSupportClient.hpp".format(idl_file_path, file_base_name))
        ts_clt_src = ctx.actions.declare_file("{}/{}TypeSupportClient.cpp".format(idl_file_path, file_base_name))
        ts_srv_hdr = ctx.actions.declare_file("{}/{}TypeSupportServer.hpp".format(idl_file_path, file_base_name))
        ts_srv_src = ctx.actions.declare_file("{}/{}TypeSupportServer.cpp".format(idl_file_path, file_base_name))

        files.append(ts_hdr_inl)
        files.append(ts_clt_hdr)
        files.append(ts_clt_src)
        files.append(ts_srv_hdr)
        files.append(ts_srv_src)

        tao_idl_out_args = ctx.actions.args()
        tao_idl_out_args.add(typesupport_idl)
        tao_idl_out_args.add("-in")
        tao_idl_out_args.add("-Sa")
        tao_idl_out_args.add("-St")
        tao_idl_out_args.add("--idl-version")
        tao_idl_out_args.add("4")
        tao_idl_out_args.add("--unknown-annotations")
        tao_idl_out_args.add("ignore")
        tao_idl_out_args.add("-ae")
        tao_idl_out_args.add("-GC")
        tao_idl_out_args.add("-Sg")
        tao_idl_out_args.add("-TS 4")
        tao_idl_out_args.add("-Wb,pre_include=ace/pre.h")
        tao_idl_out_args.add("-Wb,post_include=ace/post.h")

        #  tao_idl_out_args.add("-I{}".format(ACE_ROOT))
        #  tao_idl_out_args.add("-I{}".format(TAO_ROOT))
        #  tao_idl_out_args.add("-I{}".format(DDS_ROOT))
        tao_idl_out_args.add("-I{}/{}".format(ctx.label.package, idl_file_path))  # IDL source folder
        tao_idl_out_args.add("-I{}".format(full_outdir))
        tao_idl_out_args.add("-ci")
        tao_idl_out_args.add("Client.inl")
        tao_idl_out_args.add("-hc")
        tao_idl_out_args.add("Client.hpp")
        tao_idl_out_args.add("-cs")
        tao_idl_out_args.add("Client.cpp")
        tao_idl_out_args.add("-hs")
        tao_idl_out_args.add("Server.hpp")
        tao_idl_out_args.add("-ss")
        tao_idl_out_args.add("Server.cpp")
        tao_idl_out_args.add("-hT")
        tao_idl_out_args.add("ServerTemplateSkeleton.hpp")
        tao_idl_out_args.add("-sT")
        tao_idl_out_args.add("ServerTemplateSkeleton.cpp")
        tao_idl_out_args.add("-o")
        tao_idl_out_args.add(full_outdir)

        ctx.actions.run(
            outputs = [
                ts_hdr_inl,
                ts_clt_hdr,
                ts_clt_src,
                ts_srv_hdr,
                ts_srv_src,
            ],
            # inputs=[typesupport_idl],
            inputs = [otsidl],
            unused_inputs_list = None,
            executable = "tao_idl",
            arguments = [tao_idl_out_args],
            progress_message = "TAO IDL: Generating type support srs  from {} in folder {}".format(otsidl, full_outdir),
            use_default_shell_env = True,
            env = ctx.attr.env,
            execution_requirements = None,
            input_manifests = None,
        )

        # return [DefaultInfo(files = depset(files))]

generate_idl2cpp = rule(
    attrs = {
        "idls": attr.label_list(
            allow_files = [".idl"],
            doc = "The .IDL files to generate to c++.",
        ),
        "env": attr.string_dict(),
        "gen_tao_idl2cpp": attr.bool(),
        "gen_opendds_idl2cpp": attr.bool(),
        "gen_fatsrtps_idl2cpp": attr.bool(),
        "gen_connex_dds_idl2cpp": attr.bool(),
        "gen_vortex_dds_idl2cpp": attr.bool(),
    },
    output_to_genfiles = True,
    implementation = _generate_idl2cpp,
)
