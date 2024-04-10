#include <graphics.h>
#include <iostream>
#include <dos.h>
using namespace std;
void boundaryFill(int x, int y, int fill_color, int b_color)
{
    if (getpixel(x, y) != b_color && getpixel(x, y) != fill_color)
    {
        printf("\t\t******Boundary Fill******\n");
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
    void flood_fill(int x, int y, int new_color, int old_color)
    {
        if (getpixel(x, y) == old_color)
        {
            // delay(10);
            printf("\t\t******Flood Fill******");
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
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    setcolor(15);

    // circle(200, 200, 100);
    rectangle(100, 100, 300, 300);
    int choice;
    cout << "Choose Fill Algorithm:" << endl;
    cout << "1. Boundary Fill" << endl;
    cout << "2. Flood Fill" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        boundaryFill(220, 220, 4, 15);
        break;
    case 2:
        rectangle(100, 100, 250, 250);
        int x, y, old_color, new_color;
        cout << "Enter the seed point (x, y) to fill rectangle(200, 200, 250, 250): ";
        cin >> x >> y;
        cout << "Enter old color: ";
        cin >> old_color;
        cout << "Enter new color: ";
        cin >> new_color;
        flood_fill(x, y, new_color, old_color);
        break;
    default:
        cout << "Invalid choice!";
    }

    getch();
    closegraph();
}

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
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    setcolor(15);

    // circle(200, 200, 100);

    int choice;
    cout << "Choose Fill Algorithm:" << endl;
    cout << "1. Boundary Fill" << endl;
    cout << "2. Flood Fill" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        rectangle(100, 100, 300, 300);
        boundaryFill(220, 220, 4, 15);
        break;
    case 2:
        rectangle(100, 100, 250, 250);
        int x, y, old_color, new_color;
        cout << "Enter the seed point (x, y) to fill rectangle(200, 200, 250, 250): ";
        cin >> x >> y;
        cout << "Enter old color: ";
        cin >> old_color;
        cout << "Enter new color: ";
        cin >> new_color;
        flood_fill(x, y, new_color, old_color);

        break;
    default:
        cout << "Invalid choice!";
    }

    getch();
    closegraph();
}