compiler	= gcc 
cflags		= -framework GLUT -framework OpenGL
lflags		= -framework GLUT -framework OpenGL
copyer		= cp -u
libdir		= libs
libs		= $(libdir)/xgi.o $(libdir)/xgiwidget_colorbox.o $(libdir)/xgiwidget_simpletext.o $(libdir)/xgi_widget.o

test: tester.o $(libs)
	$(compiler) $(lflags) tester.o $(libs) -o xgi_test
	
tester.o: tester.c $(libs)
	$(compiler) $(cflags) tester.c -c
	
clean:
	rm -f xgi_test *.o
