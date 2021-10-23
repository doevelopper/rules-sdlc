# https://docs.bazel.build/versions/master/skylark/rules.html#actions
# https://docs.bazel.build/versions/master/skylark/lib/actions.html

TAO_IDL_BIN = select({
    "//conditions:default": "@io_rules_sdlc//:tao-idl-bin",
})

OPENDDS_IDL_BIN = select({
    "//conditions:default": "@io_rules_sdlc//:opendds-idl-bin",
})

JAVA_IDL_BIN = select({
    "//conditions:default": "@io_rules_sdlc//:idl-2-jni",
})

ACE_PERF_BIN = select({
    "//conditions:default": "@io_rules_sdlc//:ace-perf",
})

IDL_GENERIC_OPTS = select({
    "//conditions:default": [
        "--unknown-annotations ignore",
        "--idl-version 4",
        "-Sa",
        "-St",
    ],
})

TAO_IDL_OPTS = IDL_GENERIC_OPTS + select({
    "//conditions:default": [
        "-Wb,pre_include=ace/pre.h",
        "-Wb,post_include=ace/post.h",
        "-I$$TAO_ROOT",
        "-I$$DDS_ROOT",
        "-I$$ACE_ROOT",
        "-Sg",
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

OPENDDS_IDL_OPTS = IDL_GENERIC_OPTS + select({
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
    ],
})

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

def _IsNewExternal(ctx):
    # Bazel 0.4.4 and older have genfiles paths that look like:
    #   bazel-out/local-fastbuild/genfiles/external/repo/foo
    # After the exec root rearrangement, they look like:
    #   ../repo/bazel-out/local-fastbuild/genfiles/foo
    return ctx.label.workspace_root.startswith("../")

def _GenDir(ctx):
    if _IsNewExternal(ctx):
        # We are using the fact that Bazel 0.4.4+ provides repository-relative paths
        # for ctx.genfiles_dir.
        return ctx.genfiles_dir.path + ("/" + ctx.attr.idls[0] if ctx.attr.idls and ctx.attr.idls[0] else "")

    # This means that we're either in the old version OR the new version in the local repo.
    # Either way, appending the source path to the genfiles dir works.
    return ctx.var["GENDIR"] + "/" + _SourceDir(ctx)

def _SourceDir(ctx):
    if not ctx.attr.idls:
        return ctx.label.workspace_root
    if not ctx.attr.idls[0]:
        return _GetPath(ctx, ctx.label.package)
    if not ctx.label.package:
        return _GetPath(ctx, ctx.attr.idls[0])
    return _GetPath(ctx, ctx.label.package + "/" + ctx.attr.idls[0])

def idl_library(name, idls, **kwargs):
    if len(idls) > 1:
        fail("Only one idls value supported", "idls")

    codegen_idl_target = "_" + name + "_idl_codegen"

    generate_idl2cpp(
        name = codegen_idl_target,
        idls = idls,
        env = select({
            # "//toolchain:windows_x86_64": {},
            "//conditions:default": {
                #                "PATH": "external/com_intel_plaidml_conda_unix/env/bin"
                "ACE_ROOT": "/usr/local/share/ace",
                "TAO_ROOT": "/usr/local/share/tao",
                "DDS_ROOT": "/usr/local/share/dds",
                "CIAO_ROOT": "/usr/local/share/ciao",
                "DANCE_ROOT": "/usr/local/share/dance",
                "LD_LIBRARY_PATH": " $LD_LIBRARY_PATH:/usr/local/lib/:/opt/dds/opendds/lib",
                "CPATH": "$CPATH:/opt/dds/opendds/include:/usr/local/include",
                "BOOST_ROOT": "/usr/local",
                "GLIB_ROOT": "/usr",
                "XERCESCROOT": "/usr/local",
                "PROTOBUF_HOME": "/usr/local",
                "SSL_ROOT": "/usr/local",
            },
        }),
        **kwargs
    )

    native.cc_library(
        name = name,
        # srcs = [":" + codegen_idl_target],
        hdrs = [":" + codegen_idl_target],
        **kwargs
    )

def _use_tao_idl_4_generate_idl2cpp(ctx, from_typesupport_idl):
    pass

def _use_opendds_idl_4_generate_idl2cpp(ctx):
    pass

def _generate_idl2cpp(ctx):
    full_outdir = ctx.bin_dir.path + "/"
    if ctx.label.workspace_root:
        full_outdir += ctx.label.workspace_root + "/"
    if ctx.label.package:
        full_outdir += ctx.label.package + "/"

    # full_outdir += ctx.label.name
    # print("IDL root apout dir {} ".format(full_outdir))
    # print("ctx.attr.idls[0] {} ".format(ctx.attr.idls[0]))
    # print("ctx.label.package {} ".format(ctx.label.package))
    # print("ctx.build_file_path {} ".format(ctx.build_file_path))

    files = []

    for idl_file in ctx.files.idls:
        idl_file_path = idl_file.path.split("/idl/")[1].rpartition("/")[0]
        # print("idl file path: {} ".format(idl_file_path))
        # print("ctx.genfiles_dir.path: {} ".format(ctx.genfiles_dir.path))

        file_name = idl_file.path[0:-len(idl_file.extension) - 1]

        # print("File name: {} ".format(file_name))
        file_base_name = idl_file.basename[0:-len(idl_file.extension) - 1]
        # print("File: {} ".format(file_base_name))

        full_outdir += idl_file_path
        # print("IDL output dir {} ".format(full_outdir))

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

        # ctx.actions.run_shell(
        # outputs = [
        # otschdr,
        # otsidl,
        # otshdr,
        # otssrc
        # ],
        # inputs=[idl_file],
        # arguments = [opendds_args],
        # command = "opendds_idl",
        # progress_message = "OpendDDS IDL Generating srs from {} \n in folder {}".format(idl_file,full_outdir), #"Packing " + ctx.label.package + ":" + ctx.label.name,
        # use_default_shell_env=True,
        # env = ctx.attr.env,
        # execution_requirements=None,
        # input_manifests=None
        # )

        ctx.actions.run(
            outputs = [
                otschdr,
                otsidl,
                otshdr,
                otssrc,
            ],
            inputs = [idl_file],
            unused_inputs_list = None,
            executable = "opendds_idl",
            arguments = [opendds_args],
            progress_message = "OpendDDS IDL Generating srs from {} \n in folder {}".format(idl_file, full_outdir),  #"Packing " + ctx.label.package + ":" + ctx.label.name,
            use_default_shell_env = True,
            env = ctx.attr.env,
            execution_requirements = None,
            input_manifests = None,
        )

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
        # print("TypeSupport idl: {} ".format(typesupport_idl))

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
        tao_idl_out_args.add("-Wb,pre_include=ace/pre.h")
        tao_idl_out_args.add("-Wb,post_include=ace/post.h")

        #  tao_idl_in_args.add("-I{}".format(ACE_ROOT))
        #  tao_idl_in_args.add("-I{}".format(TAO_ROOT))
        #  tao_idl_in_args.add("-I{}".format(DDS_ROOT))
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

        return [DefaultInfo(files = depset(files))]

generate_idl2cpp = rule(
    attrs = {
        "idls": attr.label_list(
            allow_files = [".idl"],
            doc = "The .IDL files to generate to c++.",
        ),
        "env": attr.string_dict(),
        "gen_opendds_idl2cpp": attr.bool(),
        "gen_fatsrtps_idl2cpp": attr.bool(),
        "gen_connex_dds_idl2cpp": attr.bool(),
        "gen_vortex_dds_idl2cpp": attr.bool(),
    },
    output_to_genfiles = True,
    implementation = _generate_idl2cpp,
)
