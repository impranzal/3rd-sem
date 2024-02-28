#include <graphics.h>
#include <stdio.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	ellipse(100, 100, 0, 360, 50, 90);
	getch();
	closegraph();
}