#!/bin/sh

echo "Running Taktix.."
echo ""

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$PWD/Submodules"

chmod +x Binaries/Taktix

./Binaries/Taktix
