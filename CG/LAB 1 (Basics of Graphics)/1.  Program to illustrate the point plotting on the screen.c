#include<graphics.h>
#include<stdio.h>
int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm,"");
	putpixel(50,50, RED);
	getch();
	closegraph();
	return 0;
	
}