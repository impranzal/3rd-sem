#include <graphics.h>
#include <stdio.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	line(320, 150, 400, 250);
	line(400, 250, 250, 350);
	line(250, 350, 320, 150);
	getch();
	closegraph();
}