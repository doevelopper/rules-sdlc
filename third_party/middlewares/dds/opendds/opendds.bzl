
def _generate_idl2cpp(ctx):

    idl_output_dir = ctx.bin_dir.path + "/"
    if ctx.label.workspace_root:
        idl_output_dir += ctx.label.workspace_root + "/"
    if ctx.label.package:
        idl_output_dir += ctx.label.package + "/"

    files = []
    for idl_file in ctx.files.idls:
        idl_file_path = idl_file.path.split("/idl/")[1].rpartition("/")[0]
        file_name = idl_file.path[0:-len(idl_file.extension) - 1]
        file_base_name = idl_file.basename[0:-len(idl_file.extension) - 1]
        idl_output_dir += idl_file_path
        o_ts_c_hdr = ctx.actions.declare_file("{}/{}C.h".format(idl_file_path, file_base_name))
        o_ts_idl = ctx.actions.declare_file("{}/{}TypeSupport.idl".format(idl_file_path, file_base_name))
        o_ts_hdr = ctx.actions.declare_file("{}/{}TypeSupportImpl.h".format(idl_file_path, file_base_name))
        o_ts_src = ctx.actions.declare_file("{}/{}TypeSupportImpl.cpp".format(idl_file_path, file_base_name))
        files.append(o_ts_c_hdr)
        files.append(o_ts_idl)
        files.append(o_ts_hdr)
        files.append(o_ts_src)
        ctx.actions.run(
            outputs = [
                otschdr,
                otsidl,
                otshdr,
                otssrc,
            ],
            inputs = [idl_file],
            unused_inputs_list = None,
            executable = ctx.executable._opendds_idl_bin,
            arguments = [opendds_args],
            progress_message = "OpendDDS IDL Generating srs from {} \n in folder {}".format(idl_file, full_outdir),  #"Packing " + ctx.label.package + ":" + ctx.label.name,
            use_default_shell_env = True,
            env = ctx.attr.env,
            execution_requirements = None,
            input_manifests = None,
        )



opendds_idl2cpp = rule(
    attrs = {
        "idls": attr.label_list(
            allow_files = [".idl"],
            doc = "The .IDL files to generate to c++.",
        ),
        "env": attr.string_dict(),
        "_opendds_idl_bin": attr.label(
            executable = True,
            cfg = "host",
            default = Label("@io_rules_sdlc//:opendds_idl"),
        ),
        "is_type_support_idl": attr.bool(),

    output_to_genfiles = True,

    implementation = _generate_idl2cpp,
)

