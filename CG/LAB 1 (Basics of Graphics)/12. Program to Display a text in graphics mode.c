#include <graphics.h>
#include <stdio.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	setcolor(RED);
	outtextxy(100, 100, "Suresh Shahi...");
	getch();
	closegraph();
}