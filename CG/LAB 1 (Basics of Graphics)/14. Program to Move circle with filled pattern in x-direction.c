// moving circle
#include <graphics.h> 
#include <iostream> 
#include<dos.h>
int main() 
{ 
	
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
    for(int i=0; i<=500;i++)
    {
 	
    setcolor(13);
	circle(250+i, 200,50);
	setfillstyle(9,4);
	floodfill(250+i,200,13);
	delay(50);
	cleardevice();
    }
	
	getch(); 
  
	
	closegraph(); 
} 
