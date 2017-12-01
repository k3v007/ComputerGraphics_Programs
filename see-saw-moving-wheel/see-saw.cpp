#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         10
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)

//COS and SIN calculate the angle given in degree

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

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, r = 300, degcnt = 50, a = 25, sec = 65, disp = 50, page = 0, sa = 0, sign = 1, k = 0;
    //disp is used for the displacement of the circle from the extreme point of the plank as it can't go  till the end

    for (int rot = 0; !kbhit(); a -= sign, k += sign * 10, rot -= sign * 20, degcnt--) {
        //drawing the triangle
        line_mpt(xc, yc, xc + 50, yc + 80, LIGHTRED), line_mpt(xc, yc, xc - 50, yc + 80, LIGHTRED), line_mpt(xc - 50, yc + 80, xc + 50, yc + 80, LIGHTRED);

        //the sea-saw plank
        for (int j = 0; j < 5; ++j)
            line_mpt(xc + r * COS(a), yc - r * SIN(a) - j, xc - r * COS(a), yc + r * SIN(a) - j, BROWN);

        //centre of the moving circle
        int cirx = xc - (r - disp - k) * COS(a), ciry = yc - 40 + (r - disp - k) * SIN(a), cirR = 36;
        circle_mpt(cirx, ciry, cirR, GREEN), circle_mpt(cirx, ciry, cirR - 1, GREEN), circle_mpt(cirx, ciry, cirR - 2, GREEN);
        circle_mpt(cirx, ciry, 4, YELLOW), circle_mpt(cirx, ciry, 5, YELLOW), circle_mpt(cirx, ciry, 30, YELLOW);

        //drawing the spokes
        for (int cnt = 0; cnt < 4; sa += sign * 45, cnt++)
            line_mpt(cirx + cirR * COS(sa + rot), ciry - cirR * SIN(sa + rot), cirx - cirR * COS(sa + rot), ciry + cirR * SIN(sa + rot), YELLOW);

        //reseting the degree count and changing the nature of rotation
        if (degcnt == 0)
            degcnt = 50,  sign *= -1;

        //using setactivepage() and setvisualpage() to avoid flickering
        delay(sec);         setactivepage(page);        setvisualpage(1-page);
        page = 1 - page;    cleardevice();
    }

    getch();
    return 0;
}
