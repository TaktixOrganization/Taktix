#!/bin/sh

echo "Running Taktix.."
echo ""

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"$PWD/Libraries"

chmod +x Binaries/Taktix

./Binaries/Taktix
