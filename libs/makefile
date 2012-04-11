#
# This file has been release under the General Public License
#
#

compiler		= gcc -g -Wall
cflags		= 
lflags		= -framework GLUT -framework OpenGL
copyer			= cp -u
libs				= .
objects			= xgd.o xgi.o xgi_widget.o xgiwidget_colorbox.o xgiwidget_simpletext.o



libraries: xgi xgiWidget xgiColorbox xgiSimpletext
	
xgi: $(libs)/xgi.c $(libs)/xgi.h
	$(compiler) $(cflags) $(libs)/xgi.c -c

xgiColorbox: xgiWidget $(libs)/xgiwidget_colorbox.c $(libs)/xgiwidget_colorbox.h
	$(compiler) $(cflags) $(libs)/xgiwidget_colorbox.c -c
	
xgiSimpletext: xgiWidget $(libs)/xgiwidget_simpletext.c $(libs)/xgiwidget_simpletext.h
	$(compiler) $(cflags) $(libs)/xgiwidget_simpletext.c -c	
	
xgiWidget: $(libs)/xgi_widget.h $(libs)/xgi_widget.c
	$(compiler) $(cflags) $(libs)/xgi_widget.c -c 
	
clean:
	rm -f *.o
	