#ifndef XGI_WIDGET_C
#define XGI_WIDGET_C

#include "xgi_widget.h"

void xgiDrawWidget(xgiWidget *widget)
{
	widget->widgetdrawer(widget->widgetStructure, widget->xpos, widget->ypos, widget->xsize, widget->ysize);
}

void xgiDestroyWidget(xgiWidget *widget)
{
	if(widget->name != XGI_NULL)
		free(widget->name);
	
	if(widget->type != XGI_NULL)
		free(widget->type);
	
	widget->widgetdestroyer(widget->widgetStructure);
	
	if(widget->widgetStructure != XGI_NULL)
		free(widget->widgetStructure);
}

#endif
