#include <graphics.h>
#include <stdio.h>
#include <dos.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	putpixel(50, 50, RED);
	int color = getpixel(50, 50);
	delay(10000);
	// setcolor(WHITE);
	setbkcolor(WHITE);
	getch();
	closegraph();
	return 0;
}