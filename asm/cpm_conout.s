; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_conout
  .code
_cpm_conout:
  push  bc
  ld    c,2
  ex    de,hl
  call  5
  pop   bc
  ret

