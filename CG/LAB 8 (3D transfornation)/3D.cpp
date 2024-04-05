#include <graphics.h>
#include <math.h>
#include <iostream>
using namespace std;
// bar3d function in c
// Declaration: void bar3d(int left, int top, int right, int bottom, int depth, int topflag);
// bar3d function is used to draw a 2-dimensional, rectangular filled in bar .
// Coordinates of left top and right bottom corner of bar are required to draw the bar.
// left specifies the X-coordinate of top left corner, top specifies the Y-coordinate of top left corner,
// right specifies the X-coordinate of right bottom corner, bottom specifies the Y-coordinate of right bottom corner,
// depth specifies the depth of bar in pixels, topflag determines whether a 3 dimensional top is put on the bar or not
//( if it's non-zero then it's put otherwise not ). Current fill pattern and fill color is used to fill the bar.
// To change fill pattern and fill color use setfillstyle.
void display(int x1, int y1, int x2, int y2, int z)
{
    int xmid = getmaxx() / 2;
    int ymid = getmaxx() / 2;
    line(xmid, 0, xmid, getmaxy());
    line(0, ymid, getmaxx(), ymid);
    bar3d(xmid + x1, ymid + y1, xmid + x2, ymid + y2, z, 1);
}
void translate(int x1, int y1, int x2, int y2, int z, int tx, int ty, int tz)
{
    outtextxy(100, 100, "Before Translation:");
    display(x1, y1, x2, y2, z);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Translation:");
    display(x1 + tx, y1 + ty, x2 + tx, y2 + ty, z + tz);
}
void scale(int x1, int y1, int x2, int y2, int z, float sx, float sy, float sz)
{
    outtextxy(100, 100, "Before Scaling:");
    display(x1, y1, x2, y2, z);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Scaling:");
    display(x1 * sx, y1 * sy, x2 * sx, y2 * sy, z * sz);
}
void xrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    //	x' = x
    //	y' = ycosA - zsinA
    //	z' = ysinA + zcosA
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before Rotation:");
    display(x1, y1, x2, y2, z);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Rotation:");
    display(x1, y1 * c - z * s, x2, y2 * c - z * s, ((y1 + y2) / 2) * s + z * c);
}
void yrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    //	x' = xcosA + zsinA
    //	y' = y
    //	z' = zcosA + xsinA
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before Rotation:");
    display(x1, y1, x2, y2, z);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Rotation:");
    display(x1 * c + z * s, y1, x2 * c + z * s, y2, z * c - ((x1 + x2) / 2) * s);
}
void zrotate(int x1, int y1, int x2, int y2, int z, float a)
{
    //	x' = xcosA - ysinA
    //	y' = xsinA + ycosA
    //	z' = z
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before Rotation:");
    display(x1, y1, x2, y2, z);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Rotation:");
    display(x1 * c - y1 * s, x1 * s + y1 * c, x2 * c - y2 * s, x2 * s + y2 * c, z);
}
int main()
{
    int x1, y1, x2, y2, z;
    int gd = DETECT, gm;
    cout << "Enter the coordinates of the digonal points of 3D object: x1, y1, x2, y2, z:" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> z;
    while (1)
    {
        int ch;
        cout << "Enter Your Choice:" << endl
             << "1-Translation" << endl
             << "2-Scaling" << endl
             << "3-Rotation about X-axis" << endl
             << "4-Rotation about Y-axis" << endl
             << "5-Rotation about Z-axis" << endl
             << "0-EXIT" << endl;
        cin >> ch;
        if (ch == 1)
        {
            int tx, ty, tz;
            cout << "Enter tx, ty, and tz:" << endl;
            cin >> tx >> ty >> tz;
            initgraph(&gd, &gm, NULL);
            translate(x1, y1, x2, y2, z, tx, ty, tz);
            getch();
            closegraph();
        }
        else if (ch == 2)
        {
            float sx, sy, sz;
            cout << "Enter Sx, Sx, and Sz:" << endl;
            cin >> sx >> sy;
            initgraph(&gd, &gm, NULL);
            scale(x1, y1, x2, y2, z, sx, sy, sz);
            getch();
            closegraph();
        }
        else if (ch == 3)
        {
            float a;
            cout << "Enter Angle:" << endl;
            cin >> a;
            initgraph(&gd, &gm, NULL);
            xrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 4)
        {
            float a;
            cout << "Enter Angle:" << endl;
            cin >> a;
            initgraph(&gd, &gm, NULL);
            yrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 5)
        {
            float a;
            cout << "Enter Angle:" << endl;
            cin >> a;
            initgraph(&gd, &gm, NULL);
            zrotate(x1, y1, x2, y2, z, a);
            getch();
            closegraph();
        }
        else if (ch == 0)
        {
            cout << "EXITED" << endl;
            break;
        }
    }
    return 0;
}