#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         10
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)

using namespace std;

//x- and y- coordinate
typedef struct{
    int x;
    int y;
}coord;

//Test condition of point inside a given convex polygon
bool checkInside(coord vertex[MAX], int n, int x, int y)
{
    bool check = true;
    for (int i = 0; i < n; ++i){
        int dy = vertex[(i+1)%n].y - vertex[i].y;       //y2 - y1
        int dx = vertex[(i+1)%n].x - vertex[i].x;       //x2 - x1
        int a = dy;
        int b = -dx;
        long long int c = vertex[i].y * dx - vertex[i].x * dy;      //y1*dx - x1*dy

        int x1 = vertex[(i+2)%n].x, y1 = vertex[(i+2)%n].y;         //an inside point for the edge equation
        long long int eq1 = a*x + b*y + c;        //f(x, y) = ax + bx + c;
        long long int eq2 = a*x1 + b*y1 + c;      //f(x1, y1) = ax1, yb1 + c;

        //point should be inside w.r.t all the edges if false for any edge then it doesn't lie inside
        if ((eq1 * eq2) < 0) {
           return false;
        }
    }

    //point lies inside the figure
    return true;
}

//Checking whether point lies inside the circle or not
bool insideCircle(int x, int y, int xc, int yc, int r)
{
    //using circle equation, we have f(x,y) = (x-h)^2 + (y-k)^2 - r^2
    long long sum = 0;
    sum = pow((x-xc), 2) + pow((y-yc), 2) - pow(r, 2);
    if (sum < 0)
        return true;
    else
        return false;
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;

    int crv = 6;    //no. of curves
    //each curve is stored as 4 control points P1, P2, P3, P4 column wise, and each column as [x y z 1]
    //oop curve
    int curve[4][4*crv] = {     {-80,-40,-40,-80,       -80,-120,-120,-80,     0,-40,-40,0,       0,40,40,0,        50,50,50,50,        50,120,120,50},
                                {40,40,-40,-40,         40,40,-40,-40,         40,40,-40,-40,     40,40,-40,-40,    40,40,-100,-100,    40,60,-60,-40},
                                {0,0,0,0,               0,0,0,0,               0,0,0,0,           0,0,0,0,          0,0,0,0,            0,0,0,0},
                                {1,1,1,1,               1,1,1,1,               1,1,1,1,           1,1,1,1,          1,1,1,1,            1,1,1,1}  };

    POINT cursorPos;
    //initially setting the cursor position to the mid-point of the screen
    cursorPos = {xc, yc};

    long long int a = 0;
    while(!kbhit()) {
        settextstyle(10, HORIZ_DIR, 1);     setcolor(YELLOW);
        outtextxy(xc - 220, yc - 300, "Hold Left-Shift key and Hover the Cursor!!");

        //Update the cursor position only if Left Shift key is pressed
        if (GetKeyState(VK_SHIFT) & 0x8000)
            GetCursorPos(&cursorPos);

        setcolor(LIGHTGREEN);
        //storing the cursor position
        int curx = cursorPos.x, cury = cursorPos.y;

        //outer circle
        circle(curx, cury, 200);        circle(curx, cury, 201);
        //d is the distance from the centre of the outer circle, the three shapes are drawn
        int d = 60;

        //coordinates of rectangle
        coord rect[4] = {   {curx + d*COS(a-47), cury - d*SIN(a-47)},
                            {curx + d*COS(a+47), cury - d*SIN(a+47)},
                            {curx + (d+85)*COS(a+19), cury - (d+85)*SIN(a+19)},
                            {curx + (d+85)*COS(a-19), cury - (d+85)*SIN(a-19)}  };

        //coordinates of triangle
        coord tri[3] = {    {curx + d*COS(a+120-47), cury - d*SIN(a+120-47)},
                            {curx + d*COS(a+120+47), cury - d*SIN(a+120+47)},
                            {curx + (d+85)*COS(a+120), cury - (d+85)*SIN(a+120)}    };

        //coordinates of inside circle
        coord cir = {curx +(d+25)*COS(a+240), cury -(d+25)*SIN(a+240)};

        setcolor(LIGHTBLUE);
        //drawing the rectangle
        for(int i = 0; i < 4; ++i)
            line(rect[i].x, rect[i].y, rect[(i+1)%4].x, rect[(i+1)%4].y);

        //drawing the triangle
        for(int i = 0; i < 3; ++i)
            line(tri[i].x, tri[i].y, tri[(i+1)%3].x, tri[(i+1)%3].y);

        //drawing the circle
        circle(cir.x, cir.y, 50);

        for (int col = 0; col < 4 * crv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * curve[0][col] + 3 * pow(1-t, 2) * t * curve[0][col+1] + 3 * (1-t) * t * t * curve[0][col+2] + pow(t, 3) * curve[0][col+3];
                y = pow(1-t, 3) * curve[1][col] + 3 * pow(1-t, 2) * t * curve[1][col+1] + 3 * (1-t) * t * t * curve[1][col+2] + pow(t, 3) * curve[1][col+3];
                //clipping is done when the point lies outside the inside rectangle, triangle or circle
                //only then they are not displayed
                if (checkInside(rect, 4, xc + x, yc - y) or checkInside(tri, 3, xc + x, yc - y) or insideCircle(xc + x, yc - y, cir.x, cir.y, 50) or !insideCircle(xc + x, yc - y, curx, cury, 200))
                    putpixel(xc + x, yc - y, LIGHTRED);
            }
        }

        a--;
        delay(10);          setactivepage(page);        setvisualpage(1-page);
        page = 1 - page;    cleardevice();
    }

    getch();
    return 0;
}
