//Displays current time of your system using Hindi nos. from 0 - 10
//Time is in 24-hours format
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         20
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
#define deg(a)      ((float)a * 180) / PI

using namespace std;

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
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;
    time_t now;
    struct tm *now_tm;
    int hr, minutes, seconds;

    int pixcolor = LIGHTGREEN;

    //these are the displacement of each digit of hour, minute or second from center of the screen
    int hr1disp = -310, hr2disp = -210, min1disp = -57, min2disp = 57, sec1disp = 210, sec2disp = 310;
    int hr1, hr2, min1, min2, sec1, sec2;

    while(!kbhit()){
        now = time(NULL);
        now_tm = localtime(&now);
        hr = now_tm -> tm_hour;     minutes = now_tm -> tm_min;     seconds = now_tm -> tm_sec;

        hr2 = hr % 10;              hr /= 10;           hr1 = hr % 10;              //stores the digits of hour
        min2 = minutes % 10;        minutes /= 10;      min1 = minutes % 10;        //stores the digits of minute
        sec2 = seconds % 10;        seconds /= 10;      sec1 = seconds % 10;        //stores the digits of second


        setcolor(LIGHTBLUE);
        setlinestyle(DASHED_LINE, 0xFFFF, 1);       rectangle(xc - 390, yc - 110, xc + 390 , yc + 110);
        setlinestyle(SOLID_LINE, 0xFFFF, 5);        rectangle(xc - 400, yc - 120, xc + 400 , yc + 120);

        //drawing the separating dots
        setlinestyle(SOLID_LINE, 0xFFFF, 0);       setcolor(YELLOW);         setfillstyle(SOLID_FILL, YELLOW);
        circle(xc - 130, yc - 20, 10);     circle(xc - 130, yc + 20, 10);    floodfill(xc - 130, yc - 20, YELLOW);    floodfill(xc - 130, yc + 20, YELLOW);
        circle(xc + 130, yc - 20, 10);     circle(xc + 130, yc + 20, 10);    floodfill(xc + 130, yc - 20, YELLOW);    floodfill(xc + 130, yc + 20, YELLOW);

        //displaying the 1st digit of the hour
        switch(hr1){
            case 0  :   drawHindi0(xc + hr1disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + hr1disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + hr1disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + hr1disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + hr1disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + hr1disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + hr1disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + hr1disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + hr1disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + hr1disp, yc, pixcolor);  break;
        }

        //displaying the 2nd digit of the hour
        switch(hr2){
            case 0  :   drawHindi0(xc + hr2disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + hr2disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + hr2disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + hr2disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + hr2disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + hr2disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + hr2disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + hr2disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + hr2disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + hr2disp, yc, pixcolor);  break;
        }

        //displaying the 1st digit of the minute
        switch(min1){
            case 0  :   drawHindi0(xc + min1disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + min1disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + min1disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + min1disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + min1disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + min1disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + min1disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + min1disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + min1disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + min1disp, yc, pixcolor);  break;
        }

        //displaying the 2nd digit of the minute
        switch(min2){
            case 0  :   drawHindi0(xc + min2disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + min2disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + min2disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + min2disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + min2disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + min2disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + min2disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + min2disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + min2disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + min2disp, yc, pixcolor);  break;
        }

        //displaying the 1st digit of the second
        switch(sec1){
            case 0  :   drawHindi0(xc + sec1disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + sec1disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + sec1disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + sec1disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + sec1disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + sec1disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + sec1disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + sec1disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + sec1disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + sec1disp, yc, pixcolor);  break;
        }

        //displaying the 2nd digit of the second
        switch(sec2){
            case 0  :   drawHindi0(xc + sec2disp, yc, pixcolor);  break;
            case 1  :   drawHindi1(xc + sec2disp, yc, pixcolor);  break;
            case 2  :   drawHindi2(xc + sec2disp, yc, pixcolor);  break;
            case 3  :   drawHindi3(xc + sec2disp, yc, pixcolor);  break;
            case 4  :   drawHindi4(xc + sec2disp, yc, pixcolor);  break;
            case 5  :   drawHindi5(xc + sec2disp, yc, pixcolor);  break;
            case 6  :   drawHindi6(xc + sec2disp, yc, pixcolor);  break;
            case 7  :   drawHindi7(xc + sec2disp, yc, pixcolor);  break;
            case 8  :   drawHindi8(xc + sec2disp, yc, pixcolor);  break;
            case 9  :   drawHindi9(xc + sec2disp, yc, pixcolor);  break;
        }

        delay(50);
        setactivepage(page);    setvisualpage(1 - page);    1 - page;
        cleardevice();
    }

    getch();
    return 0;
}
