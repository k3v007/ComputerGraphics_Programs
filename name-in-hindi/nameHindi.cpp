#include <bits/stdc++.h>
#include <graphics.h>
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)

using namespace std;

int main()
{
    initwindow(1200, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2;

    //it defines the no. of curves to be used in curve matrix
    int crv = 11;

    //each curve matrix is written as:
    //a group of P1, P2, P3, P4 (bezier curve) points as column and each column as [x y z 1]
    //so first column is [P1.x, P1.y, P1.z, 1]
    int curve[4][4*crv] = {     {-200,-200,-200,-200,   -100,-200,-200,-100,  -200,-280,-210,-110,  -100,-100,-100,-100,   0,-100,-100,0,   0,-50,-150,-80,  0,0,0,0,        100,0,0,100,    100,100,100,100,  100,200,200,120,  -240,-240,200,200},
                                {70,70,-70,-70,         5,150,-150,-5,        70,150,150,70,         70,70,-70,-70,        5,150,-150,-5,  70,150,140,120,   70,70,-70,-70,  5,150,-150,-5,  70,70,-70,-70,     5,140,-100,-30,   70,70,70,70},
                                {0,0,0,0,               0,0,0,0,              0,0,0,0,               0,0,0,0,              0,0,0,0,        0,0,0,0,          0,0,0,0,        0,0,0,0,        0,0,0,0,           0,0,0,0,          0,0,0,0},
                                {1,1,1,1,               1,1,1,1,              1,1,1,1,               1,1,1,1,              1,1,1,1,        1,1,1,1,          1,1,1,1,        1,1,1,1,        1,1,1,1,           1,1,1,1,          1,1,1,1}  };

   //circle drawn using 2 curves
    int page = 0;
    for (int ang = 0; !kbhit(); ++ang) {
        //rotation matrix about x-axis
        float rotx[4][4] = {    {1, 0, 0, 0},
                                {0, COS(ang), -SIN(ang), 0},
                                {0, SIN(ang), COS(ang), 0},
                                {0, 0, 0, 1}    };

        //rotation matrix about y-axis
        float roty[4][4] = {    {COS(ang), 0, SIN(ang), 0},
                                {0, 1, 0, 0},
                                {-SIN(ang), 0, COS(ang), 0},
                                {0, 0, 0, 1}    };

        //rotation matrix about z-axis
        float rotz[4][4] = {    {COS(ang), -SIN(ang), 0, 0},
                                {SIN(ang), COS(ang), 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}    };

        //using the x-rotation matrix and implementing it
        float pts[4][4*crv];
        //multiplying the rotation matrix with the curve points
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += rotx[i][k] * curve[k][j];
                }
                pts[i][j] = sum;
            }
        }

        //drawing the bezier curve using the binomial formula
        for (int col = 0; col < 4 * crv; col +=4) {
            //we increment col by 4 because we have 4 columns group as a 1 bezier curve control points
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * pts[0][col] + 3 * pow(1-t, 2) * t * pts[0][col+1] + 3 * (1-t) * t * t * pts[0][col+2] + pow(t, 3) * pts[0][col+3];
                y = pow(1-t, 3) * pts[1][col] + 3 * pow(1-t, 2) * t * pts[1][col+1] + 3 * (1-t) * t * t * pts[1][col+2] + pow(t, 3) * pts[1][col+3];
                putpixel(xc + x, yc - y, LIGHTRED);
            }
        }

        delay(5);          setvisualpage(1 - page),    setactivepage(page);
        page = 1 - page;    cleardevice();
    }

    getch();
    return 0;
}
