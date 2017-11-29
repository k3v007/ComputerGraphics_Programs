#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         10
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
#define deg(a)      ((float)a * 180) / PI

using namespace std;

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

int main()
{
    initwindow(1100, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, R = 150, page = 0;

    //Program stops when any key is pressed on the keyboard
    for (int rot = 0; !kbhit(); rot ++){
        for (int a = -30 + rot; a <= 270 + rot; a += 60) {
            int x = xc + R  * COS(a), y = yc + R * SIN(a), n = 13, ang = 180 - (a) - 10, r = 5;
            circle_mpt(xc, yc, 15, RED);

            //Each cirlce design is drawn on the bigger circle circumference up to its 3/4th distance
            while (n > 0){
                //calculating centres of such circles
                int xx = x + R * COS(ang), yy = y - R * SIN(ang);
                circle_mpt(xx, yy, r, YELLOW);
                //upto 7 circles, their radius increases
                if (n > 7) {
                    //ang calculates the centre of the next circle
                    r += 5;         ang -= deg((2 * r + 1) / R);
                }
                else {
                    ang -= deg((2 * r + 1) / R);         r -= 5;
                }
                n--;
            }
        }
        delay(10);          setactivepage(page);        setvisualpage(1-page);
        page = 1 - page;    cleardevice();
    }

    getch();
    return 0;
}
