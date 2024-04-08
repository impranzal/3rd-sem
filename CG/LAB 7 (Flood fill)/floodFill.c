/*4 and 8 connected flood fill algorithm*/
#include <graphics.h>
#include <iostream>
#include <dos.h>
using namespace std;
void flood_fill(int x, int y, int new_color, int old_color)
{
    if (getpixel(x, y) == old_color)
    {
        // delay(10);
        putpixel(x, y, new_color);
        flood_fill(x + 1, y, new_color, old_color);
        flood_fill(x - 1, y, new_color, old_color);
        flood_fill(x, y + 1, new_color, old_color);
        flood_fill(x, y - 1, new_color, old_color);
        // 8-connected

        flood_fill(x + 1, y + 1, new_color, old_color);
        flood_fill(x + 1, y - 1, new_color, old_color);
        flood_fill(x - 1, y + 1, new_color, old_color);
        flood_fill(x - 1, y - 1, new_color, old_color);
    }
}

int main()
{
    int gd = DETECT, gm, x, y, old_color, new_color;
    initgraph(&gd, &gm, (char *)"");
    rectangle(100, 100, 250, 250);
    printf("Enter the seed point (x, y) to fill rectangle(200, 200, 250, 250):");
    scanf("%d%d", &x, &y);
    printf("Enter old color: ");
    scanf("%d", &old_color);
    printf("Enter new color: ");
    scanf("%d", &new_color);
    // flood_fill(220, 220, 4, 0);
    // give the interior values only
    // if the boundary values are given then it doesn't work
    // and the important point is to pass the color of the interior pixels that is black- color code: 0
    flood_fill(x, y, new_color, old_color);
    getch();
    closegraph();
    return 0;
}