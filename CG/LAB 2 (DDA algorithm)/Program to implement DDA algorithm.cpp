// implement the DAA algorithm
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int x1, y1, x2, y2;
    cout << "Enter the starting coordinates (x,y): ";
    cin >> x1 >> y1;
    cout << "Enter the ending coordinates (x,y): ";
    cin >> x2 >> y2;
    int Dx = x2 - x1, Dy = y2 - y1, steps;
    if (abs(Dx) > abs(Dy))
    {
        steps = abs(Dx);
    }
    else
        steps = abs(Dy);
    int Xinc = Dx / steps, Yinc = Dy / steps;
    int x = x1, y = y1;

    // plotting the starting point
    putpixel(x, y, WHITE);
    for (int k = 0; k < steps; k++)
    {
        x = x + Xinc;
        y = y + Yinc;
        putpixel(round(x), round(y), WHITE);
    }
    getch();
    closegraph();
}