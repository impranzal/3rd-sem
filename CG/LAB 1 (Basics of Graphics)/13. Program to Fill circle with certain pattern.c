//circle filling by using setfillstyle() and floodfill()
#include <graphics.h> 
#include <iostream> 

int main() 
{ 
	
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	setfillstyle(7,RED);
    circle(250, 200,100);
	floodfill(250,200,15);
	getch(); 
	closegraph(); 
} 
