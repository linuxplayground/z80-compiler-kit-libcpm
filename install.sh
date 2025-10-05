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
mkdir -pv $1/lib/arch/retro
mkdir -pv $1/lib/arch/nouveau
mkdir -pv $1/examples/arch/retro/skeleton
mkdir -pv $1/examples/arch/nouveau/skeleton
mkdir -pv $1/include

echo "Copying files..."
cp -f build/arch/RETRO/libcpm.a $1/lib/arch/retro/
cp -f build/arch/RETRO/crt0.o $1/lib/arch/retro/
cp -f build/arch/NOUVEAU/libcpm.a $1/lib/arch/nouveau/
cp -f build/arch/NOUVEAU/crt0.o $1/lib/arch/nouveau/
cp -rv include/* $1/include/

sed "s#INSTALLDIR#$1#" arch/NOUVEAU/skeleton/Makefile.template > arch/NOUVEAU/skeleton/Makefile
cp -r arch/NOUVEAU/skeleton/Makefile $1/examples/arch/nouveau/skeleton/
cp -r arch/NOUVEAU/skeleton/main.c $1/examples/arch/nouveau/skeleton/

sed "s#INSTALLDIR#$1#" arch/RETRO/skeleton/Makefile.template > arch/RETRO/skeleton/Makefile
cp -r arch/RETRO/skeleton/Makefile $1/examples/arch/retro/skeleton/
cp -r arch/RETRO/skeleton/main.c $1/examples/arch/retro/skeleton/

