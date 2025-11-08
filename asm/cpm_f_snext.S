; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_snext
  .code
;extern uint_fast8_t cpm_f_snext(FCB *fcb);
_cpm_f_snext:
  pop   hl  ; return
  pop   de  ; *fcb
  push  de
  push  hl
  push  bc
  ld    c,0x12
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
