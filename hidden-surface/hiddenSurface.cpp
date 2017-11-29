//Hidden surface implementation using Back-Face Detection
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
coord V = {700,500,1000};

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
    coord edge2 = {sfc[2].x - sfc[1].x, sfc[2].y - sfc[1].y, sfc[2].z - sfc[1].z};

    coord N = normalVector(edge1, edge2);
    coord MV = {V.x - M.x, V.y - M.y, V.z - M.z};

    long long int dp = dotProduct(MV, N);
//    cout << "dp : " << dp << "\n";
//    cout << "Mid : " << M.x << " " << M.y << " " << M.z << "\n";
//    cout << "MV : " << MV.x << " " << MV.y << " " << MV.z << "\n";
//    cout << "Normal : " << N.x << " " << N.y << " " << N.z << "\n\n";

    if (dp < 0)
        return false;   //surface is not hidden
    else
        return true;    //surface is hidden
}

int main()
{
    initwindow(1400, 900);
    int xc = getmaxx() / 2, yc = getmaxy() / 2, page = 0;
    int s = 4, v = 3, crv = 5;
    int sz = 200;

    //here we have to use redundant vertices to ease the implementation in for loop
    //though we have only 4 vertices for tetrahedron

    //tetrahedron vertices stored as [x y z 1] in each column
                             //S1           S2           S3           S4
    int vertex[4][s*v] = {  {sz,0,0,      sz,0,0,      0,0,0,       0,sz,0},
                            {0,0,sz,      0,0,0,       sz,0,0,      0,0,sz},
                            {0,0,0,       0,sz,0,      0,0,sz,      sz,0,0},
                            {1,1,1,       1,1,1,       1,1,1,       1,1,1}  };

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

        for (int i = 0; i < s * v; i += v){
            //converting the vertex matrix into array of co-ordinates of a given surface
            coord sfc[3] = {{xc + pts[0][i], yc + 100 - pts[1][i], pts[2][i]}, {xc + pts[0][i+1], yc + 100 - pts[1][i+1], pts[2][i+1]}, {xc + pts[0][i+2], yc + 100 - pts[1][i+2], pts[2][i+2]}};
            //if surface is not hidden then display it
            if (!hidden(sfc, 3)){
                int lcolor;

                switch(i){
                    case 0 :
                    case 3 :
                    case 6 :  lcolor = GREEN;   break;
                    case 9 :  lcolor = YELLOW;  break;
                }

                setcolor(lcolor);
                for(int j = 0; j < v; ++j)
                    line(xc + pts[0][i+j], yc + 100 - pts[1][i+j], xc + pts[0][i+(j+1)%v], yc + 100 - pts[1][i+(j+1)%v]);
            }
        }

        setactivepage(page);        setvisualpage(1-page);      delay(20);     cleardevice();
    }

    getch();
    return 0;
}
