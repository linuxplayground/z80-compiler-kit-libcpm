; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_dc_out
  .code
; void cpm_dc_out(uint_fast8_t c);
_cpm_dc_out:
  ld    hl,2
  add   hl,sp
  ld    e,(hl)  ;c

  push  bc
  ld    c,6
  call  5
  pop   bc

  ret

