# Sprites

Probably not the best name for this example, but it's purpose is to draw 8x8 sprites such that there are 5 in a row.  After drawing the sprites the program prints the current value of the status register and exits.  This is useful to confirm if the 5th Sprite reported by the VDP is the first one that occurred or the last one.

The VDP can only display 4 sprites on a single scanline.  When a fifth sprite is drawn on the same scanline as 4 preceeding sprites, the VDP does not draw it but sets the 5th sprite flag and the index of the 5th sprite into the status register.

This example returns 0xC4 meaning the following:

```text
bit  : 7 6 5 4 3 2 1 0
val  : 1 1 0 0 0 1 0 0    =   0xC4
       ^ ^ ^ |       |
       | | | +---+---+
       | | |     +- index of 5th sprite
       | | +- collision
       | +- 5th sprite
       +-vblank
```

As there are 15 sprites drawn with indexes ranging from 0-15, the value 4 in the fifth sprite index shows that it's the first occurrence that is reported.


