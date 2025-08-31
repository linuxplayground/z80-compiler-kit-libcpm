# Using the Etched Pixels Emulator

## Pre Requisites


### Z80 Retro CPM and Boot Loader

You must be able to build the whole project at https://github.com/Z80-Retro/2063-z80-cpm.git.  From this you will need the following 2 files:

- boot/firmware.bin
- filesystem/drive.img

Copy them both to this test folder.

Truncate the firmware.bin to be 16KB.

```shell
truncate --size=16k firmware.bin
```


### Etched Pixels Emulator Kit

You must have a working version of the Etched Pixels Emulator kit from https://github.com/etchedpixels/emulatorkit.git and you must have successfully built it with:

```shell
make 2063_sdl2
```

Link to the emulator inside the test folder with `ln -s ../../emulatorkit/2063_sdl2`  from where ever you have your emulator kit compiled.

## Build the Virtual SDCard Image

First make a blank image with dd like this:

```shell
dd if=/dev/zero of=sdcard.img bs=1024 count=256000
```

Format the sdcard image.

```shell
sudo fdisk sdcard.img
```

- Choose `n` for new partition
- Choose `p` for primary
- Press enter to accept default start position
- Type `+128M` for the size
- Choose `t` for type
- Type `db` for CPM 
- Choose `w` to save and quit

Then mount it using `losetup`

```shell
sudo losetup -Pf --show sdcard.img
```

Losetup will return the mount point.  This will likely be `/dev/loop0`.  Keep a note of this as the following commands depdend on it.

Now you can change the owner of the mounted partition at `/dev/loop0p1`.

```shell
sudo chown <username>:<usergroup> /dev/loop0p1
```

Check the Makefile in the test directory to make sure that the copy recipe uses the same mount point as you have been using above. You should be good to go.

