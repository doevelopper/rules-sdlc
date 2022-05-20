"""
Skylark rules and macros to support Qt application compilation.
This file defines three macros:
  - sdlc_lupdate
  - sdlc_lrelease
  - sdlc_uic, compiles .ui files into header files.
  - sdlc_lconvert, compiles .ts files into .qm files.
  - sdlc_rcc, compiles .res files into a cc_library.
  - sdlc_moc, generates .cpp or .moc files for Qt MOC .h or .cpp files.
  - sdlc_linguist
  - sdlc_qscxmlc
  - sdlc_qmlimportscanner
  - sdlc_qmllint
  - sdlc_qmlmin
  - sdlc_qdbuscpp2xml
  - sdlc_qdbusxml2cpp
  - sdlc_qdoc
  - sdlc_qgltf
  - sdlc_qlalr
  - sdlc_qmake
"""

load(
    "@io_rules_sdlc//utils:common.bzl",
    "file_base_name",
    "full_path_file_name",
)
