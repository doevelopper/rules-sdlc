#!/usr/bin/env bash

set -eux

#clang-tidy src/main/cpp/cfs/platform/Dummy.[ch]pp -config='' -- -std=c++17 -I/usr/include/c++/9/ -Isrc/main/cpp/

# clang-tidy -checks='modernize-use-override' cfs/hal/btht/Control.[ch]pp -- -std=c++17
# clang-tidy -checks='modernize-use-override' cfs/hal/btht/Control.[ch]pp -- -std=c++17
# clang-tidy -list-checks -checks=* -- -std=c++17 -I/usr/include/c++/5/
# clang-tidy *.[ch]pp -list-checks -checks=*,-clang-analyzer-alpha.*,-llvm-include-order -- -std=c++17 -I/usr/include/c++/5/