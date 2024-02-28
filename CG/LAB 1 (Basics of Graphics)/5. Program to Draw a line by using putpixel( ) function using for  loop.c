#include <graphics.h> 
#include<conio.h>
#include<dos.h>

int main() 
{ 
	
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 

	for (int i=1; i<=500; i++)
	{
		delay(100);
		putpixel(100+i, 100+i, RED);
	}

	getch(); 
	closegraph(); 
} 
