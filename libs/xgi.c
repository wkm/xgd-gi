#ifndef XGI_C
#define XGI_C

#include "xgi.h"

void xgiInit(char *name, int argc, char **argv)
{
	// glut initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	
	// xgi intialization
	_program 									= (xgiProgram *) malloc(sizeof(xgiProgram));
	
	// copy over the name
	_program->name 						= name;
	
	_program->windows 				= XGI_NULL;
	_program->numwindows 			= 0;
}

xgiWindow *xgiCreateWindow(char *name, int xsize, int ysize, int xpos, int ypos, char *title)
{
	int i = 0;
	
	xgiWindow *newWindow 			= (xgiWindow *) malloc(sizeof(xgiWindow));
	xgiWindow **oldWindows 		= (xgiWindow **) malloc(sizeof(xgiWindow *));
	
	newWindow -> name 				= name;
	newWindow -> xsize  			= xsize;
	newWindow -> ysize				= ysize;
	newWindow -> xpos					= xpos;
	newWindow -> ypos					= ypos;
	newWindow	-> title 				= title;
	newWindow	-> numwidgets 	= 0;
	newWindow -> initialized  = FALSE;
	newWindow -> displayfunc 	= xgiDrawWindow;
	newWindow -> resizefunc		= xgiResizeWindow;
	
	if(_program->numwindows != 0)
	{
		// copy the old window pointers
		for(i = 0; i < _program->numwindows; i++)
			oldWindows[i] = _program->windows[i];
	
		// copy the old window pointer plus the new window pointer over
		free(_program->windows);
	}
	
	_program->windows = (xgiWindow **) malloc(sizeof(xgiWindow *));
	
	for(i = 0; i < _program->numwindows; i++)
		_program->windows[i] = oldWindows[i];
	
	// add the new window
	_program->windows[_program->numwindows] = newWindow;
	
	_program->numwindows++;
		
	return newWindow;
}

void xgiMainLoop()
{
	glutMainLoop();
}

void xgiDisplayWindow(xgiWindow *window)
{
	glutInitWindowPosition(window->xpos, window->ypos);
	glutInitWindowSize(window->xsize, window->ysize);
	window->windowref = glutCreateWindow(window->title);
	window->initialized = TRUE;
	
	glutDisplayFunc(window->displayfunc);
	glutReshapeFunc(window->resizefunc);
}

void xgiDrawWindow()
{
	int i, j;

	// for each window
	for(j = 0; j < _program->numwindows; j++)
	{
		// dont want to mess with a window that hasn't been displayed yet
		if(_program->windows[j]->initialized == TRUE)
		{
			// say what window we want to screw with
			glutSetWindow(_program->windows[j]->windowref);
			
			// clear the screen (make it black)
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			glMatrixMode(GL_PROJECTION);

			// Set our coordinate system
			glOrtho(0, _program->windows[j]->xsize, _program->windows[j]->ysize, 0, -1, 1);
		
			// render each widget
			for(i = 0; i < _program->windows[j]->numwidgets; i++)
				xgiDrawWidget(_program->windows[j]->widgets[i]);
			
				glutSwapBuffers();
		}
	}
	
	glFlush();

}

void xgiResizeWindow(int width, int height)
{
	int windowref = glutGetWindow();
	int i = 0;
	
	// go thru every window in the program looking for the appropriate one (assuming
	// there is a window in the first place).
	if(_program->numwindows != 0)
	{
		for(i = 0; i < _program->numwindows; i++)
		{
			if(_program->windows[i]->windowref == windowref)
			{
				_program->windows[i]->xsize = width;
				_program->windows[i]->ysize = height;
			}
			glViewport(0, 0, width, height);
			glutPostRedisplay();
		}
	}
}

void xgiAddWidget(xgiWindow *window, xgiWidget *widget)
{
	xgiWidget **oldWidgets;
	int i = 0;	
	
	// copy the old widget pointers
	if(window->numwidgets != 0)
	{
		oldWidgets = (xgiWidget **) malloc(sizeof(xgiWidget *) * window->numwidgets);
		for(i = 0; i < window->numwidgets; i++)
			oldWidgets[i] = window->widgets[i];
		free(window->widgets);
	}
	
	// clear 
	window->widgets = (xgiWidget **) malloc(sizeof(xgiWidget *) * ++window->numwidgets);
	
	// copy the old pointers back (if there ever were any)
	if(window->numwidgets - 1 != 0)
	{
		for(i = 0; i < (window->numwidgets - 1); i++)
			window->widgets[i] = oldWidgets[i];
	}
	
	// add the new widget
	window->widgets[window->numwidgets - 1] = widget;
}

#endif
