#!/usr/bin/env bash
# source https://about.gitlab.com/blog/2017/09/05/how-to-automatically-create-a-new-mr-on-gitlab-with-gitlab-ci/
set -e

#target/bin/cfs-hal/src/main/cpp/cfs-hal-main.bin
function vgrndcall () {
    valgrind --tool=callgrind $@
}


valgrind --track-origins=yes target/bin/cfs-hal/src/main/cpp/cfs-hal-main.bin