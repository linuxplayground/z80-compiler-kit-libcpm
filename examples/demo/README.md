# Demo

This is the bouncing ball demo.  The ball is a 16x16 sprite
that bounces off the border.  While that's happening the demo
also renders a full 32x24 screen full of letters of the ascii
table.  This shows that the framebuffer flush methods of the
tms routines are fast enough to complete without screen
tearing or spurios artifacts.
