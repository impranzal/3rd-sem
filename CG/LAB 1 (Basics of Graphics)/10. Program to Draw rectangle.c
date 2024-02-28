#include<graphics.h>
#include<stdio.h>
int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm,"");
	rectangle(100,100,200,200);
	getch();
	closegraph();
	
}