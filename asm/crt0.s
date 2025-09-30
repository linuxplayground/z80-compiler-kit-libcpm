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
; https://github.com/linuxplayground/z80-retro-libcpm.git
;
;****************************************************************************
.export retcpm
stacktop equ 0xD400

  .code
  ld    hl, 0
  add   hl,sp
  ld    (oldstack),hl

  ld    sp,stacktop

  call  __init_sys
  call  _main

  pop   de
retcpm:
  ld    hl,_tms_buf
  call  _free

  ld    sp,(oldstack)
  ret

oldstack: .ds 2
