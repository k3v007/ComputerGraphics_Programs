//Given in external practical
//was asked to display current time as MM : SS where MM is minutes and SS is second, and they should be in Hindi numbers
//many redundant codes are used for printing the curve as we have if else conditions (will update the short code later)
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         20
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
#define deg(a)      ((float)a * 180) / PI

using namespace std;


int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;
    time_t now;
    struct tm *now_tm;
    int minutes, seconds;

    //Numbers in Hindi
    //0
    const int crv0 = 2;
    int hindi0[4][4*crv0] = {   {0,40,40,0,         0,-40,-40,0},
                                {30,30,-30,-30,     30,30,-30,-30},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };
//--------------------------------------------------------------------------------------------------------------
    //1
    const int crv1 = 2;
    int hindi1[4][4*crv1] = {   {-5,-50,40,-30,     -30,0,0,30},
                                {20,70,100,-20,     -20,-70,-70,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //2
    const int crv2 = 2;
    int hindi2[4][4*crv2] = {   {-30,60,60,-30,     -30,-50,-40,30},
                                {70,120,-70,-30,    -30,10,10,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //3
    const int crv3 = 3;
    int hindi3[4][4*crv3] = {   {-30,50,50,-30,     -30,50,50,-30,      -30,-40,40,40},
                                {70,70,10,10,       10,10,-60,-40,      -40,0,-70,-70},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //4
    const int crv4 = 7;
    int hindi4[4][4*crv4] = {   {0,40,40,40,        0,-40,-40,-40,      0,-30,-30,0,        0,30,30,0},
                                {-5,35,45,70,       -5,35,45,70,        -5,-35,-65,-70,     -5,-35,-65,-70},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1,            1,1,1,1}        };

//--------------------------------------------------------------------------------------------------------------

    //5
    const int crv5 = 2;
    int hindi5[4][4*crv5] = {   {-40,-50,50,40,     40,10,80,-30},
                                {70,-20,-20,70,     70,30,-100,-70},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //6
    const int crv6 = 3;
    int hindi6[4][4*crv6] = {   {30,-50,-50,30,     30,-50,-50,30,      30,40,-40,-40},
                                {70,70,10,10,       10,10,-60,-40,      -40,0,-70,-70},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //7
    const int crv7 = 2;
    int hindi7[4][4*crv7] = {   {-40,-60,60,40,     40,0,0,40},
                                {70,-100,-100,65,   65,80,20,40},
                                {0,0,0,0,           0,0,0,0},
                                {1,1,1,1,           1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //8
    const int crv8 = 1;
    int hindi8[4][4*crv8] = {   {10,-60,-10,40},
                                {60,-50,-90,-30},
                                {0,0,0,0},
                                {1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------

    //9
    const int crv9 = 3;
    int hindi9[4][4*crv9] = {   {30,-50,-50,30,     30,-50,-50,30,      -30,-30,30,30},
                                {70,70,30,10,       10,-10,-70,-70,     10,10,10,10},
                                {0,0,0,0,           0,0,0,0,            0,0,0,0},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1}       };

//--------------------------------------------------------------------------------------------------------------


    int pixcolor = LIGHTRED;

    int min1disp = -175, min2disp = -80, sec1disp = 80, sec2disp = 175;     //these are the displacement of each digit of minute or second from center of the screen

    while(!kbhit()){
        now = time(NULL);
        now_tm = localtime(&now);
        minutes = now_tm->tm_min;
        seconds = now_tm->tm_sec;
        int min1 = 0, min2, sec1, sec2;

        min2 = minutes % 10;        //stores the second digit of minute
        minutes /= 10;
        min1 = minutes % 10;        //stores the first digit of minute
        sec2 = seconds % 10;        //stores the second digit of second
        seconds /= 10;
        sec1 = seconds % 10;        //stores the first digit of second


        setcolor(pixcolor);
        circle(xc, yc - 20, 10);
        circle(xc, yc + 20, 10);


        //displaying the 1st digit of the minute
        if(min1 == 0){
            //for drawing 1
            for (int col = 0; col < 4 * crv0; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi0[0][col] + 3 * pow(1-t, 2) * t * hindi0[0][col+1] + 3 * (1-t) * t * t * hindi0[0][col+2] + pow(t, 3) * hindi0[0][col+3];
                    y = pow(1-t, 3) * hindi0[1][col] + 3 * pow(1-t, 2) * t * hindi0[1][col+1] + 3 * (1-t) * t * t * hindi0[1][col+2] + pow(t, 3) * hindi0[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 1){
            //for drawing 2
            for (int col = 0; col < 4 * crv1; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi1[0][col] + 3 * pow(1-t, 2) * t * hindi1[0][col+1] + 3 * (1-t) * t * t * hindi1[0][col+2] + pow(t, 3) * hindi1[0][col+3];
                    y = pow(1-t, 3) * hindi1[1][col] + 3 * pow(1-t, 2) * t * hindi1[1][col+1] + 3 * (1-t) * t * t * hindi1[1][col+2] + pow(t, 3) * hindi1[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 2){
            //for drawing 2
            for (int col = 0; col < 4 * crv2; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi2[0][col] + 3 * pow(1-t, 2) * t * hindi2[0][col+1] + 3 * (1-t) * t * t * hindi2[0][col+2] + pow(t, 3) * hindi2[0][col+3];
                    y = pow(1-t, 3) * hindi2[1][col] + 3 * pow(1-t, 2) * t * hindi2[1][col+1] + 3 * (1-t) * t * t * hindi2[1][col+2] + pow(t, 3) * hindi2[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 3){
            //for drawing 3
            for (int col = 0; col < 4 * crv3; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi3[0][col] + 3 * pow(1-t, 2) * t * hindi3[0][col+1] + 3 * (1-t) * t * t * hindi3[0][col+2] + pow(t, 3) * hindi3[0][col+3];
                    y = pow(1-t, 3) * hindi3[1][col] + 3 * pow(1-t, 2) * t * hindi3[1][col+1] + 3 * (1-t) * t * t * hindi3[1][col+2] + pow(t, 3) * hindi3[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 4){
            //for drawing 4
            for (int col = 0; col < 4 * crv4; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi4[0][col] + 3 * pow(1-t, 2) * t * hindi4[0][col+1] + 3 * (1-t) * t * t * hindi4[0][col+2] + pow(t, 3) * hindi4[0][col+3];
                    y = pow(1-t, 3) * hindi4[1][col] + 3 * pow(1-t, 2) * t * hindi4[1][col+1] + 3 * (1-t) * t * t * hindi4[1][col+2] + pow(t, 3) * hindi4[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 5){
            //for drawing 5
            for (int col = 0; col < 4 * crv5; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi5[0][col] + 3 * pow(1-t, 2) * t * hindi5[0][col+1] + 3 * (1-t) * t * t * hindi5[0][col+2] + pow(t, 3) * hindi5[0][col+3];
                    y = pow(1-t, 3) * hindi5[1][col] + 3 * pow(1-t, 2) * t * hindi5[1][col+1] + 3 * (1-t) * t * t * hindi5[1][col+2] + pow(t, 3) * hindi5[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 6){
            //for drawing 6
            for (int col = 0; col < 4 * crv6; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi6[0][col] + 3 * pow(1-t, 2) * t * hindi6[0][col+1] + 3 * (1-t) * t * t * hindi6[0][col+2] + pow(t, 3) * hindi6[0][col+3];
                    y = pow(1-t, 3) * hindi6[1][col] + 3 * pow(1-t, 2) * t * hindi6[1][col+1] + 3 * (1-t) * t * t * hindi6[1][col+2] + pow(t, 3) * hindi6[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 7){
            //for drawing 7
            for (int col = 0; col < 4 * crv7; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi7[0][col] + 3 * pow(1-t, 2) * t * hindi7[0][col+1] + 3 * (1-t) * t * t * hindi7[0][col+2] + pow(t, 3) * hindi7[0][col+3];
                    y = pow(1-t, 3) * hindi7[1][col] + 3 * pow(1-t, 2) * t * hindi7[1][col+1] + 3 * (1-t) * t * t * hindi7[1][col+2] + pow(t, 3) * hindi7[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 8){
            //for drawing 8
            for (int col = 0; col < 4 * crv8; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi8[0][col] + 3 * pow(1-t, 2) * t * hindi8[0][col+1] + 3 * (1-t) * t * t * hindi8[0][col+2] + pow(t, 3) * hindi8[0][col+3];
                    y = pow(1-t, 3) * hindi8[1][col] + 3 * pow(1-t, 2) * t * hindi8[1][col+1] + 3 * (1-t) * t * t * hindi8[1][col+2] + pow(t, 3) * hindi8[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min1 == 9){
            //for drawing 9
            for (int col = 0; col < 4 * crv9; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi9[0][col] + 3 * pow(1-t, 2) * t * hindi9[0][col+1] + 3 * (1-t) * t * t * hindi9[0][col+2] + pow(t, 3) * hindi9[0][col+3];
                    y = pow(1-t, 3) * hindi9[1][col] + 3 * pow(1-t, 2) * t * hindi9[1][col+1] + 3 * (1-t) * t * t * hindi9[1][col+2] + pow(t, 3) * hindi9[1][col+3];
                    putpixel(xc + min1disp + x, yc - y, pixcolor);
                }
            }
        }




        //displaying the 2nd digit of the minute
        if(min2 == 0){
            //for drawing 1
            for (int col = 0; col < 4 * crv0; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi0[0][col] + 3 * pow(1-t, 2) * t * hindi0[0][col+1] + 3 * (1-t) * t * t * hindi0[0][col+2] + pow(t, 3) * hindi0[0][col+3];
                    y = pow(1-t, 3) * hindi0[1][col] + 3 * pow(1-t, 2) * t * hindi0[1][col+1] + 3 * (1-t) * t * t * hindi0[1][col+2] + pow(t, 3) * hindi0[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 1){
            //for drawing 2
            for (int col = 0; col < 4 * crv1; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi1[0][col] + 3 * pow(1-t, 2) * t * hindi1[0][col+1] + 3 * (1-t) * t * t * hindi1[0][col+2] + pow(t, 3) * hindi1[0][col+3];
                    y = pow(1-t, 3) * hindi1[1][col] + 3 * pow(1-t, 2) * t * hindi1[1][col+1] + 3 * (1-t) * t * t * hindi1[1][col+2] + pow(t, 3) * hindi1[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 2){
            //for drawing 2
            for (int col = 0; col < 4 * crv2; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi2[0][col] + 3 * pow(1-t, 2) * t * hindi2[0][col+1] + 3 * (1-t) * t * t * hindi2[0][col+2] + pow(t, 3) * hindi2[0][col+3];
                    y = pow(1-t, 3) * hindi2[1][col] + 3 * pow(1-t, 2) * t * hindi2[1][col+1] + 3 * (1-t) * t * t * hindi2[1][col+2] + pow(t, 3) * hindi2[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 3){
            //for drawing 3
            for (int col = 0; col < 4 * crv3; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi3[0][col] + 3 * pow(1-t, 2) * t * hindi3[0][col+1] + 3 * (1-t) * t * t * hindi3[0][col+2] + pow(t, 3) * hindi3[0][col+3];
                    y = pow(1-t, 3) * hindi3[1][col] + 3 * pow(1-t, 2) * t * hindi3[1][col+1] + 3 * (1-t) * t * t * hindi3[1][col+2] + pow(t, 3) * hindi3[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 4){
            //for drawing 4
            for (int col = 0; col < 4 * crv4; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi4[0][col] + 3 * pow(1-t, 2) * t * hindi4[0][col+1] + 3 * (1-t) * t * t * hindi4[0][col+2] + pow(t, 3) * hindi4[0][col+3];
                    y = pow(1-t, 3) * hindi4[1][col] + 3 * pow(1-t, 2) * t * hindi4[1][col+1] + 3 * (1-t) * t * t * hindi4[1][col+2] + pow(t, 3) * hindi4[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 5){
            //for drawing 5
            for (int col = 0; col < 4 * crv5; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi5[0][col] + 3 * pow(1-t, 2) * t * hindi5[0][col+1] + 3 * (1-t) * t * t * hindi5[0][col+2] + pow(t, 3) * hindi5[0][col+3];
                    y = pow(1-t, 3) * hindi5[1][col] + 3 * pow(1-t, 2) * t * hindi5[1][col+1] + 3 * (1-t) * t * t * hindi5[1][col+2] + pow(t, 3) * hindi5[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 6){
            //for drawing 6
            for (int col = 0; col < 4 * crv6; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi6[0][col] + 3 * pow(1-t, 2) * t * hindi6[0][col+1] + 3 * (1-t) * t * t * hindi6[0][col+2] + pow(t, 3) * hindi6[0][col+3];
                    y = pow(1-t, 3) * hindi6[1][col] + 3 * pow(1-t, 2) * t * hindi6[1][col+1] + 3 * (1-t) * t * t * hindi6[1][col+2] + pow(t, 3) * hindi6[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 7){
            //for drawing 7
            for (int col = 0; col < 4 * crv7; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi7[0][col] + 3 * pow(1-t, 2) * t * hindi7[0][col+1] + 3 * (1-t) * t * t * hindi7[0][col+2] + pow(t, 3) * hindi7[0][col+3];
                    y = pow(1-t, 3) * hindi7[1][col] + 3 * pow(1-t, 2) * t * hindi7[1][col+1] + 3 * (1-t) * t * t * hindi7[1][col+2] + pow(t, 3) * hindi7[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 8){
            //for drawing 8
            for (int col = 0; col < 4 * crv8; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi8[0][col] + 3 * pow(1-t, 2) * t * hindi8[0][col+1] + 3 * (1-t) * t * t * hindi8[0][col+2] + pow(t, 3) * hindi8[0][col+3];
                    y = pow(1-t, 3) * hindi8[1][col] + 3 * pow(1-t, 2) * t * hindi8[1][col+1] + 3 * (1-t) * t * t * hindi8[1][col+2] + pow(t, 3) * hindi8[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(min2 == 9){
            //for drawing 9
            for (int col = 0; col < 4 * crv9; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi9[0][col] + 3 * pow(1-t, 2) * t * hindi9[0][col+1] + 3 * (1-t) * t * t * hindi9[0][col+2] + pow(t, 3) * hindi9[0][col+3];
                    y = pow(1-t, 3) * hindi9[1][col] + 3 * pow(1-t, 2) * t * hindi9[1][col+1] + 3 * (1-t) * t * t * hindi9[1][col+2] + pow(t, 3) * hindi9[1][col+3];
                    putpixel(xc + min2disp + x, yc - y, pixcolor);
                }
            }
        }




        //Displaying 1st digit of second
        if(sec1 == 0){
            //for drawing 1
            for (int col = 0; col < 4 * crv0; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi0[0][col] + 3 * pow(1-t, 2) * t * hindi0[0][col+1] + 3 * (1-t) * t * t * hindi0[0][col+2] + pow(t, 3) * hindi0[0][col+3];
                    y = pow(1-t, 3) * hindi0[1][col] + 3 * pow(1-t, 2) * t * hindi0[1][col+1] + 3 * (1-t) * t * t * hindi0[1][col+2] + pow(t, 3) * hindi0[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 1){
            //for drawing 2
            for (int col = 0; col < 4 * crv1; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi1[0][col] + 3 * pow(1-t, 2) * t * hindi1[0][col+1] + 3 * (1-t) * t * t * hindi1[0][col+2] + pow(t, 3) * hindi1[0][col+3];
                    y = pow(1-t, 3) * hindi1[1][col] + 3 * pow(1-t, 2) * t * hindi1[1][col+1] + 3 * (1-t) * t * t * hindi1[1][col+2] + pow(t, 3) * hindi1[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 2){
            //for drawing 2
            for (int col = 0; col < 4 * crv2; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi2[0][col] + 3 * pow(1-t, 2) * t * hindi2[0][col+1] + 3 * (1-t) * t * t * hindi2[0][col+2] + pow(t, 3) * hindi2[0][col+3];
                    y = pow(1-t, 3) * hindi2[1][col] + 3 * pow(1-t, 2) * t * hindi2[1][col+1] + 3 * (1-t) * t * t * hindi2[1][col+2] + pow(t, 3) * hindi2[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 3){
            //for drawing 3
            for (int col = 0; col < 4 * crv3; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi3[0][col] + 3 * pow(1-t, 2) * t * hindi3[0][col+1] + 3 * (1-t) * t * t * hindi3[0][col+2] + pow(t, 3) * hindi3[0][col+3];
                    y = pow(1-t, 3) * hindi3[1][col] + 3 * pow(1-t, 2) * t * hindi3[1][col+1] + 3 * (1-t) * t * t * hindi3[1][col+2] + pow(t, 3) * hindi3[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 4){
            //for drawing 4
            for (int col = 0; col < 4 * crv4; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi4[0][col] + 3 * pow(1-t, 2) * t * hindi4[0][col+1] + 3 * (1-t) * t * t * hindi4[0][col+2] + pow(t, 3) * hindi4[0][col+3];
                    y = pow(1-t, 3) * hindi4[1][col] + 3 * pow(1-t, 2) * t * hindi4[1][col+1] + 3 * (1-t) * t * t * hindi4[1][col+2] + pow(t, 3) * hindi4[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 5){
            //for drawing 5
            for (int col = 0; col < 4 * crv5; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi5[0][col] + 3 * pow(1-t, 2) * t * hindi5[0][col+1] + 3 * (1-t) * t * t * hindi5[0][col+2] + pow(t, 3) * hindi5[0][col+3];
                    y = pow(1-t, 3) * hindi5[1][col] + 3 * pow(1-t, 2) * t * hindi5[1][col+1] + 3 * (1-t) * t * t * hindi5[1][col+2] + pow(t, 3) * hindi5[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 6){
            //for drawing 6
            for (int col = 0; col < 4 * crv6; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi6[0][col] + 3 * pow(1-t, 2) * t * hindi6[0][col+1] + 3 * (1-t) * t * t * hindi6[0][col+2] + pow(t, 3) * hindi6[0][col+3];
                    y = pow(1-t, 3) * hindi6[1][col] + 3 * pow(1-t, 2) * t * hindi6[1][col+1] + 3 * (1-t) * t * t * hindi6[1][col+2] + pow(t, 3) * hindi6[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 7){
            //for drawing 7
            for (int col = 0; col < 4 * crv7; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi7[0][col] + 3 * pow(1-t, 2) * t * hindi7[0][col+1] + 3 * (1-t) * t * t * hindi7[0][col+2] + pow(t, 3) * hindi7[0][col+3];
                    y = pow(1-t, 3) * hindi7[1][col] + 3 * pow(1-t, 2) * t * hindi7[1][col+1] + 3 * (1-t) * t * t * hindi7[1][col+2] + pow(t, 3) * hindi7[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 8){
            //for drawing 8
            for (int col = 0; col < 4 * crv8; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi8[0][col] + 3 * pow(1-t, 2) * t * hindi8[0][col+1] + 3 * (1-t) * t * t * hindi8[0][col+2] + pow(t, 3) * hindi8[0][col+3];
                    y = pow(1-t, 3) * hindi8[1][col] + 3 * pow(1-t, 2) * t * hindi8[1][col+1] + 3 * (1-t) * t * t * hindi8[1][col+2] + pow(t, 3) * hindi8[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }
        else if(sec1 == 9){
            //for drawing 9
            for (int col = 0; col < 4 * crv9; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi9[0][col] + 3 * pow(1-t, 2) * t * hindi9[0][col+1] + 3 * (1-t) * t * t * hindi9[0][col+2] + pow(t, 3) * hindi9[0][col+3];
                    y = pow(1-t, 3) * hindi9[1][col] + 3 * pow(1-t, 2) * t * hindi9[1][col+1] + 3 * (1-t) * t * t * hindi9[1][col+2] + pow(t, 3) * hindi9[1][col+3];
                    putpixel(xc + sec1disp +  x, yc - y, pixcolor);
                }
            }
        }




        //displaying the 2nd digit of the second
        if(sec2 == 0){
                    //for drawing 1
            for (int col = 0; col < 4 * crv0; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi0[0][col] + 3 * pow(1-t, 2) * t * hindi0[0][col+1] + 3 * (1-t) * t * t * hindi0[0][col+2] + pow(t, 3) * hindi0[0][col+3];
                    y = pow(1-t, 3) * hindi0[1][col] + 3 * pow(1-t, 2) * t * hindi0[1][col+1] + 3 * (1-t) * t * t * hindi0[1][col+2] + pow(t, 3) * hindi0[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 1){
            //for drawing 2
            for (int col = 0; col < 4 * crv1; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi1[0][col] + 3 * pow(1-t, 2) * t * hindi1[0][col+1] + 3 * (1-t) * t * t * hindi1[0][col+2] + pow(t, 3) * hindi1[0][col+3];
                    y = pow(1-t, 3) * hindi1[1][col] + 3 * pow(1-t, 2) * t * hindi1[1][col+1] + 3 * (1-t) * t * t * hindi1[1][col+2] + pow(t, 3) * hindi1[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 2){
            //for drawing 2
            for (int col = 0; col < 4 * crv2; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi2[0][col] + 3 * pow(1-t, 2) * t * hindi2[0][col+1] + 3 * (1-t) * t * t * hindi2[0][col+2] + pow(t, 3) * hindi2[0][col+3];
                    y = pow(1-t, 3) * hindi2[1][col] + 3 * pow(1-t, 2) * t * hindi2[1][col+1] + 3 * (1-t) * t * t * hindi2[1][col+2] + pow(t, 3) * hindi2[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 3){
            //for drawing 3
            for (int col = 0; col < 4 * crv3; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi3[0][col] + 3 * pow(1-t, 2) * t * hindi3[0][col+1] + 3 * (1-t) * t * t * hindi3[0][col+2] + pow(t, 3) * hindi3[0][col+3];
                    y = pow(1-t, 3) * hindi3[1][col] + 3 * pow(1-t, 2) * t * hindi3[1][col+1] + 3 * (1-t) * t * t * hindi3[1][col+2] + pow(t, 3) * hindi3[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 4){
            //for drawing 4
            for (int col = 0; col < 4 * crv4; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi4[0][col] + 3 * pow(1-t, 2) * t * hindi4[0][col+1] + 3 * (1-t) * t * t * hindi4[0][col+2] + pow(t, 3) * hindi4[0][col+3];
                    y = pow(1-t, 3) * hindi4[1][col] + 3 * pow(1-t, 2) * t * hindi4[1][col+1] + 3 * (1-t) * t * t * hindi4[1][col+2] + pow(t, 3) * hindi4[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 5){
            //for drawing 5
            for (int col = 0; col < 4 * crv5; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi5[0][col] + 3 * pow(1-t, 2) * t * hindi5[0][col+1] + 3 * (1-t) * t * t * hindi5[0][col+2] + pow(t, 3) * hindi5[0][col+3];
                    y = pow(1-t, 3) * hindi5[1][col] + 3 * pow(1-t, 2) * t * hindi5[1][col+1] + 3 * (1-t) * t * t * hindi5[1][col+2] + pow(t, 3) * hindi5[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 6){
            //for drawing 6
            for (int col = 0; col < 4 * crv6; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi6[0][col] + 3 * pow(1-t, 2) * t * hindi6[0][col+1] + 3 * (1-t) * t * t * hindi6[0][col+2] + pow(t, 3) * hindi6[0][col+3];
                    y = pow(1-t, 3) * hindi6[1][col] + 3 * pow(1-t, 2) * t * hindi6[1][col+1] + 3 * (1-t) * t * t * hindi6[1][col+2] + pow(t, 3) * hindi6[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 7){
            //for drawing 7
            for (int col = 0; col < 4 * crv7; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi7[0][col] + 3 * pow(1-t, 2) * t * hindi7[0][col+1] + 3 * (1-t) * t * t * hindi7[0][col+2] + pow(t, 3) * hindi7[0][col+3];
                    y = pow(1-t, 3) * hindi7[1][col] + 3 * pow(1-t, 2) * t * hindi7[1][col+1] + 3 * (1-t) * t * t * hindi7[1][col+2] + pow(t, 3) * hindi7[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 8){
            //for drawing 8
            for (int col = 0; col < 4 * crv8; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi8[0][col] + 3 * pow(1-t, 2) * t * hindi8[0][col+1] + 3 * (1-t) * t * t * hindi8[0][col+2] + pow(t, 3) * hindi8[0][col+3];
                    y = pow(1-t, 3) * hindi8[1][col] + 3 * pow(1-t, 2) * t * hindi8[1][col+1] + 3 * (1-t) * t * t * hindi8[1][col+2] + pow(t, 3) * hindi8[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }
        else if(sec2 == 9){
            //for drawing 9
            for (int col = 0; col < 4 * crv9; col +=4) {
                for (float t = 0; t <= 1; t += 0.001) {
                    float x, y;
                    x = pow(1-t, 3) * hindi9[0][col] + 3 * pow(1-t, 2) * t * hindi9[0][col+1] + 3 * (1-t) * t * t * hindi9[0][col+2] + pow(t, 3) * hindi9[0][col+3];
                    y = pow(1-t, 3) * hindi9[1][col] + 3 * pow(1-t, 2) * t * hindi9[1][col+1] + 3 * (1-t) * t * t * hindi9[1][col+2] + pow(t, 3) * hindi9[1][col+3];
                    putpixel(xc + sec2disp + x, yc - y, pixcolor);
                }
            }
        }

        delay(100);
        setactivepage(page);    setvisualpage(1 - page);    1 - page;
        cleardevice();
    }

    getch();
    return 0;
}
