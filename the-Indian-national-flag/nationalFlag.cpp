//The Indian National Flag drawn using standing wave
//Sorry for the saffron color as graphics.h doesn't support it; this code may be implemented in openGL also for the required color and animation
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         20
#define PI          (float)3.1416
#define rad(a)      ((a) * PI) / (float)180
#define COS(a)      cos(rad(a))
#define SIN(a)      sin(rad(a))
#define deg(a)      ((float)a * 180) / PI


using namespace std;


int lambda = 180;   //length of a wave (in pixels)
int gap = 60;       //width of each color in flag
float t, f = 10, n1 = 1.8, n2 = 1;      //t is for time and f is frequency; n1 and n2 controls the scaling of the wave
float delta = 0.01;     //used for comparing the float difference
float k = 2 * PI / lambda;      //wave number
float w = 2 * PI * f;           //angular wave frequency

int y1, y2, x1, x2;     //these variables are used for the starting/ending points of each horizontal/vertical wave


//for drawing the horizontal standing wave
void drawWaveH(int xc, int yc, int color, int s = 0)
{
    //xc and yc is the point from where the wave is drawn
    int amp = 10;
    //s is used for the starting/ending point of the wave
    for(float x = 20 + s; x < n1 * lambda + s; x += 0.01){
        //formula of standing wave in terms of y
        int y = amp * sin(k*x) * cos(w*t);
        if(abs(x - 20) <= delta)
            y1 = y;
        if(abs(x - n1 * lambda) <= delta)
            y2 = y;

        putpixel(xc + x, yc - y, color);
    }
}


//for drawing the vertical standing wave
void drawWaveV(int xc, int yc, int color, int s)
{
    //xc and yc is the point from where the wave is drawn
    int amp = 10;
    //s is used for the starting/ending point of the wave
    for(float y = s - 2; y < n2 * lambda + s + 2; y += 0.01){
        //formula of standing wave in terms of x
        int x = amp * sin(k*y) * cos(w*t);
        if(abs(y - gap - 5) <= delta)
            x1 = x;
        if(abs(y - 2 * gap - 5) <= delta)
            x2 = x;

        putpixel(xc + x, yc + y, color);
    }
}


int main()
{
    initwindow(1400, 1000);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;

    for(t = 0; !kbhit(); t+= 0.01){
        //Drawing the flag and coloring it
        drawWaveH(xc - 155, 120, WHITE);
        drawWaveH(xc - 155, 120 + 3 * gap, WHITE);
        drawWaveV(xc - 135, 120, WHITE, -y1);
        drawWaveV(xc - 157 + n1 * lambda, 120, WHITE, -y2);
        drawWaveH(xc - 155, 120 + gap, WHITE, x1);
        drawWaveH(xc - 155, 120 + 2 * gap, WHITE, x2);
        setcolor(WHITE);
        line(xc - 155, 115, xc - 135, 120 - y1);    line(xc - 155, 125 + 3 * gap, xc - 135, 120 - y1 + 3 * gap);
        setfillstyle(SOLID_FILL, LIGHTRED);         floodfill(xc - 75, 145, WHITE);
        setfillstyle(SOLID_FILL, WHITE);            floodfill(xc - 75, 145 + gap, WHITE);
        setfillstyle(SOLID_FILL, GREEN);            floodfill(xc - 75, 145 + 2 * gap, WHITE);

        //Drawing the Ashoka Chakra
        int r = gap / 2 - 2, xw = xc + 27, yw = 120 + 1.5 * gap + (2 * cos(w*t));
        setlinestyle(SOLID_LINE, 0, 4);         setcolor(BLUE);         circle(xw, yw, r);
        setlinestyle(SOLID_LINE, 0, 2);
        for(int a = 0; a < 180; a += 15)
            line(xw + r * COS(a), yw - r * SIN(a), xw - r * COS(a), yw + r * SIN(a));

        //Drawing the pole and the stand
        setlinestyle(SOLID_LINE, 0, 1);
        setcolor(LIGHTGRAY);                        setfillstyle(SOLID_FILL, LIGHTGRAY);
        circle(xc - 160, 88, 13);                   rectangle(xc - 165, 100, xc - 155, 850);
        fillellipse(xc - 160, 850, 40, 10);         fillellipse(xc - 160, 880, 40, 10);
        line(xc - 200, 850, xc - 200, 880);         line(xc - 120, 850, xc - 120, 880);
        fillellipse(xc - 160, 885, 70, 15);         fillellipse(xc - 160, 920, 70, 15);
        line(xc - 230, 885, xc - 230, 920);         line(xc - 90, 885, xc - 90, 920);
        floodfill(xc - 160, 140, LIGHTGRAY);        floodfill(xc - 160, 845, LIGHTGRAY);
        floodfill(xc - 160, 862, LIGHTGRAY);        floodfill(xc - 160, 902, LIGHTGRAY);
        setfillstyle(SOLID_FILL, YELLOW);           floodfill(xc - 160, 88, LIGHTGRAY);

        setcolor(YELLOW);           settextstyle(9, HORIZ_DIR, 1);
        outtextxy(xc + 100, yc, "\"THE INDIAN NATIONAL FLAG\"");

        //double buffering
        setactivepage(page);    setvisualpage(1 - page);
        page = 1 - page;        cleardevice();
    }

    getch();
    return 0;
}
