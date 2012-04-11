//
//  xgiwidget_simpletext.h
//
//	widget which draws a string of text with a specified font at a specified location.
//  one may specify one of 3 tags:
//		XGI_SIMPLETEXT_LEFT				: aligns the text to the left of the location
//		XGI_SIMPLETEXT_RIGHT			: aligns the text to the right of the location (default)
//		XGI_SIMPLETEXT_CENTER			: aligns the text to the center of the location
//

#ifndef XGIWIDGET_SIMPLETEXT_H
#define XGIWIDGET_SIMPLETEXT_H

#include <OpenGL/glx.h>

#include "xgi_widget.h"

// alignment tags
#define	XGI_SIMPLETEXT_LEFT		-1
#define	XGI_SIMPLETEXT_CENTER	 0
#define XGI_SIMPLETEXT_RIGHT	 1

// fonts
#define	XGI_FONT_FIXED				"fixed"
#define XGI_FONT_HELVETICA		"-adobe-helvetica-medium-r-normal--18-*-*-*-p-*-iso8859-1"
#define XGI_FONT_CLEAN				"-schumacher-clean-medium-r-normal-*-*-180-*-*-c-*-iso646.1991-irv*"

typedef struct xgiWidget_Simpletext_typedef {
	char 	*font;
	char 	*string;
} xgiWidget_Simpletext;

//
//  xgiCreateWidget_Simpletext
//
//	Creates a simpletext widget.
//
//	font					: the font to use (see the above font tags)
//	x/ypos				: the x and y position of the marker
//	string				: the text to print
//	alignment			: specifies how to print the text relative to the marker (see the above alignment tags)
//
xgiWidget *xgiCreateWidget_Simpletext(char *font, int xpos, int ypos, char *string, int alignment);

//
//  xgiWidget_Simpletext_draw
//
//	draws the widget in question
//
void	xgiWidget_Simpletext_draw(void *structure, int posx, int posy, int sizex, int sizey);

//
//	xgiWidget_Simpletext_destroy
//
//	frees all of the memory used by the structure of the widget
//
void xgiWidget_Simpletext_destroy(void *structure);


#endif
