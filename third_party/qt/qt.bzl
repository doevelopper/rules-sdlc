load(
    "@io_rules_sdlc//utils:common.bzl",
    "file_base_name",
    "full_path_file_name"
)


def qt_cc_library(
    name,
    src,
    hdr,
    uis = [],
    res = [],
    deps = None,
    **kwargs):

    srcs = src

    for hItem in hdr:
        base_name = _base_name(_file_name(hItem))
        native.genrule(
            name = "%s_moc" % base_name,
            srcs = [hItem],
            outs = [ "moc_%s.cpp" % base_name ],
            cmd =  "if [[ `grep 'Q_OBJECT' $(location %s)` ]] ; \
            then $(type -P moc) $(location %s) -o $@ -f'%s'; \
            else echo '' > $@ ; fi"  % (hItem, hItem, '%s/%s' % (PACKAGE_NAME, hItem))
        )
        srcs.append("moc_%s.cpp" % base_name)

    for uitem in uis:
        base_name = _base_name(_file_name(uitem))
        native.genrule(
            name = "%s_ui" % base_name,
            srcs = [uitem],
            outs = ["ui_%s.h" % base_name],
            cmd = "$(type -P uic) $(locations %s) -o $@" % uitem,
        )
        hdr.append("ui_%s.h" % base_name)

    for ritem in res:
        base_name = _base_name(_file_name(ritem))
        native.genrule(
            name = "%s_res" % base_name,
            srcs = [ritem] + deps,
            outs = ["res_%s.cpp" % base_name],
            cmd = "$(type -P rcc) --name res --output $(OUTS) $(location %s)" % ritem,
        )
        srcs.append("res_%s.cpp" % base_name)

    hdrs = hdr

    native.cc_library(
        name = name,
        srcs = srcs,
        hdrs = hdrs,
        deps = deps,
        alwayslink = 1,
        **kwargs
    )


#usage exemple

#qt_cc_library(
#    name = "qt_demo_lib",

#    src = glob(
#        ["src/main/cpp/*.cpp"],
#    ),

#    copts = [
#        "-Isrc/main/proto",
#    ],

#    hdr = glob([
#        "src/main/cpp/*.hpp",
#    ]),

#    includes = [
#        ".",
#    ],

#    linkstatic = 1,

#    res = glob([
#        "src/main/res/*.qrc",
#    ]),

#    uis = glob([
#        "src/main/uis/*.ui",
#    ]),

#    deps = [
#        "@qt514//:qt_gui",
#    ],
#)

