#include	"libs/xgi.h"
#include  "libs/xgiwidget_colorbox.h"
#include	"libs/xgiwidget_simpletext.h"

xgiWidget *box;
xgiWindow *window;

int main(int argc, char **argv) {
	xgiInit("xgi_test_01", argc, argv);
	
	xgiWindow *window1    = xgiCreateWindow("main_window", 275, 275, 100, 100, "xGI Test #1 - Window 1");
	xgiWindow *window2   	= xgiCreateWindow("secd_window", 275, 275, 475, 100, "xGI Test #2 - Window 2");
	
	xgiWidget *colorbox1	= xgiCreateWidget_Colorbox(	25,  25, 100, 100, XGI_COLORBOX_GREY);
	xgiWidget *colorbox2 	= xgiCreateWidget_Colorbox(	25, 150, 100, 100, XGI_COLORBOX_RED);
	xgiWidget *colorbox3	= xgiCreateWidget_Colorbox(150,  25, 100, 100, XGI_COLORBOX_BLUE);
	xgiWidget *colorbox4	= xgiCreateWidget_Colorbox(150, 150, 100, 100, XGI_COLORBOX_GREEN);
	
	xgiAddWidget(window1, colorbox1);
	xgiAddWidget(window1, colorbox2);
	xgiAddWidget(window1, colorbox3);
	xgiAddWidget(window1, colorbox4);
	
	xgiAddWidget(window2, colorbox1);
	xgiAddWidget(window2, colorbox2);
	xgiAddWidget(window2, colorbox3);
	xgiAddWidget(window2, colorbox4);
	xgiDisplayWindow(window1);
	xgiDisplayWindow(window2);
	
	xgiMainLoop();
	
	return 0;
}
