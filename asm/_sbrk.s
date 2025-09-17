; vim: set ft=z80:
;
; This code is copied and adapted from the HIGH-TECH-C Compiler for Z80
; https://github.com/agn453/HI-TECH-Z80-C/blob/master/gen/SBRK.AS
;
; The HI-TECH Z80 CP/M C compiler V3.09 is provided free of charge for
; any use, private or commercial, strictly as-is.  No warranty or product
; support is offered or implied.
;
  .export __sbrk
  .export __brk
  .export memtop
  .code

__brk:
  ld    (memtop),hl
  ld    hl,0
  ret

__sbrk:
  push  bc            ; preserve BC
  ex    de,hl         ; move argument into DE

  ld    hl,(memtop)   ; is memtop = 0
  ld    a,l
  or    h
  jr    nz,l1         ; no - skip to incr
  ld    hl,__end      ; yes - set it to end of program bytes
  ld    (memtop),hl
l1:                   ; 
  add   hl,de         ; add argument to hl.
  jr    c,l2          ; if overflow - no more room.
  ld    bc,0x400      ; allow buffer of 1kb between stack and heap
  add   hl,bc         ; add new memtop to buffer
  jr    c,l2          ; if overflow - no more room.
  sbc   hl,sp         ; subtract stack pointer from new memtop (incl. buffer)
  jr    c,l3          ; carry is set if HL < sp
l2:
  ld    hl,-1         ; return -1 if no room.
  pop   bc
  ret
l3:
  ld    hl,(memtop)   ; load existing memtop into hl
  push  hl            ; save it.
  add   hl,de         ; add memtop to argument (we already checked for overflows)
  ld    (memtop),hl   ; store back to memtop
  pop   hl            ; return original memtop
  pop   bc            ; restore preserved BC
  ret                 ; return

memtop: .ds 2
