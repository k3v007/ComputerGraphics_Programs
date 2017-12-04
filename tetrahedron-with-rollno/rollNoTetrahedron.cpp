#include <bits/stdc++.h>
#include <graphics.h>
#define MAX         10
#define PI          3.1416
#define COS(a)      cos(((a) * PI) / (float)180)
#define SIN(a)      sin(((a) * PI) / (float)180)

using namespace std;

//x y z coordinate
typedef struct{
    long long int x;
    long long int y;
    long long int z;
}coord;


//Calculating normal vector using cross-product formula
coord normalVector(coord edge1, coord edge2)
{
    coord normal;
    normal.x = edge1.y * edge2.z - edge1.z * edge2.y;
    normal.y = edge1.z * edge2.x - edge1.x * edge2.z;
    normal.z = edge1.x * edge2.y - edge1.y * edge2.x;

    return normal;
}

//return dot product of two vectors
long long int dotProduct(coord a, coord b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//setting the vision co-ordinate
coord V = {700,300,1000};

//calculating whether the given surface is hidden or not using the Back-face detection technique
bool hidden(coord sfc[MAX], int n)
{
    //sfc array contains the surface vertices in order of cross-product
    //calculating the midpoint of the surface
    coord M = {0,0,0};
    for(int i = 0; i < n; ++i) {
        M.x += sfc[i].x;
        M.y += sfc[i].y;
        M.z += sfc[i].z;
    }
    M.x /= n;
    M.y /= n;
    M.z /= n;

    //edge1 and edge2 for calculating normal vector
    coord edge1 = {sfc[1].x - sfc[0].x, sfc[1].y - sfc[0].y, sfc[1].z - sfc[0].z};
    coord edge2 = {sfc[2].x - sfc[1].x, sfc[2].y - sfc[1].y, sfc[2].z - sfc[1].z};;
    coord N = normalVector(edge1, edge2);
    coord MV = {V.x - M.x, V.y - M.y, V.z - M.z};

    long long int dp = dotProduct(MV, N);

    if (dp < 0)
        return false;   //surface is not hidden
    else
        return true;    //surface is hidden
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;
    int s = 4, v = 3, crv = 7;
    int sz = 200;

    //here we have to use redundant vertices to ease the implementation in for loop
    //though we have only 4 vertices for tetrahedron

    //tetrahedron vertices stored as [x y z 1] in each column
                              //S1        S2          S3          S4
    int vertex[4][s*v] = {  {sz,0,0,    sz,0,0,     0,0,0,      0,sz,0},
                            {0,0,sz,    0,0,0,      sz,0,0,     0,0,sz},
                            {0,0,0,     0,sz,0,     0,0,sz,     sz,0,0},
                            {1,1,1,     1,1,1,      1,1,1,      1,1,1}  };

    //coordinates of roll no. are set according to the surfaces of tetrahedron
    ///reference figure is provided in the folder

    int crv4 = 4;
    int hindi4[4][4*crv4] = {   {0,0,0,0,           0,0,0,0,            0,0,0,0,      0,0,0,0},
                                {65,105,115,140,    65,105,115,140,     65,35,5,0,    65,35,5,0},
                                {70,110,110,110,    70,30,30,30,        70,40,40,70,  70,110,110,70},
                                {1,1,1,1,           1,1,1,1,            1,1,1,1,      1,1,1,1}      };

    int crv0 = 2;
    int hindi0[4][4*crv0] = {   {50,10,10,100,   50,80,150,100},
                                {140,150,50,50,  140,150,50,50},
                                {50,80,150,100,  50,10,10,100},
                                {1,1,1,1,        1,1,1,1}    };

    int crv8 = 1;
    int hindi8[4][4*crv8] = {   {60,130,130,30},
                                {130,20,-20,40},
                                {0,0,0,0},
                                {1,1,1,1}    };


    int ang = 0;

    while(1){
        setcolor(LIGHTBLUE);    settextstyle(10, HORIZ_DIR, 1);
        outtextxy(xc - 300, yc - 350, "Press  'a'  for \"CW Rotation\" and  'd'  for \"CCW Rotation\"");

        //x-rotation matrix
        float rotx[4][4] = {    {1, 0, 0, 0},
                                {0, COS(ang), -SIN(ang), 0},
                                {0, SIN(ang), COS(ang), 0},
                                {0, 0, 0, 1}    };

        //y-rotation matrix
        float roty[4][4] = {    {COS(ang), 0, SIN(ang), 0},
                                {0, 1, 0, 0},
                                {-SIN(ang), 0, COS(ang), 0},
                                {0, 0, 0, 1}    };

        //z-rotation matrix
        float rotz[4][4] = {    {COS(ang), -SIN(ang), 0, 0},
                                {SIN(ang), COS(ang), 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}    };


        char ch = getch();      ch = tolower(ch);
        switch(ch){
            case 'a' :  --ang;  break;
            case 'd' :  ++ang;  break;
        }


        //multiplying the vertex with the y-rotation matrix
        float pts[4][s*v];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < s * v; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++)
                    sum += roty[i][k] * vertex[k][j];
                pts[i][j] = sum;
            }
        }

        //multiplying the roll no. with the y-rotation matrix
        float pts4[4][4*crv4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv4; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 0.8 * roty[i][k] * hindi4[k][j];
                }
                pts4[i][j] = sum;
            }
        }

        //multiplying the roll no. with the y-rotation matrix
        float pts0[4][4*crv0];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv0; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 0.8 * roty[i][k] * hindi0[k][j];
                }
                pts0[i][j] = sum;
            }
        }

        //multiplying the roll no. with the y-rotation matrix
        float pts8[4][4*crv8];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 * crv8; j++) {
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    sum += 0.8 * roty[i][k] * hindi8[k][j];
                }
                pts8[i][j] = sum;
            }
        }

        for (int i = 0; i < s * v; i += v){
            //converting the vertex matrix into array of co-ordinates of a given surface
            coord sfc[3] = {{xc + pts[0][i], yc - pts[1][i], pts[2][i]}, {xc + pts[0][i+1], yc - pts[1][i+1], pts[2][i+1]}, {xc + pts[0][i+2], yc - pts[1][i+2], pts[2][i+2]}};
            //if surface is not hidden then display it
            if (!hidden(sfc, 3)){
                int lcolor;

                switch(i){
                    case 0 :  lcolor = LIGHTMAGENTA;    break;
                    case 3 :  lcolor = LIGHTCYAN;       break;
                    case 6 :  lcolor = LIGHTGREEN;      break;
                    case 9 :  lcolor = YELLOW;          break;
                }

                //Calculating the mid-point
                coord M;
                M.x = (sfc[0].x + sfc[1].x + sfc[2].x) / 3;
                M.y = (sfc[0].y + sfc[1].y + sfc[2].y) / 3;

                setcolor(lcolor);
                for(int j = 0; j < v; ++j)
                    line(sfc[j].x, sfc[j].y, sfc[(j+1)%v].x, sfc[(j+1)%v].y);

                //filling color in the corresponding surfaces
                setfillstyle(SOLID_FILL, lcolor);
                floodfill(M.x, M.y, lcolor);


                if (i == 6) {       //4 is present on S3
                    for (int col = 0; col < 4 * crv4; col +=4) {            //for hindi 4
                        for (float t = 0; t <= 1; t += 0.001) {
                            float x, y;
                            x = pow(1-t, 3) * pts4[0][col] + 3 * pow(1-t, 2) * t * pts4[0][col+1] + 3 * (1-t) * t * t * pts4[0][col+2] + pow(t, 3) * pts4[0][col+3];
                            y = pow(1-t, 3) * pts4[1][col] + 3 * pow(1-t, 2) * t * pts4[1][col+1] + 3 * (1-t) * t * t * pts4[1][col+2] + pow(t, 3) * pts4[1][col+3];
                            putpixel(xc + x, yc - y, RED);
                        }
                    }
                }
                else if (i == 0) {          //8 is present on S1
                    for (int col = 0; col < 4 * crv8; col +=4) {            //for hindi 8
                        for (float t = 0; t <= 1; t += 0.001) {
                            float x, y;
                            x = pow(1-t, 3) * pts8[0][col] + 3 * pow(1-t, 2) * t * pts8[0][col+1] + 3 * (1-t) * t * t * pts8[0][col+2] + pow(t, 3) * pts8[0][col+3];
                            y = pow(1-t, 3) * pts8[1][col] + 3 * pow(1-t, 2) * t * pts8[1][col+1] + 3 * (1-t) * t * t * pts8[1][col+2] + pow(t, 3) * pts8[1][col+3];
                            putpixel(xc + x, yc - y, RED);
                        }
                    }
                }
                else if (i == 9) {      //0 is present on S4
                    for (int col = 0; col < 4 * crv0; col +=4) {            //for hindi 0
                        for (float t = 0; t <= 1; t += 0.001) {
                            float x, y;
                            x = pow(1-t, 3) * pts0[0][col] + 3 * pow(1-t, 2) * t * pts0[0][col+1] + 3 * (1-t) * t * t * pts0[0][col+2] + pow(t, 3) * pts0[0][col+3];
                            y = pow(1-t, 3) * pts0[1][col] + 3 * pow(1-t, 2) * t * pts0[1][col+1] + 3 * (1-t) * t * t * pts0[1][col+2] + pow(t, 3) * pts0[1][col+3];
                            putpixel(xc + x, yc - y, RED);
                        }
                    }
                }
            }
        }

        setactivepage(page);        setvisualpage(1-page);     cleardevice();
    }

    getch();
    return 0;
}
