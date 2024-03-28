#include <graphics.h>
#include <iostream>
#include <dos.h>
using namespace std;
void boundaryFill(int x, int y, int fill_color, int b_color)
{
    if (getpixel(x, y) != b_color && getpixel(x, y) != fill_color)
    {
        // delay(2);
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, b_color);
        boundaryFill(x - 1, y, fill_color, b_color);
        boundaryFill(x, y + 1, fill_color, b_color);
        boundaryFill(x, y - 1, fill_color, b_color);
        // 8 connected points
        boundaryFill(x + 1, y + 1, fill_color, b_color);
        boundaryFill(x + 1, y - 1, fill_color, b_color);
        boundaryFill(x - 1, y + 1, fill_color, b_color);
        boundaryFill(x - 1, y - 1, fill_color, b_color);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    setcolor(15);
    // circle(200, 200, 100);
    rectangle(100, 100, 300, 300);
    boundaryFill(220, 220, 4, 15);
    getch();
    closegraph();
}