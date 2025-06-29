#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

#define SCALE 6


void bresenham(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    int dx = x2 - x1;
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int y = y1;
    int yStep = (y2 > y1) ? 1 : -1;

    for (int x = x1; x <= x2; x++)
    {
        putpixel(x, y, WHITE);
        if (p >= 0)
        {
            y += yStep;
            p += 2 * (dy - dx);
        }
        else
        {
            p += 2 * dy;
        }
    }
}

int main()
{
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");
    int x1, y1, x2, y2;

    cout << "Enter the starting and end points: " << endl;
    cin >> x1 >> y1 >> x2 >> y2;

    bresenham(x1, y1, x2, y2);
    getch();

    return 0;
}
