
def doc_group_ace_repository():
    return native.new_local_repository(
        name = "docgroup_ace",
        build_file = "@io_rules_sdlc//third_party:BUILD.ace",
        path = "/usr/local/include",
    )
