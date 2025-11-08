; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_close
  .code
;extern uint_fast8_t cpm_f_close(FCB *fcb);
_cpm_f_close:
  pop   hl  ; return
  pop   de  ; *fcb
  push  de
  push  hl
  push  bc
  ld    c,0x10
  call  5
  pop   bc
  ret
