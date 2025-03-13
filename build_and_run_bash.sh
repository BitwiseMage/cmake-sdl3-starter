#!/bin/bash
set -e

cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B build
cmake --build build

BIN_FILE=$(find bin -maxdepth 1 -type f -executable | head -n 1)

if [ -n "$BIN_FILE" ]; then
    echo "Running: $BIN_FILE"
    "$BIN_FILE"
else
    echo "No executable found in the bin folder!"
    exit 1
fi
