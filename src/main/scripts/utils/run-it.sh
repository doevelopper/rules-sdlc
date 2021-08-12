#!/bin/env bash

# deps: coreutils and gnu-sed
#set -e #break script on non-zero exitcode from any command
#set -x #display command being executed
#set -eo pipefail
#set -eEuo pipefail

set -o pipefail -o errexit -o nounset

help() {
    sed -rn 's/^### ?//;T;p' "$0"
    ## awk '/^###/' "$0"
    ## awk -F'### ' '/^###/' "$0"
    ## awk -F'### ' '/^###/ { print $2 }' "$0"
}

#[[ $# == 0 || "$1" == "-h" ]]
#if [[ $# == 0 ]] || [[ "$1" == "-h" ]]; then
#    help
#    exit 1
#fi

function error() {
    echo >&2 "$0: $@"
    exit 1
}



# From https://gist.github.com/somebox/6b00f47451956c1af6b4
function echo_ok {
    echo -e '\033[1;32m'"$1"'\033[0m';
}

function echo_warn {
    echo -e '\033[1;33m'"$1"'\033[0m';
}

function echo_error  {
    echo -e '\033[1;31mERROR: '"$1"'\033[0m';
}

function pause(){
    read -p "Press any key to continue..."
}


function fancy_echo() {
    local fmt="$1"; shift
    printf "\\n>>> $fmt\\n" "$@"
}

function is_true() {
    case "$1" in
        1|y|yes|YES|Yes|on)
            return 0
            ;;
        0|n|no|NO|No|off)
            return 1
            ;;
        "")
            if [ "$2" == "" ]; then
                echo_error "not a boolean argument \"$1\""
            fi
            is_true "$2"
            return $?
            ;;
        *)
            echo_error "not a boolean argument \"$1\""
            ;;
    esac
}


hostMachine="$(uname -s)"
case "${hostMachine}" in
    Linux*)     machine=Linux;;
    Darwin*)    machine=Mac;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${hostMachine}"
esac

echo_ok "Running test on ${machine} host"

KillChildProcesses()
{
    ChildProcesses=$(jobs -p)
    if [[ -n "${ChildProcesses}" ]]
    then
        # Note: ChildProcesses must be expanded to args here.
        kill ${ChildProcesses} 2> /dev/null
        wait 2> /dev/null
    fi
}

starXvirtualFramebuffer ()
{
    if [ "$(uname)" = "linux" ]; then
        trap : USR1
        (trap '' USR1; Xvfb $DISPLAY -screen 0 640x480x8 -nolisten tcp > /dev/null 2>&1) &
        #/usr/bin/Xvfb :99 -screen 0 1024x768x24 > /dev/null 2>&1 &
        XVFBPID=$!
        wait || :
        trap '' USR1

        if ! kill -0 $XVFBPID 2> /dev/null; then
            echo "Xvfb failed to start" >&2
            exit 1
        fi
    else
        sudo Xvfb $DISPLAY -screen 0 640x480x8 -nolisten tcp > /dev/null 2>&1 &
        XVFBPID=$!
        sleep 15
    fi

}

stopXvirtualFramebuffer ()
{
    if [ -n "${XVFBPID:-}" ]; then
        sudo kill $XVFBPID
        wait
    fi

}

echo_ok "Running $1 "

if [[ "$*" == *GUI_APPS* ]]
then
    starXvirtualFramebuffer
else
    echo_warn "Integration test might not be running a GUI application"
fi

# Laun binary compiled for integration test

if [[ "$*" == *UNIXSOCK* ]]
then
    SOCK=cucumber.wire.sock
    echo "unix: ${SOCK}" > src/it/cfs/com/features/step_definitions/cucumber.wire
    "$1" --unix "${SOCK}" > /dev/null &
	it_Process=$!

else
    if [ -n "${DISPLAY:-}" ]; then
        "$1" --port 3902 2> /dev/null &
		it_Process=$!
    else
        "$1" --port 3902 >/dev/null &
		it_Process=$!
    fi
fi

sleep 5

# Run cucumber binary to run
cucumber --format progress --backtrace --format html --color --out $2.Feature-Tests-Report.html --strict cfs/com/features
cucumber_Process=$!
wait %

while true
do
    sleep 1

    for ProcessID in "${it_Process}" "${cucumber_Process}"
    do
        if ! kill -0 $ProcessID 2> /dev/null
        then
            exit
        fi
    done
done

# Shutdown PORT to kill process listening on cucumber test port used in next test iteration
lsof -ti tcp:3902 | ([[ $? == 0 ]] && xargs kill -9 || echo_error "No Cucumber's PID to kill found" )

#
if [[ "$*" == *GUI_APPS* ]]
then
    stopXvirtualFramebuffer
else
    echo_warn "Integration test might not be running a GUI application"
fi
