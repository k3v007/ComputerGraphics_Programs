//Polygon filling through Scan-line approach
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX     10

using namespace std;

typedef struct{
    int x;
    int y;
}coord;

void scanline(coord pts[MAX], int n, int color)
{
    int ymin = INT_MAX, ymax = -INT_MAX;
    int xi[MAX];
    float slope[MAX];

    for (int i = 0; i < n; i++) {
        ymin = min(ymin, pts[i].y);
        ymax = max(ymax, pts[i].y);
    }

    for (int i = 0; i < n; i++) {
        int dy = pts[(i+1)%n].y - pts[i].y;
        int dx = pts[(i+1)%n].x - pts[i].x;
        if (dy == 0)
            slope[i] = 1.0;
        if (dx == 0)
            slope[i] = 0.0;
        if ((dy != 0) && (dx != 0))             // calculate inverse slope
            slope[i] = (float) dx / dy;
    }

    for(int y = ymin + 1; y < ymax; y++) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (((pts[i].y <= y) && (pts[(i+1)%n].y > y)) || ((pts[i].y > y) && (pts[(i+1)%n].y <= y))) {
                xi[k] = (int)(pts[i].x + slope[i] * (y - pts[i].y));
                k++;
            }
        }

        for(int j = 0; j < k - 1; j++) {        //Arrange x-intersections in order
            for(int i = 0; i < k - 1; i++) {
                if(xi[i] > xi[i+1]) {
                    swap(xi[i], xi[i+1]);
                }
            }

            setcolor(color);
            for(int i = 0; i < k; i += 2)
                line(xi[i]+1, y, xi[i+1], y);
        }
    }
}

int main()
{
    initwindow(1400, 900);
    int n, color;
    coord pts[MAX];

    cout << "Enter no. of vertices of polygon : ";      cin >> n;
    cout << "\nEnter co-ordinates in cyclic order :\n";

    for (int i = 0; i < n; ++i){
        int x, y;
        cout << "Enter (x, y) of vertex no. " << i + 1 << " : ";
        cin >> x >> y;
        pts[i] = {x, y};
    }

    cout << "\nEnter color (1 - 15) : ";          cin >> color;

    for (int i = 0; i < n; i++)
        line(pts[i].x, pts[i].y, pts[(i+1)%n].x, pts[(i+1)%n].y);

    scanline(pts, n, color);

    getch();
    return 0;
}

/*Test Case:
4
200 200
200 800
800 800
800 200
10
*/
