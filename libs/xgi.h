//
//  xGD Glut Intrface Libraries
//

#ifndef XGI_H
#define XGI_H

#include <GL/glut.h>
#include <GL/gl.h>


#define XGI_DEPTH 			GLUT_DEPTH
#define XGI_SINGLE			GLUT_SINGLE
#define	XGI_RGBA				GLUT_RGBA
#define XGI_NULL				0

#define TRUE						't'
#define FALSE						'f'

#include "xgi_widget.h"

//
//	xgiWindow
//
//	Structure that defines a window.
//
//	name			: the associated name of the window
//	x/ysize		: the x and y size of the window
//	x/ypos		: the x and y position of the window
//	title			: the title of the window
//	widgets		: an array specifying the widgets to use with the window
//
typedef struct xgiWindow_typedef {
	char 				*name;
	int					 xsize; int ysize;
	int   			 xpos;  int ypos;
	char 				*title;
	int					 windowref;
	char         initialized;

	xgiWidget  **widgets;
	int 				 numwidgets;
	
	void			 (*displayfunc)(void);
	void			 (*resizefunc)(int width, int height);
} xgiWindow;


//
//	xgiProgram
//	
//	Structure that defines a program (all information is initialized by
//	xgiInit.
//
//  name			: name of the resource file to use and also used for
//							printing debugging information.
//	windows		: an array of memory locations that define all windows related
//							to the xgi program. Each element in the array points to a
//							xgiWindow.
//	numwindows:	the number of elements in the windows array.
//
typedef struct xgiProgram_typedef {
	char 				 *name;
	
	xgiWindow		**windows;
	int 					numwindows;	
} xgiProgram;

static xgiProgram *_program;

//
//	xgiInit
//	
//	initalizes glut and xgi.
//
//	argc:	passed directly to glut
//	argv:	passed directly to glut
//	name: name of the program, used with the
//	
void xgiInit(char *name, int argc, char **argv);

//
//	xgiCreateWindow
//
//  Creates a window using the specified parameters:
//
//		name						: used within xgi to refer to the window
//		size_x/y				: the x and y size of the window
//		position_x/y		: the x and y position of the window
//		title						: the title of the window
//
xgiWindow *xgiCreateWindow(char *name, int size_x, int size_y, int position_x, int position_y, char *title);

//
//  xgiDisplayFunc
//
//	Pipes directly to glutDisplayFunc
//
void xgiDisplayFunc(void (*func)(void));

//
//	xgiMainLoop
//
//	Pipes directly to glutMainLoop();
//
void xgiMainLoop();

//
//	xgiDestory
//
//	Frees all memory used by the program that is xgi releated.
//
void xgiDestory();

//
//	xgiDisplayFunc
//
//	Tells xgiDrawWindow what function to call befure drawing all
//	of the widgets.
//
void xgiDisplayFunc(void (*func)(void));

//
//	xgiDisplayWindow
//
//	Function which renders the window
//
void xgiDisplayWindow(xgiWindow *window);

//
//	xgiDrawWindow
//
//	Function which renders all windows (at once).
//
void xgiDrawWindow();

//
//	xgiResizeWindow
//
//	Function which sets the window's size accordingly
//
void xgiResizeWindow(int x, int y);

//
//	xgiAddWidget
//
//	Function which adds a widget to the specified window
//
void xgiAddWidget(xgiWindow *window, xgiWidget *widget);

#endif
