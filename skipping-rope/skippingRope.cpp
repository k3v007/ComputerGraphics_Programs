//for hiding the rope behind the person during skipping, z-coordinate of the rope has been compared
//and point is checked whether it lies inside a given figure or not
#include <bits/stdc++.h>
#include <graphics.h>
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
#define MAX         10

using namespace std;

//x and y coordinate
typedef struct{
    int x;
    int y;
}coord;

//using checkInside function for clipping purpose
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

bool insideCircle(int x, int y, int xc, int yc, int r)
{
    //inside test of circle is checked using the circle equation
    //f(x,y) = (x-h)^2 + (y-k)^2 - r^2 = 0
    long long sum = 0;
    sum = pow((x-xc), 2) + pow((y-yc), 2) - pow(r, 2);
    if (sum < 0)
        return true;    //point lies inside the circle
    else
        return false;   //point lies outside the circle
}

int main()
{
    initwindow(1200, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0, ang = 0;
    int YC = yc;    //used in hand movement

    //we require only one curve for drawing the skipping rope (use of bezier curve)
    //second curve is used for thickening the curve
    //each curve is stored as 4 control points P1, P2, P3, P4 column wise, and each column as [x y z 1]
    int crv = 2;
    int rope[4][4*crv] = {  {-75,-75,75,75,         -74,-74,74,74},
                            {-10,248,248,-10,       -9,247,247,-9},
                            {0,0,0,0,               0,0,0,0},
                            {1,1,1,1,               1,1,1,1}  };

    //yinc is used for person jumping
    int yinc = 1, last = 0;
    float k = 0;
    for (int ang = 0; !kbhit(); ang+=3) {
        last = yc;
        //setting condition for going up or down
        if(yc > YC + 30) {
            yinc *= -1;
        }
        if (yc < YC - 30) {
            yinc *= -1;
        }
        yc += yinc;

        //k is used for the hand movement relative to the body
        if (yc > last){
            k += 0.3;
        }
        else{
            k -= 0.3;
        }

        //Drawing person
        setcolor(LIGHTGRAY);
        line(xc - 25, yc + 50, xc + 25, yc + 50);       line(xc - 25, yc + 49, xc + 25, yc + 49);       line(xc - 25, yc + 48, xc + 25, yc + 48);       //used for main body
        line(xc - 25, yc + 50, xc - 25, yc - 50);       line(xc - 24, yc + 50, xc - 24, yc - 50);       line(xc - 23, yc + 50, xc - 23, yc - 50);       //~
        line(xc + 25, yc + 50, xc + 25, yc - 50);       line(xc + 24, yc + 50, xc + 24, yc - 50);       line(xc + 23, yc + 50, xc + 23, yc - 50);       //~
        line(xc - 28, yc - 60, xc + 28, yc - 60);       line(xc - 28, yc - 59, xc + 28, yc - 59);       line(xc - 28, yc - 58, xc + 28, yc - 58);       //~
        line(xc - 45, yc - 20, xc - 28, yc - 60);       line(xc - 44, yc - 19, xc - 27, yc - 59);       line(xc - 43, yc - 19, xc - 27, yc - 58);       //left arm
        line(xc + 45, yc - 20, xc + 28, yc - 60);       line(xc + 44, yc - 19, xc + 27, yc - 59);       line(xc + 43, yc - 19, xc + 27, yc - 58);       //right arm

        line(xc - 75, yc + k - 10, xc - 45, yc - 20);   line(xc - 74, yc + k - 9,  xc - 44, yc - 19);   line(xc - 73, yc + k - 8,  xc - 43, yc - 18);   //left hand
        line(xc + 75, yc + k - 10, xc + 45, yc - 20);   line(xc + 74, yc + k - 9,  xc + 44, yc - 19);   line(xc + 73, yc + k - 8,  xc + 43, yc - 18);   //right hand

        line(xc, yc - 60, xc, yc - 70);                 line(xc - 1, yc - 60,  xc - 1,  yc - 70);       line(xc + 1,  yc - 60, xc + 1,  yc - 70);       //neck
        circle(xc - 7 , yc - 95, 5);                    circle(xc + 7 , yc - 95, 5);                    line(xc - 5, yc - 83, xc + 5, yc - 83);         //eyes and mouth
        circle(xc, yc - 90, 20);                        circle(xc, yc - 90, 21);                        circle(xc, yc - 90, 19);                        //head
        line(xc - 15, yc + 50,  xc - 15, yc + 100);     line(xc - 16, yc + 50, xc - 16, yc + 100);      line(xc - 14, yc + 50, xc - 14, yc + 100);      //left leg
        line(xc + 15, yc + 50,  xc + 15, yc + 100);     line(xc + 16, yc + 50, xc + 16, yc + 100);      line(xc + 14, yc + 50, xc + 14, yc + 100);      //right leg
        line(xc - 15, yc + 100, xc - 10, yc + 100);     line(xc - 15, yc + 99, xc - 11, yc + 99);       line(xc - 15, yc + 98, xc - 10, yc + 99);       //left foot
        line(xc + 15, yc + 100, xc + 10, yc + 100);     line(xc + 15, yc + 99, xc + 11, yc + 99);       line(xc + 15, yc + 98, xc + 10, yc + 99);       //right foot

        setcolor(LIGHTRED);
        line(0, YC + 136, getmaxx(), YC + 136);         line(0, YC + 135, getmaxx(), YC + 135);         line(0, YC + 134, getmaxx(), YC + 134);         //ground line

        //rotation matrix about x-axis
        float rotx[4][4] = {    {1,  0,         0,          0},
                                {0,  COS(ang),  -SIN(ang),  0},
                                {0,  SIN(ang),  COS(ang),   0},
                                {0,  0,         0,          1}    };

        //multiplying the curve points with the rotation matrix
        float pts[4][4*crv];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += rotx[i][k] * rope[k][j];
                }
                pts[i][j] = sum;
            }
        }

        //defining the clipping window, using it for hiding the rope
        coord rect[4] = {{xc - 25, yc + 50}, {xc - 25, yc - 60}, {xc + 25, yc - 60}, {xc + 25, yc + 50}};

        //plotting using Bezier method
        for (int col = 0; col < 4 * crv; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * pts[0][col] + 3 * pow(1-t, 2) * t * pts[0][col+1] + 3 * (1-t) * t * t * pts[0][col+2] + pow(t, 3) * pts[0][col+3];
                y = pow(1-t, 3) * pts[1][col] + 3 * pow(1-t, 2) * t * pts[1][col+1] + 3 * (1-t) * t * t * pts[1][col+2] + pow(t, 3) * pts[1][col+3];

                //we check the z value of the skipping rope
                //if z<=0, then we draw the rope over the body
                //if z>0, then point should not lie inside rectangle or circle(head) and it should not be drawn on white pixels(i.e the edges used for drawing person)
                if ((pts[2][col] <= 0) or (!checkInside(rect, 4, xc + x, yc + k - y) and !insideCircle(xc + x, yc + k - y, xc, yc - 90, 20) and getpixel(xc + x, yc + k - y) == BLACK))
                    putpixel(xc + x, yc + k - y, LIGHTGREEN);

            }
        }

        delay(10);          setvisualpage(1 - page);    setactivepage(page);
        page = 1 - page;    cleardevice();
    }

    getch();
    return 0;
}
