; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_randrec
  .code
;extern void cpm_f_randrec(FCB *fcb);
_cpm_f_randrec:
  pop   hl  ; return
  pop   de  ; *fcb
  push  de
  push  hl
  push  bc
  ld    c,0x25
  call  5
  pop   bc
  ret
