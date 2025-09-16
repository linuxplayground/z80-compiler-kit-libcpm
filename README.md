<-- vim: set ft=markdown ts=4 sw=4 et tw=80 cc=80: -->
# Z80-Retro! CPMLIB

As I have been starting to use the [Fuzix Compiler
Kit](https://github.com/etchedpixels/Fuzix-Compiler-Kit.git) to compile C
Programs for the [Z80-Retro](https://github.com/Z80-Retro/2063-Z80) I wanted to
have some form of standard library for interfacing with CP/M-2.2.  In the past I have used [Z88DK](https://github.com/z88dk/z88dk.git) for this and it has proven
to be very capable.  It's really just a matter of preference for me.  I prefer
to use the Fuzix Compiler Kit (FCC) over the Z88DK compiler due to its simple
install and lightweight footprint.

## Newlib you say?

I had a decent go at getting Newlib to compile with the Fuzix-Compiler-Kit.  I
was not successful.

## Not A Full Stdlib

This is not a full blown standard library.  I have gone for something resembling
the basics.  These are the functions available:

### Core

- [x] CRT0 that restores the CPM stack before returning from main
- [x] exit()

### CPM

- [x] CPM2.2 Wappers as described in [cpm.h](./include/cpm.h)
- [ ] File Control [fcntl.h](./include/fcntl.h)
    - [x] STDOUT, STDERR, STDIN
    - [x] open, close, read, write
    - [ ] lseek and random access
    - [ ] support for file access modes

### String and Memory

- [x] malloc and free with supporting sbrk assembly routine [stdlib.h](./include/stdlib.h)
- [x] String functions provided by the Fuzix Compiler Kit
[stirng.h](./include/string.h)
    - [x] strchr strcpy strlcpy strncmp strcmp strlcat strlen strrchr
    - [x] memcmp memcpy memset
- [ ] Additional string functions
    - [x] itoa
    - [x] toupper
    - [x] puts - prints null terminated strings - no formatting
    - [x] print_kvd print_kvh - prints text followed by integer in decimal (kvd)
      or hex (kvh)
    - [ ] sprintf
- [x] Raw SIO routines [sio.h](./include/sio.h)
    - [x] chin, chout, cstat

### Graphics

- [ ] TMS [tms.h](./include/tms.h)
    - [x] Init graphics modes: g1, g2,mc, text
    - [ ] g2.5 mode
    - [x] framebuffer routines: tms_wait, tms_flush
    - [x] set tms ram address: for read and write
    - [x] load_patterns, load_colors
    - [x] MC plot xy to framebuffer
    - [x] G1 and G2.5 plot xy to framebuffer
    - [ ] G2 plot xy pixel
    - [ ] Flush sprite attributes
    - [x] Char at location xy G1 mode, text mode
    - [ ] Char at location xy G2.5 mode
    - [x] String at location xy G1 mode, text mode
    - [ ] String at location xy G2.5 mode

### Joystick

- [ ] Joystick [joy.h](./include/joy.h)
    - [ ] Get Joy Status J0, J1

