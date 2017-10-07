#include "D:\Git Projects\see-saw-and-moving-wheel\myHeaderFile\myprimitives.h"
#define PI      3.141593
#define rad(a)  PI / 180 * a

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, r = 300, degcnt = 50, a = 25, sec = 50, disp = 50, page = 0, sa = 0, sign = 1, k = 0;

    while (!kbhit()) {
        for (int rot = 0; ; a -= sign, k += sign * 10, rot -= sign * 20, degcnt--) {
            setactivepage(page);        setvisualpage(1-page);      cleardevice();
            line_mpt(xc, yc, xc + 50, yc + 80), line_mpt(xc, yc, xc - 50, yc + 80), line_mpt(xc - 50, yc + 80, xc + 50, yc + 80);

            for (int j = 0; j < 5; ++j)
                line_mpt(xc + r * cos(rad(a)), yc - r * sin(rad(a)) - j, xc - (r * cos(rad(a))), yc + r * sin(rad(a)) - j);

            int cirx = xc - (r - disp - k) * cos(rad(a)), ciry = yc - 40 + (r - disp - k) * sin(rad(a)), cirR = 36;
            circle_mpt(cirx, ciry, cirR), circle_mpt(cirx, ciry, cirR - 1), circle_mpt(cirx, ciry, cirR - 2);
            circle_mpt(cirx, ciry, 4), circle_mpt(cirx, ciry, 5), circle_mpt(cirx, ciry, 30);

            for (int cnt = 0; cnt < 4; sa += sign * 45, cnt++)
                line_mpt(cirx + cirR * cos(rad(sa + rot)), ciry - cirR * sin(rad(sa + rot)), cirx - cirR * cos(rad(sa + rot)), ciry + cirR * sin(rad(sa + rot)));

            if (degcnt == 0)
                degcnt = 50,  sign *= -1;

            delay(sec);     page = 1 - page;
        }
    }

    getch();
    return 0;
}
