#!/bin/bash
set -e

INSTALL_PREFIX="/usr/local"

echo "=== Installing Mono ==="

sudo mkdir -p "$INSTALL_PREFIX/include/mono"
sudo cp -r include/mono/* "$INSTALL_PREFIX/include/mono/"

echo "Installed headers to $INSTALL_PREFIX/include/mono"
echo "You can now use #include <mono/observable.hpp> in your projects!"