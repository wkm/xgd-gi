//
//	xgiwidget_colorbox.h
//
//	Defines a widget that draws a box with a solid color inside.
//
#ifndef XGIWIDGET_COLORBOX_H
#define XGIWIDGET_COLORBOX_H
#include <GL/gl.h>

#include "xgi_widget.h"


//
// Various Colors
//
#define XGI_COLORBOX_RED							1.0, 0.0, 0.0
#define XGI_COLORBOX_GREEN						0.0, 1.0, 0.0
#define XGI_COLORBOX_BLUE							0.0, 0.0, 1.0
#define XGI_COLORBOX_WHITE						1.0, 1.0, 1.0
#define XGI_COLORBOX_GREY							0.5, 0.5, 0.5
#define XGI_COLORBOX_BLACK						0.0, 0.0, 0.0

typedef struct xgiWidget_colorbox_typedef {
	float red;
	float green;
	float blue;	
} xgiWidget_colorbox;

//
//	xgiCreateWidgetColorbox
//
//	Creates a color *rectangle* based on the given x/y size, and x/y pos
//	where red, green, and blue are the fill color.
//
xgiWidget *xgiCreateWidget_Colorbox(int xpos, int ypos, int xsize, int ysize, float red, float green, float blue);

//
//	xgiDrawWidgetColorbox
//
//	Draws the colorbox.
//
void xgiDrawWidgetColorbox(void *structure, int xpos, int ypos, int xsize, int ysize);

//
//	xgiDestroyWidgetColorbox
//
//	Frees all of the memory used by the xgiWidget Colorbox
//
void xgiDestroyWidgetColorbox(void *structure);

#endif
