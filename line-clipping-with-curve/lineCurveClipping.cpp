//Clipping w.r.t a curve is totally based on either accept or reject case of line drawing
//for this we colored the background of curve so that can be used to check the above case

//Hover the cursor slowly as rendering with floodfill is quite slow

#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         10
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)

using namespace std;

int pixcolor = GREEN;       //pixel color of curve
int bgcolor = LIGHTGREEN;   //background color of curve

//flood fill algorithm
void ffill(int x,int y,int fill,int old)
{
	if((getpixel(x,y) != old) && (getpixel(x, y) != fill)) {
		putpixel(x, y, fill);
		ffill(x + 1, y, fill, old);
		ffill(x - 1, y, fill, old);
		ffill(x, y + 1, fill, old);
		ffill(x, y - 1, fill, old);
	}
}

//modifying the mid-point algorithm of line for clipping
void line_mpt (int x1, int y1, int x2, int y2, int color1 = WHITE, int color2 = WHITE)
{
    int dx = abs(x2 - x1), dy = abs(y2 - y1), xsign, ysign;
    bool compare;

    if (abs (x2 - x1) > abs (y2 - y1)) {            //major moment in x
        if ((x2 - x1) * (y2 - y1) >= 0) {            //slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if ((x1 > x2) or ((x2 - x1) == 0 and (y1 > y2))) {
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
        //putpixel(x, y, color);

        while (x != x2) {
            x -= xsign;
            if ((compare ? del < 0 : del > 0)) {
                del += (dy * ysign);
            }
            else {
                del += ((dy * ysign) + (dx * xsign));
                y++;
            }
            if (getpixel(x, y) == bgcolor)      //this is the clipping case as line lies inside the curve
                putpixel(x, y, color2);
            else
                putpixel(x, y, color1);         //no clipping
        }
    }
    else {      //major moment in y
        if ((x2 - x1) * (y2 - y1) >= 0) {          //slope is +ve: mx - y + c = 0
            xsign = -1, ysign = 1, compare = 1;
            if ((x1 > x2) or ((x2 - x1) == 0 and (y1 > y2))) {
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
        //putpixel(x, y, color);

        while (y != y2) {
            y ++;
            if ((compare ? del > 0 : del < 0)) {
                del += (dx * xsign);
            }
            else {
                del += ((dx * xsign) + (dy * ysign));
                x -= xsign;
            }
            if (getpixel(x, y) == bgcolor)      //this is the clipping case as line lies inside the curve
                putpixel(x, y, color2);
            else
                putpixel(x, y, color1);         //no clipping
        }
    }
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxx() / 2, page = 0;
    xc -= 150,  yc -= 200;

    //hi of Hindi curve
    int hcrv = 13;
    int hi_Hindi[4][4*hcrv] = {     {0,0,0,0,        0,0,10,10,     10,10,10,10,     60,60,60,60,      70,70,70,70,        60,10,10,60,    70,25,25,70,       60,10,0,90,     70,100,100,60,   70,90,75,60,   70,30,10,90,    0,-30,20,65,       10,-15,20,65},
                                    {20,20,150,150,  20,20,20,20,   20,20,150,150,   150,150,140,140,  150,150,130,130,    140,140,90,90,  130,130,100,100,   90,90,30,0,     100,90,70,60,    80,75,70,60,   80,80,30,0,     160,215,245,165,   160,205,225,165},
                                    {0,10,0,0,       0,0,0,0,       0,10,0,0,        0,0,0,0,          0,0,0,0,            0,0,0,0,        0,0,0,0,           0,0,0,0,        0,0,0,0,         0,0,0,0,       0,0,0,0,        0,0,0,0,           0,0,0,0},
                                    {1,1,1,1,        1,1,1,1,       1,1,1,1,         1,1,1,1,          1,1,1,1,            1,1,1,1,        1,1,1,1,           1,1,1,1,        1,1,1,1,         1,1,1,1,       1,1,1,1,        1,1,1,1,           1,1,1,1}           };

    //n of Hindi curve
    int ncrv = 4;
    int n_Hindi[4][4*ncrv] = {  {100,100,160,160,   125,125,160,160,   100,105,125,125,   160,160,160,160},
                                {90,90,90,90,       80,80,80,80,       90,60,70,80,       90,90,80,80},
                                {0,0,0,0,           0,0,0,0,           0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1,           1,1,1,1,           1,1,1,1}  };

    //di of Hindi curve
    int dcrv = 12;
    int d_Hindi[4][4*dcrv] = {  {230,230,230,230,   240,240,240,240,    230,148,148,230,    240,158,158,230,    230,225,220,260,    240,235,230,260,    230,230,270,240,  270,270,270,270,   280,280,280,280,   270,270,280,280,   280,310,260,230,     270,295,260,230},
                                {150,150,140,140,   150,150,130,130,    140,130,30,40,      130,120,40,50,      40,30,20,10,        40,30,20,10,        50,80,40,40,      20,20,150,150,     20,20,150,150,     20,20,20,20,       160,215,245,165,     160,205,225,165},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,          0,0,0,0,           0,0,0,0,           0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,          1,1,1,1,           1,1,1,1,           1,1,1,1,           1,1,1,1}      };

    //horizontal bar of Hindi curve
    int lcrv = 10;
    int l_Hindi[4][4*lcrv] = {  {-20,-20,0,0,       10,10,270,270,      280,280,300,300,    -20,-20,0,0,        10,10,60,60,        70,70,230,230,      240,240,270,270,    280,280,300,300,    -20,-20,-20,-20,    300,300,300,300},
                                {160,160,160,160,   160,160,160,160,    160,160,160,160,    150,150,150,150,    150,150,150,150,    150,150,150,150,    150,150,150,150,    150,150,150,150,    150,150,160,160,    150,150,160,160},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1,            1,1,1,1}  };

    POINT cursorPos;
    cursorPos = {xc + 400, yc - 200};

    while(!kbhit()){
        settextstyle(10, HORIZ_DIR, 1);     setcolor(LIGHTRED);
        outtextxy(xc - 100, yc - 400, "Hold the Left-Shift key and Hover the CURSOR!!");
        //update the cursor position only if Left Shift is hold
        if(GetKeyState(VK_SHIFT) & 0x800)
            GetCursorPos(&cursorPos);

        //drawing the hi curve of Hindi
        for (int col = 0; col < 4 * hcrv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hi_Hindi[0][col] + 3 * pow(1-t, 2) * t * hi_Hindi[0][col+1] + 3 * (1-t) * t * t * hi_Hindi[0][col+2] + pow(t, 3) * hi_Hindi[0][col+3];
                y = pow(1-t, 3) * hi_Hindi[1][col] + 3 * pow(1-t, 2) * t * hi_Hindi[1][col+1] + 3 * (1-t) * t * t * hi_Hindi[1][col+2] + pow(t, 3) * hi_Hindi[1][col+3];
                putpixel(xc + x, yc - y, pixcolor);
            }
        }

        //drawing the n curve of Hindi
        for (int col = 0; col < 4 * ncrv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * n_Hindi[0][col] + 3 * pow(1-t, 2) * t * n_Hindi[0][col+1] + 3 * (1-t) * t * t * n_Hindi[0][col+2] + pow(t, 3) * n_Hindi[0][col+3];
                y = pow(1-t, 3) * n_Hindi[1][col] + 3 * pow(1-t, 2) * t * n_Hindi[1][col+1] + 3 * (1-t) * t * t * n_Hindi[1][col+2] + pow(t, 3) * n_Hindi[1][col+3];
                putpixel(xc + x, yc - y, pixcolor);
            }
        }

        //drawing the di curve of Hindi
        for (int col = 0; col < 4 * dcrv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * d_Hindi[0][col] + 3 * pow(1-t, 2) * t * d_Hindi[0][col+1] + 3 * (1-t) * t * t * d_Hindi[0][col+2] + pow(t, 3) * d_Hindi[0][col+3];
                y = pow(1-t, 3) * d_Hindi[1][col] + 3 * pow(1-t, 2) * t * d_Hindi[1][col+1] + 3 * (1-t) * t * t * d_Hindi[1][col+2] + pow(t, 3) * d_Hindi[1][col+3];
                putpixel(xc + x, yc - y, pixcolor);
            }
        }

        //drawing the horizontal bar of Hindi
        for (int col = 0; col < 4 * lcrv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * l_Hindi[0][col] + 3 * pow(1-t, 2) * t * l_Hindi[0][col+1] + 3 * (1-t) * t * t * l_Hindi[0][col+2] + pow(t, 3) * l_Hindi[0][col+3];
                y = pow(1-t, 3) * l_Hindi[1][col] + 3 * pow(1-t, 2) * t * l_Hindi[1][col+1] + 3 * (1-t) * t * t * l_Hindi[1][col+2] + pow(t, 3) * l_Hindi[1][col+3];
                putpixel(xc + x, yc - y, pixcolor);
            }
        }

        //filling the background of the curve
        ffill(xc + 5, yc - 25, bgcolor, pixcolor);
        ffill(xc + 110, yc - 85, bgcolor, pixcolor);
        //drawing the line and also performing the clipping
        line_mpt(xc - 200, yc + 50, cursorPos.x, cursorPos.y, YELLOW, BLACK);
        line_mpt(xc - 201, yc + 49, cursorPos.x-1, cursorPos.y-1, YELLOW, BLACK);

        setactivepage(page);        setvisualpage(1-page);
        page = 1 - page;            cleardevice();
    }

    getch();
    return 0;
}
