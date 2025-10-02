<-- vim: set ft=markdown ts=4 sw=4 et tw=80 cc=80: -->
# Build

Just run `make`

The library an crt0.o files will be in `arch/<arch>/`  IE: `arch/retro/libcpm.a`

To make the examples, go into the examples directory and set up which target you
want the examples for in `Make.default` then type make.

The headers are in `include`

## TODO: THERE IS NO MAKE INSTALL YET.

# Build and Install FCC


These instructions are all gathered from a fresh install of Ubuntu-24.04 on
WSL2.

## Compiler Kit

```bash
mkdir tools
cd tools

git clone https://codeberg.org/etchedPixels/FUZIX-Bintools.git
git clone https://codeberg.org/etchedPixels/FUZIX-Compiler-Kit.git

sudo mkdir /opt/fcc
sudo chown ${USER}:${USER} /opt/fcc
echo "export PATH=\"$PATH:/opt/fcc/bin\"" >> ${HOME}/.bashrc
source ${HOME}/.bashrc

sudo apt update
sudo apt install build-essential libbsd-dev
cd FUZIX-Bintools
make install
cd ../FUZIX-Compiler-Kit
make bootstuff
make install
```


# Continue here if you want the emulator.

## Emulator Kit

```bash
cd tools
git clone https://codeberg.org/etchedPixels/EmulatorKit.git
cd EmulatorKit
sudo apt install libsdl2-dev
make 2063_sdl2
```

## libcpm


In this example, the assumption is a filesystem layout like this.

```text
.
|-- dev
`-- tools
    |-- EmulatorKit
    |-- FUZIX-Bintools
    `-- FUZIX-Compiler-Kit
```

Make the dev folder if it doesn't exist.  Up to you what folder names you use,
but this is how I do it.

```bash
sudo apt install cpmtools
cd dev
git clone https://github.com/linuxplayground/z80-compiler-kit-cpmlib.git
cd z80retro-libcpm/examples

ln -s ${HOME}/tools/EmulatorKit/2063_sdl2
dd if=/dev/zero of=sdcard.img bs=1024 count=256000
```

Now the disk image must be partitioned.  I use fdisk for this.  You need to
create one partition starting at the default sector and make it 128MB big.  Set
the type to CPM.

``` text
Welcome to fdisk (util-linux 2.39.3).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

Device does not contain a recognized partition table.
Created a new DOS (MBR) disklabel with disk identifier 0x32086a64.

Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (1-4, default 1): 1
First sector (2048-511999, default 2048): 2048
Last sector, +/-sectors or +/-size{K,M,G,T,P} (2048-511999, default 511999): +128M

Created a new partition 1 of type 'Linux' and of size 128 MiB.

Command (m for help): t
Selected partition 1
Hex code or alias (type L to list all): db
Changed type of partition 'unknown' to 'CP/M / CTOS / ...'.

Command (m for help): w
The partition table has been altered.
Syncing disks.
```

Now the disk image can be mounted on the loopback device.

```bash
sudo losetup --show -Pf sdcard.img

## XXX: Here the command will output something like /dev/loop0 or /dev/loop0.
## XXX: You need to keep that in mind.

ls -l /dev/loop0*
brw-rw---- 1 root       disk         7, 1 Sep  8 09:42 /dev/loop0
brw-rw---- 1 davelatham davelatham 259, 2 Sep  8 09:42 /dev/loop0p1

sudo chown ${USER}:${USER} /dev/loop0p1
```

The 2063-z80-cpm repo must be built so we can get the filesystem and boot
firmware from there to run the emulator.

```bash
cd dev/
git clone --recurse https://github.com/z80-retro/2063-z80-cpm.git
cd 2063-z80-cpm
sudo apt install z80asm
make world
dd if=filesystem/drive.img of=/dev/loop0p1 bs=512 conv=notrunc,fsync
```

Prepare the virtual filesystem with CPM and get the firmware ready for the
emulator.

```bash
cd dev/libcpm/examples
## Copy the firmare
cp ${HOME}/dev/2063-z80-cpm/boot/firmware.bin ./
## Truncate to meet the needs of the emulator
truncate --size=16k boot/firmware.bin
```

You can now make the library and the examples.

```bash
cd dev/libcpm

make world
```

Copy the examples into the virtual filesystem.

```bash
make -C examples copy
```

## Running the Emulator

```bash
cd dev/libcpm/examples

./2063_sdl2 -r firmware.bin -S sdcard.img -T
```

Once booted type `dir` to see the examples.  All the examples should work in the
emulator except for the joystick ones (unless you figure out how to map your
joystick with SDL2 and the emulator) and the audio ones as the emulatro does not
have AY-3-8910 support.

