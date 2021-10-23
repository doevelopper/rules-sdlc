#!/usr/bin/env bash

set -eux

function bzl-tracing () {
    # bazel query "allpaths(//foo, third_party/...)" --notool_deps --output graph | dot -Tsvg > /tmp/deps.svg
    bazel query "allpaths(//foo, third_party/...)" --notool_deps --output graph | dot -Tsvg > /tmp/deps.svg
}

function bzl-tools () {
    bazel query @bazel_tools//...
}

function bzl-cond () {
    bazel query @bazel_tools//src/conditions:all
}

function bzl-arch () {
    bazel query @bazel_tools//platforms:all
}

function bzl-packages () {
    bazel query @bazel_tools//platforms:all
}

function bzl-build-all () {
    kind="${1:-rule}"
    bazel query "kind('$kind', '//...')" 2>/dev/null | while read x; do
        bazel build "$x" > /dev/null 2>&1
        retVal=$?
        res='SUCCESS'
        if [ $retVal -ne 0 ]; then res='FAILURE'; fi
         printf "%s\t%s\n" "$res" "$x"
    done
}

function bzl-all-bin () {
    bazel query 'kind(.*_binary, //...)'
}

function bzl-all-lib () {
    bazel query 'kind(.*_library, //...)'
}

function bzl-all-test () {
    bazel query 'kind(.*_test, //...)'
}

function bzl-build-all-bin () {
	buildables=$(bazel query \
		--keep_going \
		--noshow_progress \
		"kind(.*_binary, rdeps(//..., set(${files[*]})))")
}
function bzl-run-all-bin () {
    for r in $(bazel query 'kind(.*_binary, //...)' 2> /dev/null | grep .bin | xargs)
    do
      bazel run $r
    done
}

function bzl-run-all-test () {
    tests=$(bazel query \
        --keep_going \
        --noshow_progress \
        "kind(test, rdeps(//..., set(${files[*]}))) except attr('tags', 'manual', //...)")
    # Run the tests if there were results
    if [[ ! -z $tests ]]; then
          echo "Running tests $tests"
          bazel test $tests
    fi
}

function bzl-buildify () {
	bazel run //:buildifier
}

function bzl-gen-dir () {
	echo $(bazel info bazel-genfiles)
}

function bzl-list-packages () {
	echo $(bazel query //... | tr '\n' ' ')
}

## Print availabel bazel rules by path
## Usage bazel_rules '//...'
function bazel_rules(){
	bazel query "attr(name, \".*\", $@:*)" 2> /dev/null
}

## Print availabel bazel rules by path
## Usage bazel_public_rules '//...'
function bazel_public_rules() {
	bazel query "attr(visibility, \"//visibility:public\", $@:*)" 2> /dev/null
}
## Usage: bazel_graph '//cfs-com/src/main/cpp:cfs-com-main', then paste clipboard content into graph input.
function bazel_graph(){
	bazel query --notool_deps --noimplicit_deps "deps($@)" --output graph 2> /dev/null ;#| pbcopy && open http://www.webgraphviz.com/
}

function bzl_graph-workspace() {
    echo "create a high level graph of library dependencies within a given bazel workspace ( targets scala java cpp and python projects ) "
    output_graph=$(basename $(git rev-parse --show-toplevel))
    bazel query --noimplicit_deps 'kind("(scala|java|cc|py)_*", deps(//...))' --output graph > ${output_graph}.dot
    dot -Tpng < ${output_graph}.dot > ${output_graph}.png
}

function miscs(){
    bazel query --noshow_progress 'buildfiles(//...)'
    bazel build --check_tests_up_to_date --check_up_to_date --nobuild //...
    bazel build --nobuild //...
    bazel test //... --nocache_test_results --test_output=streamed --curses=yes --color=yes
    bazel query 'kind(".*_binary rule", //...) union kind(".*_test rule", //...) union kind(".*_library rule", //...)'
    bazel query 'tests(//...)'
    bazel query "kind(cc_test, //cfs-utils/... + //cfs-osal/...)"

}

function build_targets() {
    COMMON_TARGETS="//src/main/cpp/... union //src/test/cpp/..."
    JOB_ARG=$(nproc)
    DEFINES="${DEFINES} --copt=-fpic"
    case $BUILD_FILTER in
        utils)
            BUILD_TARGETS=`bazel query //src/main/... union //cfs-utils/...`
            ;;
        *)
             BUILD_TARGETS=`bazel query`
    esac

    bazel build $JOB_ARG $DEFINES $@ $BUILD_TARGETS
}

function dps_graph () {
	xdot <(bazel query --nohost_deps --noimplicit_deps 'deps('$1')' --output graph)
}
