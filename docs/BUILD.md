<-- vim: set ft=markdown ts=4 sw=4 et tw=80 cc=80: -->
# Build

These instructions are all gathered from a fresh install of Ubuntu-24.04 on
WSL2.

## Compiler Kit

```bash
mkdir tools
cd tools

git clone https://github.com/EtchedPixels/FUZIX-Bintools.git
git clone https://github.com/EtchedPixels/FUZIX-Compiler-Kit.git

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

## Emulator Kit

```bash
cd tools
git clone https://github.com/EtchedPixels/EmulatorKit.git
cd EmulatorKit
sudo apt install libsdl2-dev
make 2063_sdl2
```

## CPMLIB

Now that the compiler, assembler and linker are installed and we have an
emulator, it's time to clone and build CPMLIB

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
mkdir dev
git clone https://github.com/linuxplayground/z80retro-cpmlib.git
cd z80retro-cpmlib

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

## NOTE NOTE NOTE: Here the command will output something like /dev/loop0 or /dev/loop1.
## NOTE NOTE NOTE: You need to keep that in mind.

ls -l /dev/loop1*
brw-rw---- 1 root       disk         7, 1 Sep  8 09:42 /dev/loop1
brw-rw---- 1 davelatham davelatham 259, 2 Sep  8 09:42 /dev/loop1p1

sudo chown ${USER}:${USER} /dev/loop1p1
```

You can now make the library and the tests.  The tests should be deployed onto
the CPM filesystem ready for the Emulator

```bash
cd dev/cpmlib

make world
```

One final thing that needs to be done is that the 2063-z80-cpm repo must be
built so we can get the filesystem and boot firmware from there to run the
emulator.

```bash
cd dev/
git clone --recurse https://github.com/z80-retro/2063-z80-cpm.git
cd 2063-z80-cpm
sudo apt install z80asm
make world
truncate --size=16k boot/firmware.bin
dd if=filesystem/drive.img of=/dev/loop1p1 bs=512 conv=notrunc,fsync
```

Now back to the cpmlib/test and we can run some tests.

```bash
cd dev/cpmlib/test
## FOR CONVENIENCE ADD A SYMLINK
ln -s ${HOME}/dev/2063-z80-cpm/boot/firmware.bin
```

## Running the Emulator

```bash
cd dev/cpmlib/test

## NOTE: NOTE: NOTE: You must update the LOOPDEV variable in the cpmlib/test/Makefile before you start
## NOTE: NOTE: NOTE: It must match the device you used in the `dd` command to copy the filesystem.img on
## NOTE: NOTE: NOTE: to the mounted sdcard image.


./2063_sdl2 -r firmware.bin -S sdcard.img -T
```

Once booted, you can type `testtms` to test Graphics Mode 1.

