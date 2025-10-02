# Z80-Retro! CPMLIB

## Compile and Install

- Clone
- make
- make install

The default INSTALLDIR is ${HOME}/dev/libcpm  If you want to change that, set
the new value of INSTALLDIR in `Make.local` to override the default.

```bash
cp Make.default Make.local
vi Make.local
```

## Using the library

There are example projects in the library that have working Make scripts.  These
use the source tree of the library, (this repo) rather than the installed
location.

An example Makefile.template is given in the skeleton folders.

The `make install` scripts automatically create the `Makefile` from the
`Makefile.template` in the skeleton_retro and skeleton_nouveau directories.

You should be able to copy a skeleton directory to any place on the same system
and compile your code from there.

<-- vim: set ft=markdown ts=4 sw=4 et tw=80 cc=80: -->

