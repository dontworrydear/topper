#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class LineDrawer {
    int x, y, dx, dy, xi, yi, steps;
public:
    void put() {
        putpixel(x, y, 9);
    }

    void lin(int x1, int y1, int x2, int y2) {
        dx = x2 - x1;
        dy = y2 - y1;
        
        if (abs(dx) > abs(dy))
            steps = abs(dx);
        else
            steps = abs(dy);

        xi = dx / steps;
        yi = dy / steps;

        x = x1 + 0.5;
        y = y1 + 0.5;
        put();

        for (int i = 1; i <= steps; i++) {
            x = x + xi;
            y = y + yi;
            put();
            delay(5);
        }
    }
} l;

int main() {
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, NULL);
    
    // Draw the box and internal diagonal lines (diamond pattern)
    l.lin(100, 100, 400, 100);
    l.lin(100, 400, 400, 400);
    l.lin(100, 100, 100, 400);
    l.lin(400, 100, 400, 400);
    l.lin(250, 100, 100, 250);
    l.lin(100, 250, 250, 400);
    l.lin(250, 100, 400, 250);
    l.lin(400, 250, 250, 400);

    delay(500);
    closegraph();
    return 0;
}
