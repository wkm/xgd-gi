#include "xgiwidget_colorbox.h"

xgiWidget *xgiCreateWidget_Colorbox(int xpos, int ypos, int xsize, int ysize, float red, float green, float blue)
{
	xgiWidget_colorbox *colorbox = (xgiWidget_colorbox*) malloc(sizeof(xgiWidget_colorbox));
	xgiWidget 				 *widget	 = (xgiWidget *) malloc(sizeof(xgiWidget));
	
	colorbox -> red     					= red;
	colorbox -> green   					= green;
	colorbox -> blue    					= blue;
	
	widget   -> xsize 						= xsize;
	widget	 -> ysize							= ysize;
	widget   -> xpos							= xpos;
	widget   -> ypos    					= ypos;
	widget   -> widgetdrawer			= xgiDrawWidgetColorbox;
	widget	 -> type							= "xgiwidget: colorbox";
	widget   -> widgetStructure	 	= (void *) colorbox;

	return widget;  	
}

void xgiDrawWidgetColorbox(void *structure, int xpos, int ypos, int xsize, int ysize)
{
	xgiWidget_colorbox *structureptr = (xgiWidget_colorbox *) structure;
	glColor3f(structureptr->red, structureptr->green, structureptr->blue);
	glRecti(xpos, ypos, xpos + xsize, ypos + ysize);
}

void xgiDestoryWidgetColorbox(void *structure)
{
	xgiWidget_colorbox *structureptr = (xgiWidget_colorbox *) structure;
	
	free(structureptr);
}
