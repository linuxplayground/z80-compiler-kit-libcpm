#/usr/bin/env bash

usage() {
  echo "No prefix provided.  Check Make.default or Make.local"
  echo "Usage: make install"
  exit 1
}

if [ $# -lt 1 ]; then
  usage
fi

echo "Installing to $1"

echo "Creating install directory..."
mkdir -pv $1/lib
mkdir -pv $1/include

echo "Copying files..."
cp -rv build/arch $1/lib/
cp -rv include/* $1/include/

sed "s#INSTALLDIR#$1#" skeleton_nouveau/Makefile.template > skeleton_nouveau/Makefile
sed "s#INSTALLDIR#$1#" skeleton_retro/Makefile.template > skeleton_retro/Makefile

