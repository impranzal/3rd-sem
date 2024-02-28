// C++ Implementation for drawing line 
#include <graphics.h> 
#include<conio.h>
int main() 
{ 
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	// line with default color 
	line(150, 150, 450, 150); 
    // line with user defined colour
    setcolor(RED);
    line(200, 200, 400, 200); 
    
	getch(); 
	closegraph(); 
} 
