IDL_GENERIC_OPTS = select({
    "//conditions:default": [
        "--unknown-annotations ignore",
        "--idl-version 4",
        "-Sa",
        "-St",
    ],
})

TAO_IDL_OPTS = select({
    "//conditions:default": [
        "-Wb,pre_include=ace/pre.h",
        "-Wb,post_include=ace/post.h",
        "-I$$TAO_ROOT",
        "-I$$DDS_ROOT",
        "-I$$ACE_ROOT",
        "-in",
        "-Gstl",
        "-hc Client.hpp",
        "-ss Server.cpp",
        "-hs Server.hpp",
        "-cs Client.cpp",
        "-hT ServerTemplateSkeleton.hpp",
        "-sT ServerTemplateSkeleton.cpp",
    ],
})

OPENDDS_IDL_OPTS = select({
    "//conditions:default": [
        "-Sa",
        "-St",
        "-Lc++11",
        "-Lspcpp",
        "-Cw",
        "--idl-version 4",
        "-v",
        "--unknown-annotations ignore",
    ],
})

IDL_OPTS = select({
    "//conditions:default": [
        "-Wb,pre_include=ace/pre.h",
        "-Wb,post_include=ace/post.h",
        "--unknown-annotations ignore",
        "-I$$TAO_ROOT",
        "-I$$DDS_ROOT",
        "-I$$ACE_ROOT",
        "-in",
        "-Gstl",
        "-hc Client.hpp",
        "-ss Server.cpp",
        "-hs Server.hpp",
        "-cs Client.cpp",
        "-hT ServerTemplateSkeleton.hpp",
        "-sT ServerTemplateSkeleton.cpp",
        "--idl-version 4",
        "-Sa",
        "-St",
		"-Sg",
		"-TS 4",
    ],
})

def _generate_idl2cpp(ctx):

    idl_output_dir = ctx.bin_dir.path + "/"
    if ctx.label.workspace_root:
        idl_output_dir += ctx.label.workspace_root + "/"
    if ctx.label.package:
        idl_output_dir += ctx.label.package + "/"

        tao_idl_args = ctx.actions.args()
		#tao_idl_args += [d for d in f.TAO_IDL_OPTS]
        #  tao_idl_args.add("-I{}".format(ACE_ROOT))
        #  tao_idl_args.add("-I{}".format(TAO_ROOT))
        #  tao_idl_args.add("-I{}".format(DDS_ROOT))
        tao_idl_args.add("-in")
        tao_idl_args.add("-Sa")
        tao_idl_args.add("-St")
        tao_idl_args.add("--idl-version")
        tao_idl_args.add("4")
        tao_idl_args.add("--unknown-annotations")
        tao_idl_args.add("ignore")
        tao_idl_args.add("-ae")
        tao_idl_args.add("-GC")
		tao_idl_args.add("-Sg")
		tao_idl_args.add("-TS 4")
        tao_idl_args.add("-Wb,pre_include=ace/pre.h")
        tao_idl_args.add("-Wb,post_include=ace/post.h")
        tao_idl_args.add("-ci")
        tao_idl_args.add("Client.inl")
        tao_idl_args.add("-hc")
        tao_idl_args.add("Client.hpp")
        tao_idl_args.add("-cs")
        tao_idl_args.add("Client.cpp")
        tao_idl_args.add("-hs")
        tao_idl_args.add("Server.hpp")
        tao_idl_args.add("-ss")
        tao_idl_args.add("Server.cpp")
        tao_idl_args.add("-hT")
        tao_idl_args.add("ServerTemplateSkeleton.hpp")
        tao_idl_args.add("-sT")
        tao_idl_args.add("ServerTemplateSkeleton.cpp")

    files = []
    for idl_file in ctx.files.idls:
        idl_file_path = idl_file.path.split("/idl/")[1].rpartition("/")[0]
        file_name = idl_file.path[0:-len(idl_file.extension) - 1]
        file_base_name = idl_file.basename[0:-len(idl_file.extension) - 1]
        idl_output_dir += idl_file_path
        tao_hdr_inl = ctx.actions.declare_file("{}/{}Client.inl".format(idl_file_path, file_base_name))
        tao_clt_hdr = ctx.actions.declare_file("{}/{}Client.hpp".format(idl_file_path, file_base_name))
        tao_clt_src = ctx.actions.declare_file("{}/{}Client.cpp".format(idl_file_path, file_base_name))
        tao_srv_hdr = ctx.actions.declare_file("{}/{}Server.hpp".format(idl_file_path, file_base_name))
        tao_srv_src = ctx.actions.declare_file("{}/{}Server.cpp".format(idl_file_path, file_base_name))
        files.append(tao_hdr_inl)
        files.append(tao_clt_hdr)
        files.append(tao_clt_src)
        files.append(tao_srv_hdr)
        files.append(tao_srv_src)
        tao_idl_args.add(idl_file)
        tao_idl_args.add("-I{}".format(idl_output_dir))
        tao_idl_args.add("-o")
        tao_idl_args.add(idl_output_dir)
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
            executable = ctx.executable._tao_idl_bin,
            arguments = [tao_idl_args],
            progress_message = "TAO IDL: Generating srs  from {} in folder {}".format(idl_file, idl_output_dir),
            use_default_shell_env = True,
            env = ctx.attr.env,
            execution_requirements = None,
            input_manifests = None,
        )
        generated_typesupport_idl = "{}/{}TypeSupport.idl".format(idl_output_dir, file_base_name)
        if ctx.attr.is_type_support_idl and generated_typesupport_idl.exists:
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
			tao_idl_args.add(generated_typesupport_idl)
			tao_idl_args.add("-I{}/{}".format(ctx.label.package, idl_file_path))
            ctx.actions.run(
                outputs = [
                    ts_hdr_inl,
                    ts_clt_hdr,
                    ts_clt_src,
                    ts_srv_hdr,
                    ts_srv_src,
                ],
                inputs = [generated_typesupport_idl],
                unused_inputs_list = None,
                executable = ctx.executable._tao_idl_bin,
                arguments = [tao_idl_args],
                progress_message = "TAO IDL: Generating Type Support srcs  from {} in folder {}".format(generated_typesupport_idl, idl_output_dir),
                use_default_shell_env = True,
                env = ctx.attr.env,
                execution_requirements = None,
                input_manifests = None,
            )
    return [DefaultInfo(files = depset(files))]

tao_idl2cpp = rule(
    attrs = {
        "idls": attr.label_list(
            allow_files = [".idl"],
            doc = "The .IDL files to generate to c++.",
        ),
        "env": attr.string_dict(),
        "_tao_idl_bin": attr.label(
            executable = True,
            cfg = "host",
            default = Label("@io_rules_sdlc//middlewares:tao_idl_bin"),
            # default = None if is_windows else Label("@io_rules_sdlc//middlewares:tao_idl_bin"),
        ),
        "is_type_support_idl": attr.bool(),
    },
    # outputs = {
    # "clthdr": "%{name}Client.hpp",
    # "clthdr": "{}Client.hpp".format(basename)),
    # "cltsrc": "{}Client.cpp".format(basename)),
    # "srvhdr": "{}Server.hpp".format(basename)),
    # "srvsrc": "{}Server.cpp".format(basename)),
    # "skelhdr": "{}ServerTemplateSkeleton.hpp".format(basename)),
    # "skelsrc": "{}ServerTemplateSkeleton.cpp".format(basename)),
    # },
    output_to_genfiles = True,

    implementation = _generate_idl2cpp,
)

