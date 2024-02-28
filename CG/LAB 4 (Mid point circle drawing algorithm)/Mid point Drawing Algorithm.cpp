#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int radius, x1, y1, p, k = 0;
    cout << "Enter the radius of circle: ";
    cin >> radius;
    cout << "Enter the centre coordinates of circle: ";
    cin >> x1 >> y1;
    p = 5 / 4 - radius;
    int x = 0, y = radius;
    while (y > x)
    {
        putpixel(x + x1, y + y1, 1);
        putpixel(-x + x1, y + y1, 2);
        putpixel(x + x1, -y + y1, 3);
        putpixel(-x + x1, -y + y1, 4);
        putpixel(y + x1, x + y1, 5);
        putpixel(-y + x1, x + y1, 6);
        putpixel(y + x1, -x + y1, 7);
        putpixel(-y + x1, -x + y1, 8);
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * x + 1 - 2 * y;
        }
        delay(50);
    }
    getch();
    closegraph();
}