; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_conout
  .code
; void conout(uint_fast8_t c);
_cpm_conout:
  ld    hl,2
  add   hl,sp
  ld    e,(hl)

  push  bc
  ld    c,2
  call  5
  pop   bc

  ret

