#include	"libs/xgi.h"
#include  "libs/xgiwidget_colorbox.h"
#include	"libs/xgiwidget_simpletext.h"


int main(int argc, char **argv) {
	xgiWidget *box;
	xgiWindow *window;

	xgiInit("xgi_test_01", argc, argv);
	
	xgiWindow *window1    = xgiCreateWindow("main_window", 275, 275, 100, 100, "xGI Test #1 - Window 1");
	
	printf("The windows have absolutly nothing to do with that stupid logo from Redmond.\n");
	
	xgiWidget *colorbox1	= xgiCreateWidget_Colorbox(	25,  25, 100, 100, XGI_COLORBOX_GREY);
	xgiWidget *colorbox2 	= xgiCreateWidget_Colorbox(	25, 150, 100, 100, XGI_COLORBOX_RED);
	xgiWidget *colorbox3	= xgiCreateWidget_Colorbox(150,  25, 100, 100, XGI_COLORBOX_BLUE);
	xgiWidget *colorbox4	= xgiCreateWidget_Colorbox(150, 150, 100, 100, XGI_COLORBOX_GREEN);
	xgiWidget *text				= xgiCreateWidget_Simpletext(XGI_FONT_CLEAN, 10, 20, "xGD-GI: Welcome!", XGI_SIMPLETEXT_LEFT);		// alignment dosen't work :p 
	
	xgiAddWidget(window1, colorbox1);
	xgiAddWidget(window1, colorbox2);
	xgiAddWidget(window1, colorbox3);
	xgiAddWidget(window1, colorbox4);
	xgiAddWidget(window1, text);
	
	xgiDisplayWindow(window1);
	
	xgiMainLoop();
	
	return 0;
}
