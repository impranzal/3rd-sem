#include<graphics.h>
#include<stdio.h>
int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm,"");
	putpixel(50,50, RED);
	int color=getpixel(50,50);
	printf("The colour of your pixel is : %d" ,color);
	getch();
	closegraph();
	return 0;
	
}