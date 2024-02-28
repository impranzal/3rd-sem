#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int x1, x2, y1, y2, labelx, labely, Dx, Dy, k, p, x, y;
    cout << "Enter the inital coordinates: ";
    cin >> x1 >> y1;
    cout << "Enter the final coordinates: ";
    cin >> x2 >> y2;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    if (x2 > x1)
    {
        labelx = 1;
    }
    else
        labelx = -1;
    if (y2 > y1)
        labely = 1;
    else
        labely = -1;
    x = x1;
    y = y1;
    putpixel(x, y, WHITE);
    if (Dx > Dy)
    {
        p = 2 * Dy - Dx;
        for (k = 1; k < Dx; k++)
        {
            if (p < 0)
            {
                x = x + labelx;
                y = y;
                p = p + 2 * Dy;
            }
            else
            {
                x = x + labelx;
                y = y + labely;
                p = p + 2 * Dy - 2 * Dx;
            }
            putpixel(x, y, WHITE);
        }
    }
    else
    {
        p = 2 * Dx - Dy;
        for (k = 1; k < Dy; k++)
        {
            if (p < 0)
            {
                x = x;
                y = y + labely;
                p = p + 2 * Dy;
            }
            else
            {
                x = x + labelx;
                y = y + labely;
                p = p + 2 * Dx - 2 * Dy;
            }
            putpixel(x, y, WHITE);
        }
    }
    getch();
    closegraph();
}