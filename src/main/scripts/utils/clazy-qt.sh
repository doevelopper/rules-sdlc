#!/usr/bin/env bash

set -eux

clazy -isystem /opt/Qt/5.14.2/gcc_64/ -std=c++11 -fPIC

#Running Cl azy on al l  .cpp fil es in a project
find . -name "*.cpp" | xargsclazy-standalone -checks=level2 -p $CMAKE_BUILD_DIR
#or with jq
jq ".[] | .file" $BUILD_DIR/compile_commands.json | xargsclazy-standalone -checks=level2 -p $CMAKE_BUILD_DIR