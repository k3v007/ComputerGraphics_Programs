//clipping of circle is basically a case of either accept or reject on the basis of some condition (here whether it lies inside the clipping window or not)
//the checking condition is done while using the putpixel() function
//the clipping polygon must be convex
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX 10

using namespace std;

//x and y coordinate
typedef struct{
    int x;
    int y;
}coord;

//global clipping window
//the reason to declare it here is we are modifying the circle (mid-point) algorithm which is using the checkInside function
//and that needs the vertex of the clipping window
const int n = 6;    //no. of vertices/edges
coord vertex[n] = {{400, 350}, {650, 250}, {1000, 350}, {950, 650}, {700, 750}, {480, 650}};
//coord vertex[n] = {{500, 550}, {600, 350}, {700, 550}};   n = 4


bool checkInside(int x, int y)
{
    bool check = true;
    for (int i = 0; i < n; ++i){
        int dy = vertex[(i+1)%n].y - vertex[i].y;       //y2 - y1
        int dx = vertex[(i+1)%n].x - vertex[i].x;       //x2 - x1
        //the coefficients of the line equation
        int a = dy;
        int b = -dx;
        long int c = vertex[i].y * dx - vertex[i].x * dy;       //y1*dx - x1*dy

        int x1 = vertex[(i+2)%n].x, y1 = vertex[(i+2)%n].y;     //an inside point for the edge equation
        long long int eq1 = a*x + b*y + c;        //f(x, y) = ax + bx + c;
        long long int eq2 = a*x1 + b*y1 + c;      //f(x1, y1) = ax1, yb1 + c;

        //point should be inside w.r.t all the edges, if false for any edge then it doesn't lie inside the polygon
        if ((eq1 * eq2) < 0) {
           return false;
        }
    }

    //point lies inside the figure
    return true;
}

//for plotting 8 different points of circle using 8-symmetry
void pixel(int xc, int yc, int x, int y, int color, int outColor)
{
    //if the pixel lies inside the clipping window then color it with "color"
    //otherwise color it with "outColor"
    if (checkInside(xc + x, yc + y))
        putpixel(xc + x, yc + y, color);
    else
        putpixel(xc + x, yc + y, outColor);

    if (checkInside(xc + y, yc + x))
        putpixel(xc + y, yc + x, color);
    else
        putpixel(xc + y, yc + x, outColor);

    if (checkInside(xc - y, yc + x))
        putpixel(xc - y, yc + x, color);
    else
        putpixel(xc - y, yc + x, outColor);

    if (checkInside(xc - x, yc + y))
        putpixel(xc - x, yc + y, color);
    else
        putpixel(xc - x, yc + y, outColor);

    if (checkInside(xc - x, yc - y))
        putpixel(xc - x, yc - y, color);
    else
        putpixel(xc - x, yc - y, outColor);

    if (checkInside(xc - y, yc - x))
        putpixel(xc - y, yc - x, color);
    else
        putpixel(xc - y, yc - x, outColor);

    if (checkInside(xc + y, yc - x))
        putpixel(xc + y, yc - x, color);
    else
        putpixel(xc + y, yc - x, outColor);

    if (checkInside(xc + x, yc - y))
        putpixel(xc + x, yc - y, color);
    else
        putpixel(xc + x, yc - y, outColor);
}

//for drawing circle using mid-point algorithm
void circle_mpt(int xc, int yc, int r, int color1 = WHITE, int color2 = WHITE)
{
    int x = 0, y = r, d = 1 - r;
    pixel(xc, yc, x, y, color1, color2);

    while (x < y) {
        if (d < 0) {
            x++;
            d += (2 * x) + 3;
        }
        else {
            x++;
            y--;
            d += 2 * (x - y) + 5;
        }
        pixel(xc, yc, x, y, color1, color2);
    }
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;
    POINT cursorPos;

    while(!kbhit()) {
        settextstyle(10, HORIZ_DIR, 1);      setcolor(LIGHTBLUE);
        outtextxy(xc - 60, yc - 350, "Hover the Cursor!!");
        GetCursorPos(&cursorPos);

        //drawing the clipping polygon (it must be convex)
        setcolor(LIGHTRED);
        for (int i = 0; i < n; ++i)
            line(vertex[i].x, vertex[i].y, vertex[(i+1)%n].x, vertex[(i+1)%n].y);

        //drawing the circle which also includes clipping
        circle_mpt(cursorPos.x, cursorPos.y, 100, YELLOW, LIGHTGREEN);
        circle_mpt(cursorPos.x, cursorPos.y, 99, YELLOW, LIGHTGREEN);

        setactivepage(page);        setvisualpage(1 - page);        page = 1 - page;
        cleardevice();
    }

    getch();
    return 0;
}
