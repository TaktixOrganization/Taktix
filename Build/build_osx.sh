#!/usr/bin/env bash

# Compiling SFML from sources

cd Submodules/SFML
git checkout 2.5.x
mkdir -p Build
cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j2
make install

cd ../../..

# Compiling TGUI from sources

cd Submodules/TGUI
git checkout 0.8
mkdir -p Build
cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j2 tgui
make install

cd ../../..

# Compiling Taktix

cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make all

# Run tests

./Tests/Taktix_Tests