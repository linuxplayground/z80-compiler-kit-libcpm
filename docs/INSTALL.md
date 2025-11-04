# BUILD AND INSTALL

## DEPENDENCIES

Please make sure you have [installed](./COMPILER-KIT.md) the FUZIX-Compiler-Kit
before continuing.

## BUILD
Just run `make`

The library and crt0.o files will be in `build/arch/<ARCH>/`  IE:
`build/arch/retro/libcpm.a`

### CONFIGURATION

Copy `Make.default` to `Make.local` and edit.  Then you can build for specific
targets.

> Note: To build the library, you do `make nouveau` or `make retro` or `make` to
> build them both.

The ARCH in `Make.default` is for building the examples.

## Examples

> NOTE: This library uses the word "architecture", "arch" and "ARCH" to refer to
> the concept of a target platform.  That might be semantically incorrect so
> please don't be confused.

The examples are short programs that demonstrate the various utilities available
in the library.

## INSTALL

You might want to have the library installed in a more central location.  An
install script is provided for this.

Before installing, please note: The install scripts assume that you are
installing for all the available targets.  There is no harm in doing so as your
applications that you develop must select which target to compile for at compile
time.  Applications can be compiled multiple times for different targets so it
will be convenient to have all the supported target architectures supported.

The `Make.default` configuration file in the root of this project contains the
default value for the installation directory.  This is where the `lib` and
`includes` folders will be created when running `make install`.  You can
override this by copying `Make.default` to `Make.local` and changing the value
of `INSTALLDIR`.

This is what the installation directory will look like after running `make
install`.

```text
.
├── examples
│   └── arch
│       ├── nouveau
│       │   └── skeleton
│       │       ├── Makefile
│       │       └── main.c
│       └── retro
│           └── skeleton
│               ├── Makefile
│               └── main.c
├── include
│   ├── arch
│   │   ├── NOUVEAU
│   │   │   └── io.h
│   │   └── RETRO
│   │       └── io.h
│   ├── ay-3-8910.h
│   ├── ay-notes.h
│   ├── cpm.h
│   ├── errno.h
│   ├── fcntl.h
│   ├── joy.h
│   ├── stdarg.h
│   ├── stdbool.h
│   ├── stddef.h
│   ├── stdint.h
│   ├── stdio.h
│   ├── stdlib.h
│   ├── string.h
│   ├── tms.h
│   ├── tms_patterns.h
│   └── unistd.h
└── lib
    └── arch
        ├── nouveau
        │   ├── crt0.o
        │   └── libcpm.a
        └── retro
            ├── crt0.o
            └── libcpm.a

15 directories, 26 files
```

## UNINSTALL

Just delete the whole `libcpm` directory from wherever it was installed to.  If
you used the default path, this will be at `${HOME}/dev/libcpm`

## SKELETON PROJECTS

An example *skeleton* application is provided with pre-configured Makefiles
that can be copied to start a new project anywhere on your system.

