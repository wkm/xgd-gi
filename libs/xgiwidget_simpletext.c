#ifndef XGIWIDGET_SIMPLETEXT_C
#define XGIWIDGET_SIMPLETEXT_C

#include "xgiwidget_simpletext.h"

xgiWidget *xgiCreateWidget_Simpletext(char *font, int xpos, int ypos, char *string, int alignment)
{
	// Create the xgiWidget
	xgiWidget *widget 				  = (xgiWidget *) malloc(sizeof(xgiWidget));
	xgiWidget_Simpletext *text  = (xgiWidget_Simpletext *) malloc(sizeof(xgiWidget)); 
	
	widget -> name 							= string;
	widget -> type 							= "simpletext";
	
	widget -> xsize 						= 0;
	widget -> ysize 						= 0;
	
	widget -> xpos  						= xpos;
	widget -> ypos  						= ypos;
	widget -> widgetStructure 	= (void *) text;
	widget -> widgetdrawer			= xgiWidget_Simpletext_draw;
	widget -> widgetcallback		= XGI_NULL;
	widget -> widgetdestroyer		= xgiWidget_Simpletext_destroy;
	
	// Create the widgetStucture
	text   -> font							= font;
	text	 -> string						= string;
	
	return widget;
}

void xgiWidget_Simpletext_draw(void *structure, int x, int y, int sizex,int sizey)
{
	//
	// Acquire the font
	//
	GLuint 			 base;
	Display 		*display;
	XFontStruct *fontInfo;
	
	// cast our structure to the appropriate type
	xgiWidget_Simpletext *structureptr = (xgiWidget_Simpletext *) structure;
	
	base = glGenLists(96);
	display = XOpenDisplay(NULL);
	
	fontInfo = XLoadQueryFont(display, structureptr->font);
	
	if(fontInfo == NULL)
	{
		printf("ERROR: requested font \"%s\" does not exist.\n", structureptr->font);
		return;
	}
	
	// load the charecters from the font
	glXUseXFont(fontInfo->fid, 32, 96, base);
	
	XFreeFont(display, fontInfo);
	
	XCloseDisplay(display);
	
	//
	// Render the font
	//
	// position the text
	glRasterPos2i(x, y);
	
	// if there is no text to render, return.
	if(structureptr->string == NULL)
		return;
	
	glPushAttrib(GL_LIST_BIT);
	glListBase(base - 32);

	glCallLists(strlen(structureptr->string), GL_UNSIGNED_BYTE, structureptr->string);
	glPopAttrib();	
}

void xgiWidget_Simpletext_destroy(void *structure)
{
	xgiWidget_Simpletext *structureptr = (xgiWidget_Simpletext *) structure;
	free(structureptr->font);
	free(structureptr->string);
}

#endif
