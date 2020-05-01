
cc_library(
    name = "qt_core",
    hdrs = glob(["*"]),

    includes = [
        "include",
        "include/QtCore"
    ],

    copts=[
        "-Iinclude",
        "-Iinclude/QtCore",
    ],
    linkopts = [
        "-Wl,-rpath,/opt/Qt/5.14.2/gcc_64/lib",
        "-lQt5Core",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "qt_widgets",
    hdrs = glob(["*"]),
    includes = ["include/QtWidgets" ],
    deps = [":qt_core"],
    copts=[
        "-Iinclude",
#        "-Iinclude/QtCore",
        "-Iinclude/QtWidgets",
    ],
    linkopts = [
        "-L/opt/Qt/5.14.2/gcc_64/lib",
        "-lQt5Widgets",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "qt_gui",
    hdrs = glob(["*"]),
    includes = ["include/QtGui"],
    deps = [
        ":qt_core",
        ":qt_widgets"
    ],

    copts=[
        "-Iinclude",
       # "-Iinclude/QtCore",
        "-Iinclude/QtGui",
       # "-Iinclude/QtWidgets",
    ],

    linkopts = [
        "-L/opt/Qt/5.14.2/gcc_64/lib",
        "-lQt5Gui",
    ],

    visibility = ["//visibility:public"],
)

cc_library(

    name = "qt_opengl",
    hdrs = glob(["*"]),

    includes = [
        "include/QtOpenGL"
    ],

    deps = [
        ":qt_core",
        ":qt_widgets",
        ":qt_gui"
    ],

    copts=[
        "-Iinclude",
        "-Iinclude/QtCore",
        "-Iinclude/QtWidgets",
        "-Iinclude/QtGui",
        "-Iinclude/QtOpenGL",
    ],

    linkopts = [
        "-L/opt/Qt/5.14.2/gcc_64/lib",
        "-lQt5OpenGL",
    ],

    visibility = ["//visibility:public"],
)

cc_library(
    name = "qt_qml",
    hdrs = glob(["QtQml/**"]),
    includes = ["."],
    linkopts = [
        "-lQt5Qml",
    ],
    deps = [
        ":qt_core",
        ":qt_network",
    ],
)

cc_library(
    name = "qt_qml_models",
    linkopts = [
        "-lQt5QmlModels",
    ],
    hdrs = glob(
        ["QtQmlModels/**"],
    ),
    includes = ["."],
)

cc_library(
    name = "qt_quick",
    hdrs = glob(["QtQuick/**"]),
    includes = ["."],
    linkopts = [
        "-lQt5Quick",
    ],
    deps = [
        ":qt_gui",
        ":qt_qml",
        ":qt_qml_models",
    ],
)

cc_library(
    name = "qt_network",
    hdrs = glob(["QtNetwork/**"]),
    includes = ["."],
    linkopts = [
        "-lQt5Network",
    ],
)


cc_library(
    name = "qt_3d",
    hdrs = glob([
        "Qt3DAnimation/**",
        "Qt3DCore/**",
        "Qt3DExtras/**",
        "Qt3DInput/**",
        "Qt3DLogic/**",
        "Qt3DQuick/**",
        "Qt3DQuickAnimation/**",
        "Qt3DQuickExtras/**",
        "Qt3DQuickInput/**",
        "Qt3DQuickRender/**",
        "Qt3DQuickScene2D/**",
        "Qt3DRender/**",
    ]),
    includes = ["."],
    linkopts = [
        "-lQt53DAnimation",
        "-lQt53DCore",
        "-lQt53DExtras",
        "-lQt53DInput",
        "-lQt53DLogic",
        "-lQt53DQuick",
        "-lQt53DQuickAnimation",
        "-lQt53DQuickExtras",
        "-lQt53DQuickInput",
        "-lQt53DQuickRender",
        "-lQt53DQuickScene2D",
        "-lQt53DRender",
    ],
    visibility = ["//visibility:public"],
)
