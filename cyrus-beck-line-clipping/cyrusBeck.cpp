//Cyrus Beck algorithm for line clipping, it can handle any polygon : convex or concave
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX 100
#define     ff      first
#define     ss      second

using namespace std;

//for x and y coordinate
typedef struct{
    int x;
    int y;
}coord;

//used in Normal vector calculation (using CW rotation)
//      Edge        Normal
//      + +          - +
//      + -          + +
//      - -          + -
//      - +          - -
void calcSign(int &x, int &y)
{
    //using CW wise rotation
    if ((x >= 0 and y >= 0) and (x < 0 and y < 0))
        x *= -1;
    else
        y *= -1;
}

//returns dot product of two vectors
int dotprod(coord a, coord b)
{
    return (a.x * b.x) + (a.y * b.y);
}

//returns t parameter
float tfunc(coord e1, coord e2, coord l1, coord l2)
{
    coord edge = {e2.x - e1.x, e2.y - e1.y};
    //calculating the sign of x and y,
    int xsig = (edge.x >= 0) ? 1 : -1;
    int ysig = (edge.y >= 0) ? 1 : -1;
    //changing it according to the rule for Normal
    calcSign(xsig, ysig);
    coord norm = {xsig * abs(edge.y), ysig * abs(edge.x)};
    int Nr = dotprod(norm, {l1.x - e1.x, l1.y - e1.y});         // N.(p1 - Ei)
    int Dr = - dotprod(norm, {l2.x - l1.x, l2.y - l1.y});       //-N.(p2 - p1)

    float t;
    if (Dr != 0) {
        t = (float)Nr / (float)Dr;
        return t;
    }
    else
        return 10;
}

//t parameter should lie between 0 and 1
//and it is calculated from both the reference that is edge and line and then edge as line and line as edge
//if they intersect then t value should be between 0 and 1 w.r.t both of them
void cyrusBeck(coord vertex[MAX], int n, coord p1, coord p2, vector<float> &tval)
{
    for (int i = 0; i < n; ++i){
        float t1 = tfunc(vertex[i], vertex[(i+1)%n], p1, p2);
        float t2 = tfunc(p2, p1, vertex[i], vertex[(i+1)%n]);
        //cout << t1 << " " << t2 << "\n\n";
        if (t1 >= 0 and t1 <= 1){
            if (t2 >= 0 and t2 <= 1)
                tval.push_back(t1);
        }
    }
    if (tval.size() & 1)
        tval.push_back(1);

    sort(tval.begin(), tval.end());
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2;
    POINT cursorPos;
    cursorPos = {xc - 200, yc + 300};
    //polygon vertices
    coord vertex[MAX] = {{xc - 200, yc - 100}, {xc + 300, yc - 30}, {xc + 50, yc}, {xc + 200, yc + 150}, {xc, yc + 20}, {xc + 10, yc + 200}};
    //1st point of line
    coord p1 = {xc + 400, yc - 200};
    int page = 0;

    while(!kbhit()){
        settextstyle(10, HORIZ_DIR, 1);     setcolor(YELLOW);
        outtextxy(xc - 200, yc - 350, "Hold the Left-Shift key and Hover the Cursor!!");

        //update the P2 coordinate only if Shift key is pressed
        if(GetKeyState(VK_SHIFT) & 0x800)
            GetCursorPos(&cursorPos);
        coord p2 = {cursorPos.x, cursorPos.y};

        //for storing the t parameters
        vector<float> t;
        //n  is the total no. of sides/vertices of the polygon
        int n = 6;
        cyrusBeck(vertex, n, p1, p2, t);

//        cout << "T-values : ";
//        for (auto i = t.begin(); i != t.end(); ++i)
//            cout << *i << " ";

        setcolor(RED);
        //Drawing the edges of polygon
        for (int i = 0; i < n; ++i)
            line(vertex[i].x, vertex[i].y, vertex[(i+1)%n].x, vertex[(i+1)%n].y);

        setcolor(BLUE);
        line(p1.x, p1.y, p2.x, p2.y);

        setcolor(LIGHTGREEN);
        //drawing the clipped line (i.e over-drawing)
        for (auto i = t.begin(); i != t.end(); ++i){
            coord pt1, pt2;
            pt1.x = p1.x + (p2.x - p1.x) * (*i);
            pt1.y = p1.y + (p2.y - p1.y) * (*i);
            ++i;
            pt2.x = p1.x + (p2.x - p1.x) * (*i);
            pt2.y = p1.y + (p2.y - p1.y) * (*i);
            line(pt1.x, pt1.y, pt2.x, pt2.y);
        }
        t.clear();

        setactivepage(page);    setvisualpage(1 - page);
        cleardevice();  page = 1 - page;
    }

    getch();
    return 0;
}
