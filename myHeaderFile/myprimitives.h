#include <bits/stdc++.h>
#include <graphics.h>
#define PI          3.141593
#define rad(a)      PI / 180 * a
#define deg(a)      180 / PI * a

using namespace std;

//for plotting 8 different points of circle using 8-symmetry
void pixel(int xc,int yc,int x,int y, int color)
{
    putpixel(xc + x, yc + y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc - y, yc - x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc + x, yc - y, color);
}

//for drawing circle using mid-point algorithm
void circle_mpt(int xc, int yc, int r, int color = WHITE)
{
    int x = 0, y = r, d = 1 - r;
    pixel(xc, yc, x, y, color);

    while (x < y)
    {
        if (d < 0)
        {
            x++;
            d += (2 * x) + 3;
        }
        else
        {
            x++;
            y--;
            d += 2 * (x - y) + 5;
        }
        pixel(xc, yc, x, y, color);
    }
}


//for drawing line using mid-point algorithm which handles all the cases
void line_mpt (int x1, int y1, int x2, int y2, int color = WHITE)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1), xsign, ysign;
    bool compare;

    if (abs (x2 - x1) > abs (y2 - y1)) {    //major moment in x
        if ((x2 - x1) * (y2 - y1) > 0) {          //slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if (x1 > x2) {
                swap(x1, x2);   swap(y1, y2);
            }
        }
        else {      //slope is -ve: y + mx - c = 0
            xsign = 1, ysign = -1, compare = 0;
            if (x1 < x2) {
                swap(x1, x2);   swap(y1, y2);
            }
        }

        int x = x1, y = y1;
        int del = (dy * ysign) + (dx * xsign) / 2;
        putpixel(x, y, color);

        while (x != x2) {
            x -= xsign;
            if ((compare ? del < 0 : del > 0)) {
                del += (dy * ysign);
            }
            else {
                del += ((dy * ysign) + (dx * xsign));
                y++;
            }
            putpixel(x, y, color);
        }
    }
    else {      //major moment in y
        if ((x2 - x1) * (y2 - y1) > 0) {          //slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if (x1 > x2) {
                swap(x1, x2);   swap(y1, y2);
            }
        }
        else {      //slope is -ve: y + mx - c = 0
            xsign = 1, ysign = -1, compare = 0;
            if (x1 < x2) {
                swap(x1, x2);   swap(y1, y2);
            }
        }

        int x = x1, y = y1;
        int del = (dx * xsign) + (dy * ysign) / 2;
        putpixel(x, y, color);

        while (y != y2) {
            y ++;
            if ((compare ? del > 0 : del < 0)) {
                del += (dx * xsign);
            }
            else {
                del += ((dx * xsign) + (dy * ysign));
                x -= xsign;
            }
            putpixel(x, y, color);
        }
    }
}


void ellipse_bhm(int xc, int yc, int a, int b, int color = WHITE)
{
    int x = 0, y = b, aa = a * a, bb = b * b, d = aa + (2 * b * (b - a));
    while (bb * x < aa * y) {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc - x, yc - y, color);
        putpixel(xc + x, yc - y, color);
        if (d >= 0) {
            d += (4 * aa * (1 - y));
            y--;
        }       //addition of bb * (4 * x + 6) is common in both the case
        d += (bb * (4 * x + 6));
        x++;
    }

    x = a, y = 0, d = bb + 2 * a * (b + a);
    while (bb * x > aa * y) {
        putpixel(xc + x, yc + y, color);
        putpixel(xc - x, yc + y, color);
        putpixel(xc - x, yc - y, color);
        putpixel(xc + x, yc - y, color);
         if (d >= 0) {
            d += (4 * bb * (1 - x));
            x--;
        }
        d += (aa * (4 * y + 6));
        y++;
    }
}
