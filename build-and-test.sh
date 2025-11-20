#!/bin/bash
set -e

ROOT_DIR=$(dirname "$0")
BUILD_DIR="$ROOT_DIR/build"

echo "=== Starting clean build ==="
rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR
cd $BUILD_DIR

echo "=== Configuring CMake ==="
cmake ..

echo "=== Building ==="
cmake --build . --config Release

echo "=== Running Tests ==="
./test_observable

echo "=== FIN ==="