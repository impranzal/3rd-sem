// 2D transformations of a triangle
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
void display(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int xmax = getmaxx();
    int ymax = getmaxy();
    int xmid = getmaxx() / 2;
    int ymid = getmaxy() / 2;
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    line(x1 + xmid, y1 + ymid, x2 + xmid, y2 + ymid);
    line(x2 + xmid, y2 + ymid, x3 + xmid, y3 + ymid);
    line(x3 + xmid, y3 + ymid, x1 + xmid, y1 + ymid);
}
void translate(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
    outtextxy(100, 100, "Before Translation:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Translation:");
    display(x1 + tx, y1 + ty, x2 + tx, y2 + ty, x3 + tx, y3 + ty);
}

void scale(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy)
{
    outtextxy(100, 100, "Before Scaling:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Scaling:");
    display(x1 * sx, y1 * sy, x2 * sx, y2 * sy, x3 * sx, y3 * sy);
}
void arotate(int x1, int y1, int x2, int y2, int x3, int y3, int a)
{
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before Rotataion:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Rotataion:");
    display(x1 * c - y1 * s, x1 * s + y1 * c, x2 * c - y2 * s, x2 * s + y2 * c, x3 * c - y3 * s, x3 * s + y3 * c);
}
void crotate(int x1, int y1, int x2, int y2, int x3, int y3, int a)
{
    a = a * (3.1415 / 180);
    float c = cos(a);
    float s = sin(a);
    outtextxy(100, 100, "Before Rotataion:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Rotataion:");
    display(x1 * c + y1 * s, -x1 * s + y1 * c, x2 * c + y2 * s, -x2 * s + y2 * c, x3 * c + y3 * s, -x3 * s + y3 * c);
}
void xreflect(int x1, int y1, int x2, int y2, int x3, int y3)
{
    outtextxy(100, 100, "Before Reflection:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Reflection about x-axis:");
    display(x1, -y1, x2, -y2, x3, -y3);
}
void yreflect(int x1, int y1, int x2, int y2, int x3, int y3)
{
    outtextxy(100, 100, "Before Reflection:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Reflection about x-axis:");
    display(-x1, y1, -x2, y2, -x3, y3);
}
void xshear(int x1, int y1, int x2, int y2, int x3, int y3, float shx)
{
    outtextxy(100, 100, "Before Shearing:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Shearing about x-axis:");
    display(x1 + shx * y1, y1, x2 + shx * y2, y2, x3 + shx * y3, y3);
}
void yshear(int x1, int y1, int x2, int y2, int x3, int y3, float shy)
{
    outtextxy(100, 100, "Before Shearing:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Shearing about y-axis:");
    display(x1, y1 + shy * x1, x2, y2 + shy * x2, x3, y3 + shy * x3);
}
void xyshear(int x1, int y1, int x2, int y2, int x3, int y3, float shx, float shy)
{
    outtextxy(100, 100, "Before Shearing:");
    display(x1, y1, x2, y2, x3, y3);
    delay(3000);
    cleardevice();
    outtextxy(100, 100, "After Shearing about xy-axis:");
    display(x1 + shx * y1, y1 + shy * x1, x2 + shx * y2, y2 + shy * x2, x3 + shx * y3, y3 + shy * x3);
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    int gd = DETECT, gm;
    cout << "Enter the co-ordinates of the triangle: x1, y1, x2, y2, x3, y3:" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    while (1)
    {
        int ch;
        cout << "Enter:" << endl
             << "1. For Translation" << endl
             << "2. For Scaling" << endl
             << "3. For Anticlockwise Rotation" << endl
             << "4. For Clockwise Rotation" << endl
             << "5. For Reflection about x-axis" << endl
             << "6. For Reflection about y-axis" << endl
             << "7. For Shearing about x-axis" << endl
             << "8. For Shearing about y-axis" << endl
             << "9. For Shearing about xy-axis" << endl
             << "0. For Exit" << endl;
        cin >> ch;
        if (ch == 1)
        {
            int tx, ty;
            cout << "Enter Translation Factors tx and ty: " << endl;
            cin >> tx >> ty;
            initgraph(&gd, &gm, NULL);
            translate(x1, y1, x2, y2, x3, y3, tx, ty);
            getch();
            closegraph();
        }
        if (ch == 2)
        {
            float sx, sy;
            cout << "Enter Scaling Factors sx and sy: " << endl;
            cin >> sx >> sy;
            initgraph(&gd, &gm, NULL);
            scale(x1, y1, x2, y2, x3, y3, sx, sy);
            getch();
            closegraph();
        }
        if (ch == 3)
        {
            float a;
            cout << "Enter Rotation angle: " << endl;
            cin >> a;
            initgraph(&gd, &gm, NULL);
            arotate(x1, y1, x2, y2, x3, y3, a);
            getch();
            closegraph();
        }
        if (ch == 4)
        {
            float a;
            cout << "Enter Rotation angle: " << endl;
            cin >> a;
            initgraph(&gd, &gm, NULL);
            crotate(x1, y1, x2, y2, x3, y3, a);
            getch();
            closegraph();
        }
        if (ch == 5)
        {
            initgraph(&gd, &gm, NULL);
            xreflect(x1, y1, x2, y2, x3, y3);
            getch();
            closegraph();
        }
        if (ch == 6)
        {
            initgraph(&gd, &gm, NULL);
            yreflect(x1, y1, x2, y2, x3, y3);
            getch();
            closegraph();
        }
        if (ch == 7)
        {
            float shx;
            cout << "Enter Shearing factor shx: " << endl;
            cin >> shx;
            initgraph(&gd, &gm, NULL);
            xshear(x1, y1, x2, y2, x3, y3, shx);
            getch();
            closegraph();
        }
        if (ch == 8)
        {
            float shy;
            cout << "Enter Shearing factor shy: " << endl;
            cin >> shy;
            initgraph(&gd, &gm, NULL);
            yshear(x1, y1, x2, y2, x3, y3, shy);
            getch();
            closegraph();
        }
        if (ch == 9)
        {
            float shx, shy;
            cout << "Enter Shearing factors shx and shy: " << endl;
            cin >> shx >> shy;
            initgraph(&gd, &gm, NULL);
            xyshear(x1, y1, x2, y2, x3, y3, shx, shy);
            getch();
            closegraph();
        }
        if (ch == 0)
        {
            cout << "EXITED" << endl;
            break;
        }
    }

    return 0;
}