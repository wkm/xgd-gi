compiler	= gcc 
cflags		= -I/usr/X11R6/include
lflags		= -L/usr/include -lGL -lGLU -lglut -L/usr/X11R6/lib -lXaw -lXt -lXmu -lX11 -lm -lXi
copyer		= cp -u
libdir		= libs
libs		= $(libdir)/xgi.o $(libdir)/xgiwidget_colorbox.o $(libdir)/xgiwidget_simpletext.o $(libdir)/xgi_widget.o

test: tester.o $(libs)
	$(compiler) $(lflags) tester.o $(libs) -o xgi_test
	
tester.o: tester.c $(libs)
	$(compiler) $(cflags) tester.c -c
	
clean:
	rm -f xgi_test *.o
