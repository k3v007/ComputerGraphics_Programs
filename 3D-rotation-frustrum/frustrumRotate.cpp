//3D rotation along x-, y-, z-axis
#include<graphics.h>
#include<bits/stdc++.h>
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)
//COS and SIN uses angle a in radian

using namespace std;

int main()
{
    initwindow(700, 480);
    //vertices of frustrum
    int p[4][8] = {     {-40,  40,  40,   -40,  -20,  20,  20,   -20},
                        {40,   40,  -40,  -40,  20,   20,  -20,  -20},
                        {0,    0,   0,    0,    60,   60,  60,   60},
                        {1,    1,   1,    1,    1,    1,   1,    1}   };

    int i, j, k, page = 0;
    int ang = 0;

    while(1)
    {
        settextstyle(11, HORIZ_DIR, 1);      setcolor(LIGHTGREEN);
        outtextxy(200, 50, "Press 'a' for \"CW Rotation\" and 'd' for \"CCW Rotation\"");

        //z rotation matrix
        float rotz[4][4] = {    COS(ang), -SIN(ang), 0, 0,
                                SIN(ang), COS(ang),  0, 0,
                                0,        0,         1, 0,
                                0,        0,         0, 1   };

        float pts[4][8];
        for (i = 0; i <= 3; i++) {
            for (j = 0; j <= 8; j++) {
                int sum = 0;
                for (k = 0; k <= 3; k++) {
                    sum += rotz[i][k] * p[k][j];
                }
                pts[i][j] = sum;
            }
        }

        //due to symmetry of the surfaces, first front surface is drawn then back surface is drawn
        //and finally the edges connecting the front and the back surfaces

        //top view - we are drawing in xy plane
        //z coordinate is set to 0 or not taken
        setcolor(LIGHTRED);
        for(i = 0; i < 4; i++) {
            line(140 + pts[0][i],   240 - pts[1][i],   140 + pts[0][(i+1)%4],   240 - pts[1][(i+1)%4]);
            line(140 + pts[0][i+4], 240 - pts[1][i+4], 140 + pts[0][(i+1)%4+4], 240 - pts[1][(i+1)%4+4]);
            line(140 + pts[0][i],   240 - pts[1][i],   140 + pts[0][i+4],       240 - pts[1][i+4]);
        }

        //front view - we are drawing in xz plane
        //y coordinate is set to 0 or not taken
        for(i = 0; i < 4; i++) {
            line(350 + pts[0][i],   260 - pts[2][i],   350 + pts[0][(i+1)%4],   260 - pts[2][(i+1)%4]);
            line(350 + pts[0][i+4], 260 - pts[2][i+4], 350 + pts[0][(i+1)%4+4], 260 - pts[2][(i+1)%4+4]);
            line(350 + pts[0][i],   260 - pts[2][i],   350 + pts[0][i+4],       260 - pts[2][i+4]);
        }

        //side view - we are drawing in yz plane
        //x coordinate is set to 0 or not taken
        for(i = 0; i < 4; i++) {
            line(530 + pts[2][i],   240 - pts[1][i],   530 + pts[2][(i+1)%4],   240 - pts[1][(i+1)%4]);
            line(530 + pts[2][i+4], 240 - pts[1][i+4], 530 + pts[2][(i+1)%4+4], 240 - pts[1][(i+1)%4+4]);
            line(530 + pts[2][i],   240 - pts[1][i],   530 + pts[2][i+4],       240 - pts[1][i+4]);
        }

        char ch = getch();  ch = tolower(ch);
        if (ch == 'd') {
            ang += 2;
        }
        else if (ch == 'a') {
            ang -= 2;
        }

        setactivepage(page);        setvisualpage(1 - page);
        page = 1 - page;            cleardevice();
    }

    getch();
    return 0;
}

