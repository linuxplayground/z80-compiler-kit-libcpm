  .export _f_usernum
  .code
_f_usernum:
  push  bc
  ld    c,0x20
  ld    e,l
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
