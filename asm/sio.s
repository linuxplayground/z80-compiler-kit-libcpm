; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;
;    Copyright (C) 2025 David Latham
;
;    This library is free software; you can redistribute it and/or
;    modify it under the terms of the GNU Lesser General Public
;    License as published by the Free Software Foundation; either
;    version 2.1 of the License, or (at your option) any later version.
;
;    This library is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;    Lesser General Public License for more details.
;
;    You should have received a copy of the GNU Lesser General Public
;    License along with this library; if not, write to the Free Software
;    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
;    USA
;
; https://github.com/linuxplayground/z80-retro-cpmlib.git
;
;****************************************************************************

  .export _chin
  .export _chout
  .export _cstat

  .code

SIOA_D equ 0x30
SIOA_C equ 0x32

_cstat:
  in a,(SIOA_C)
  and 1
  ld l,a
  ld h,0
  ret

_chin:
  in a,(SIOA_C)
  and 1
  jr z,_chin
  in a,(SIOA_D)
  ld l,a
  ld h,0
  ret

_chout:
chout:
  in a,(SIOA_C)
  and 4
  jr z,chout
  ld a,l
  out (SIOA_D),a
  ret

