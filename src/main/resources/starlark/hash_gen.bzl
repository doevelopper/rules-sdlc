def _hash_gen_impl(ctx):
    computed = []
    ctx.actions.run_shell(
        outputs = [ctx.outputs.md5],
        inputs = [ctx.file.src],
        command = "md5sum {} > {}".format(ctx.file.src.path, ctx.outputs.md5.path),
    )

    ctx.actions.run_shell(
        outputs = [ctx.outputs.sha1],
        inputs = [ctx.file.src],
        command = "sha1sum {} > {}".format(ctx.file.src.path, ctx.outputs.sha1.path),
    )

    ctx.actions.run_shell(
        outputs = [ctx.outputs.sha256],
        inputs = [ctx.file.src],
        command = "sha256sum {} > {}".format(ctx.file.src.path, ctx.outputs.sha256.path),
    )

    # only the sha256 is computed.
    return DefaultInfo(files = depset([ctx.outputs.sha256]))

    #return DefaultInfo(files = depset([computed]))

hashes = rule(
    implementation = _hash_gen_impl,
    attrs = {
        "src": attr.label(mandatory = True, allow_single_file = True),
    },
    outputs = {
        "md5": "%{name}.md5",
        "sha1": "%{name}.sha1",
        "sha256": "%{name}.sha256",
    },
)
