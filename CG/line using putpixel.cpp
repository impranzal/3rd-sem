#include <graphics.h> 
#include<dos.h>


// driver code 
int main() 
{ 
	
	int gd = DETECT, gm; 


	initgraph(&gd, &gm, ""); 
	
	setcolor(14);  //Gives line new colour
	
	setbkcolor(10);  //Gives background colour

	// line for x1, y1, x2, y2 
	for (int i=1; i<=500; i++)
	{
		delay(10);
		putpixel(i,200,150);
	}

	getch(); 
 
	closegraph(); 
}
