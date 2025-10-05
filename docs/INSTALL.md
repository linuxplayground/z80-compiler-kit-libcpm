# BUILD AND INSTALL

## DEPENDANCIES

Please make sure you have [installed](./COMPILER-KIT.md) the Fuzix-Compiler-Kit
before continuing.

## BUILD
Just run `make`

The library and crt0.o files will be in `build/arch/<ARCH>/`  IE:
`build/arch/retro/libcpm.a`

## Examples

> NOTE: This library uses the word "architecture", "arch" and "ARCH" to refer to
> the concept of a target platform.  That might be symantically incorrect so
> please don't be confused.

The examples are short programs that demonstrate the various utilities available
in the library.

To compile them, you must first select the target architecture.  You can find a
list of available target architectures in `examples/Make.default`.  By default,
the RETRO target is selected.  You can override this by copying
`exambles/Make.default` to `examples/Make.local` and commenting and uncommenting
to select the target architecture you want.

Once you have selected the target architecture, you can run `make` inside the
`examples` directory.  This will build all the examples and you can find them in
`build/arch/<ARCH>/examples/` where `<ARCH>` is the name of the target
architecture you configured in `Make.local`.

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

This is what the installation directory will look like (files not shown) after
running `make install`.

```text
➜  libcpm tree
.
├── examples
│   └── arch
│       ├── nouveau
│       │   └── skeleton
│               ├── main.c
│               └── Makefile
│       └── retro
│           └── skeleton
│               ├── main.c
│               └── Makefile
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

15 directories, 25 files
```

## UNINSTALL

Just delete the whole `libcpm` directory from wherever it was installed to.  If
you used the default path, this will be at `${HOME}/dev/libcpm`

## SKELETON PROJECTS

An example *skeleton* application is provided with pre-configured Makefiles
that can be copied to start a new project anywhere on your system.

<!-- vim: tw=80 cc=80 ft=markdown: -->
