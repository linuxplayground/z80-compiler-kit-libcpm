; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_drv_reset
  .code
;extern uint_fast8_t cpm_drv_reset(size_t bitmap);
_cpm_drv_reset:
  pop   hl  ; return
  pop   de  ; bitmap
  push  de
  push  hl
  push  bc
  ld    c,0x25
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
