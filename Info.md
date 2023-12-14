# Known Issues
 - double-clicking the header for the viewport tab causes an incomplete framebuffer
	 - More specifically, causes the height of the viewport to be set to 0 and the OpenGL Framebuffer cannot handle a height of 0.
- Resizing the viewport on the diagonal causes severe artifacting on the screen for the duration of the resize, and a black screen during vertical or horizontal resizing.
	- 