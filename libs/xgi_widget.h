//
//	xgiWidget
//
//	Structure that defines a base widget (has a name and a type) and provides
//	a pointer space to the actual widget structure, the widget drawing function,
//	a callback for when the widget is clicked, and the widgetdestroying function.
//
//  Addittionally support for the callback function is provided thru the 4 integers
//	defining the rectangle the widget is in (or isn't the callback is called if the
//	user clicks in the particular area of the window).  
//
//		name						: the name of the widget
//		type						: the widget type
//		widgetstructure : the actual data the widget needs
//		widgetdrawer		: the function which draws the widget
//		widgetcallback	: the function to call when the user clicks withing the hot
//											rectangle
//		widgetdestroyer	: the function to call when the widget is destroyed
//    
//	For an example widget, please see the simpletext widget ( xgiwidget_simpletext.h )
//

#ifndef XGI_WIDGET_H
#define XGI_WIDGET_H

#define	XGI_NULL 0

typedef struct xgiWidget_typedef {
	// Parameters:
	char 				 *name;
	char				 *type;
	
	int						xsize;
	int						ysize;
	int						xpos;
	int						ypos;
	
	void				 *widgetStructure;
	void				(*widgetdrawer)(void *structure, int xp, int yp, int xs, int ys);
	void				(*widgetcallback)(void);
	void				(*widgetdestroyer)(void *struc);
} xgiWidget;

void xgiDrawWidget(xgiWidget *widget);

void xgiDestroyWidget(xgiWidget *widget);

#endif
