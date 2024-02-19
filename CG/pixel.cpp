#include<graphics.h>

#include<stdio.h>
int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm,"");
	putpixel(50,50, RED);
	int pix=getpixel(50,50);
	printf("The value is : %d" ,pix);
	getch();
	closegraph();
	return 0;
	
}
