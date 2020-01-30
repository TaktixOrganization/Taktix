#!/usr/bin/env bash

# Compiling SFML from sources

cd Submodules/SFML
git checkout 2.5.x
mkdir -p Build
cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
make install

cd ../../..

# Compiling TGUI from sources

cd Submodules/TGUI
git checkout 0.8
mkdir -p Build
cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
make install

cd ../../..

# Compiling Taktix

cd Build
cmake .. -DCMAKE_BUILD_TYPE=Release
make all

# Moving libraries

mkdir -p Application/Binaries/
mv Application/Taktix Application/Binaries/.
mkdir -p Application/Submodules
cp ../Submodules/SFML/Build/lib/* Application/Submodules/.
cp ../Submodules/TGUI/Build/lib/* Application/Submodules/.
chmod u+x run.sh
cp run.sh Application/.
mv Application Taktix

mkdir -p Tests/Binaries/
mv Tests/Taktix_Tests Tests/Binaries/.
mkdir -p Tests/Submodules
cp ../Submodules/SFML/Build/lib/* Tests/Submodules/.
cp ../Submodules/TGUI/Build/lib/* Tests/Submodules/.

# Cleaning deployement files

rm Makefile
rm *.cmake
rm -rf CMakeFiles
rm CMake*

rm Taktix/Makefile
rm Taktix/*.cmake
rm -rf Taktix/CMakeFiles

rm Tests/Makefile
rm Tests/*.cmake
rm -rf Tests/CMakeFiles