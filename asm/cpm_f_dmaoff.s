; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_dmaoff
  .code
_cpm_f_dmaoff:
  push  bc
  ld    c,0x1A
  ex    de,hl
  call  5
  pop   bc
  ret

