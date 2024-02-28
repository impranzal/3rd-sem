#include<graphics.h>
#include<conio.h>
#include<dos.h>
int main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm, "");
	//draw normal line
	line(100,100,200,100);
	//draw solid and thick line
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	line(100,150,200,150);
	//drawing dotted line
	setlinestyle(DOTTED_LINE,0,1);
	line(100,180,200,180);
	//drawing centere line
	setlinestyle(DASHED_LINE,0,1);
	line(100,200,200,200);
	//userbit line
	setlinestyle(USERBIT_LINE,0000000000000000,1);
	line(100,230,200,230);

	getch();
	closegraph();
	
}