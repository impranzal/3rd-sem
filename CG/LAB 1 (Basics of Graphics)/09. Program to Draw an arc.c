#include <graphics.h>
#include <stdio.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	arc(100, 100, 45, 90, 50);
	getch();
	closegraph();
}