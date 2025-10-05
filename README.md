# Z80-Retro! CPMLIB

## Compile and Install

See [INSTALL.md](./docs/INSTALL.md) for more detailed docs.

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

If you have installed the library, then you can find skeleton projects in the
`INSTALLDIR`.  By default this is `${HOME}/dev/libcpm`.

You should be able to copy a skeleton directory to any place on the same system
and compile your code from there.

<!-- vim: set ft=markdown ts=4 sw=4 et tw=80 cc=80: -->

