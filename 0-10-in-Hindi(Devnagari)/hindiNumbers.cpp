//Numbers from 0 - 10 in Devnagari
//Drawn using Bezier curves
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         20
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
#define deg(a)      ((float)a * 180) / PI

using namespace std;

//for thickness of the curves
const int thick = 5;


//Bezier curve is stored in the form of matrix each containing 4 rows and a set of controlling points P1, P2, P3, and P4 for each curve as columns
//each controlling point is stored as [x y z 1] column wise, so that matrix calculation can be carried out for 2D or 3D transformation

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//0
void drawHindi0(int xc, int yc, int pixcolor){
    const int crv0 = 2;
    int hindi0[4][4*crv0] = {   {0,40,40,0,         0,-40,-40,0},
                                {30,30,-30,-30,     30,30,-30,-30},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv0; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi0[0][col] + 3 * pow(1-t, 2) * t * hindi0[0][col+1] + 3 * (1-t) * t * t * hindi0[0][col+2] + pow(t, 3) * hindi0[0][col+3];
                y = pow(1-t, 3) * hindi0[1][col] + 3 * pow(1-t, 2) * t * hindi0[1][col+1] + 3 * (1-t) * t * t * hindi0[1][col+2] + pow(t, 3) * hindi0[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//1
void drawHindi1(int xc, int yc, int pixcolor){
    const int crv1 = 2;
    int hindi1[4][4*crv1] = {   {-5,-90,80,0,      0,-60,50,0},
                                {25,70,100,20,      20,-25,-40,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

    //for drawing 1
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv1; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi1[0][col] + 3 * pow(1-t, 2) * t * hindi1[0][col+1] + 3 * (1-t) * t * t * hindi1[0][col+2] + pow(t, 3) * hindi1[0][col+3];
                y = pow(1-t, 3) * hindi1[1][col] + 3 * pow(1-t, 2) * t * hindi1[1][col+1] + 3 * (1-t) * t * t * hindi1[1][col+2] + pow(t, 3) * hindi1[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//2
void drawHindi2(int xc, int yc, int pixcolor){
    const int crv2 = 2;
    int hindi2[4][4*crv2] = {   {-40,60,60,-30,     -30,-60,10,30},
                                {55,110,-60,-20,    -20,20,-10,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

    //for drawing 2
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv2; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi2[0][col] + 3 * pow(1-t, 2) * t * hindi2[0][col+1] + 3 * (1-t) * t * t * hindi2[0][col+2] + pow(t, 3) * hindi2[0][col+3];
                y = pow(1-t, 3) * hindi2[1][col] + 3 * pow(1-t, 2) * t * hindi2[1][col+1] + 3 * (1-t) * t * t * hindi2[1][col+2] + pow(t, 3) * hindi2[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//3
void drawHindi3(int xc, int yc, int pixcolor){
    const int crv3 = 3;
    int hindi3[4][4*crv3] = {   {-25,55,55,-5,      -5,55,50,-30,        -30,-40,0,10},
                                {60,100,-10,5,      5,10,-90,-50,       -50,-20,-40,-80},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

    //for drawing 3
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv3; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi3[0][col] + 3 * pow(1-t, 2) * t * hindi3[0][col+1] + 3 * (1-t) * t * t * hindi3[0][col+2] + pow(t, 3) * hindi3[0][col+3];
                y = pow(1-t, 3) * hindi3[1][col] + 3 * pow(1-t, 2) * t * hindi3[1][col+1] + 3 * (1-t) * t * t * hindi3[1][col+2] + pow(t, 3) * hindi3[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//4
void drawHindi4(int xc, int yc, int pixcolor){
    const int crv4 = 4;
    int hindi4[4][4*crv4] = {   {0,40,40,40,        0,-40,-40,-40,      0,-30,-30,0,        0,30,30,0},
                                {-5,35,45,70,       -5,35,45,70,        -5,-35,-65,-70,     -5,-35,-65,-70},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1,            1,1,1,1}        };

    //for drawing 4
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv4; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi4[0][col] + 3 * pow(1-t, 2) * t * hindi4[0][col+1] + 3 * (1-t) * t * t * hindi4[0][col+2] + pow(t, 3) * hindi4[0][col+3];
                y = pow(1-t, 3) * hindi4[1][col] + 3 * pow(1-t, 2) * t * hindi4[1][col+1] + 3 * (1-t) * t * t * hindi4[1][col+2] + pow(t, 3) * hindi4[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//5
void drawHindi5(int xc, int yc, int pixcolor){
    const int crv5 = 3;
    int hindi5[4][4*crv5] = {   {-40,-50,40,30,     30,30,40,-20,       -20,-30,-10,50},
                                {70,-30,-20,70,     70,70,-100,-50,     -50,-40,-30,-70},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

    //for drawing 5
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv5; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi5[0][col] + 3 * pow(1-t, 2) * t * hindi5[0][col+1] + 3 * (1-t) * t * t * hindi5[0][col+2] + pow(t, 3) * hindi5[0][col+3];
                y = pow(1-t, 3) * hindi5[1][col] + 3 * pow(1-t, 2) * t * hindi5[1][col+1] + 3 * (1-t) * t * t * hindi5[1][col+2] + pow(t, 3) * hindi5[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//6
void drawHindi6(int xc, int yc, int pixcolor){
    const int crv6 = 3;
    int hindi6[4][4*crv6] = {   {20,-60,-60,0,      0,-60,-55,30,       30,50,-10,40},
                                {60,100,-10,5,      5,10,-90,-50,       -50,-10,-30,-80},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

    //for drawing 6
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv6; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi6[0][col] + 3 * pow(1-t, 2) * t * hindi6[0][col+1] + 3 * (1-t) * t * t * hindi6[0][col+2] + pow(t, 3) * hindi6[0][col+3];
                y = pow(1-t, 3) * hindi6[1][col] + 3 * pow(1-t, 2) * t * hindi6[1][col+1] + 3 * (1-t) * t * t * hindi6[1][col+2] + pow(t, 3) * hindi6[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//7
void drawHindi7(int xc, int yc, int pixcolor){
    const int crv7 = 2;
    int hindi7[4][4*crv7] = {   {-30,-80,80,40,     40,0,0,45},
                                {70,-100,-110,35,    35,90,-20,20},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

    //for drawing 7
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv7; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi7[0][col] + 3 * pow(1-t, 2) * t * hindi7[0][col+1] + 3 * (1-t) * t * t * hindi7[0][col+2] + pow(t, 3) * hindi7[0][col+3];
                y = pow(1-t, 3) * hindi7[1][col] + 3 * pow(1-t, 2) * t * hindi7[1][col+1] + 3 * (1-t) * t * t * hindi7[1][col+2] + pow(t, 3) * hindi7[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//8
void drawHindi8(int xc, int yc, int pixcolor){
    const int crv8 = 1;
    int hindi8[4][4*crv8] = {   {10,-70,-10,40},
                                {70,-50,-90,-30},
                                {0,0,0,0},
                                {1,1,1,1}       };

    //for drawing 8
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv8; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi8[0][col] + 3 * pow(1-t, 2) * t * hindi8[0][col+1] + 3 * (1-t) * t * t * hindi8[0][col+2] + pow(t, 3) * hindi8[0][col+3];
                y = pow(1-t, 3) * hindi8[1][col] + 3 * pow(1-t, 2) * t * hindi8[1][col+1] + 3 * (1-t) * t * t * hindi8[1][col+2] + pow(t, 3) * hindi8[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


//9
void drawHindi9(int xc, int yc, int pixcolor){
    const int crv9 = 2;
    int hindi9[4][4*crv9] = {   {5,100,-120,0,      0,60,50,20},
                                {15,90,90,10,       10,-35,-40,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

    //for drawing 9
    for (int disp = 0; disp < thick; ++disp){
        for (int col = 0; col < 4 * crv9; col +=4) {
            for (float t = 0; t <= 1; t += 0.001) {
                float x, y;
                x = pow(1-t, 3) * hindi9[0][col] + 3 * pow(1-t, 2) * t * hindi9[0][col+1] + 3 * (1-t) * t * t * hindi9[0][col+2] + pow(t, 3) * hindi9[0][col+3];
                y = pow(1-t, 3) * hindi9[1][col] + 3 * pow(1-t, 2) * t * hindi9[1][col+1] + 3 * (1-t) * t * t * hindi9[1][col+2] + pow(t, 3) * hindi9[1][col+3];
                putpixel(xc + disp + x, yc - y, pixcolor);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2;

    int pixcolor = YELLOW;

    //Drawing all the Devnagari numbers from 0 - 10
    drawHindi0(xc - 500, yc - 200, pixcolor);
    drawHindi1(xc - 250, yc - 200, pixcolor);
    drawHindi2(xc, yc - 200, pixcolor);
    drawHindi3(xc + 250, yc - 200, pixcolor);
    drawHindi4(xc + 500, yc - 200, pixcolor);

    drawHindi5(xc - 500, yc + 200, pixcolor);
    drawHindi6(xc - 250, yc + 200, pixcolor);
    drawHindi7(xc, yc + 200, pixcolor);
    drawHindi8(xc + 250, yc + 200, pixcolor);
    drawHindi9(xc + 500, yc + 200, pixcolor);

    getch();
    return 0;
}
