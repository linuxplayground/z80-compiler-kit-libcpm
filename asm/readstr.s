  .export _readstr
  .code

; This function reads characters from the keyboard into a memory buffer until
; RETURN is pressed. The Delete key is handled correctly.
;
; ON ENTRY: The value at buffer+0 is the amount of bytes available in the
; buffer. Once the limit has been reached, no more can be added, although the
; line editor can still be used.

_readstr:
  push  bc
  ld    c,0xa
  ex    de,hl
  call  5
  pop   bc
  ret
