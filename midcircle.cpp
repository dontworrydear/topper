#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class CircleDrawer {
public:
    void circle(int x, int y, int rad) {
        int x1 = 0;
        int y1 = rad;
        putpixel(x1, y1, 6);
        int pk = 3 - 2 * rad;
        
        while (x1 < y1) {
            if (pk <= 0) {
                pk = pk + (4 * x1) + 6;
            } else {
                pk = pk + 4 * (x1 - y1) + 10;
                y1--;
            }
            x1++;
            
            // Plotting across 8 symmetrical octants
            putpixel(x + x1, y + y1, 3);
            putpixel(x - x1, y + y1, 3);
            putpixel(x + x1, y - y1, 3);
            putpixel(x - x1, y - y1, 3);
            putpixel(x + y1, y + x1, 3);
            putpixel(x - y1, y + x1, 3);
            putpixel(x + y1, y - x1, 3);
            putpixel(x - y1, y - x1, 3);
            
            delay(10);
        }
    }
} c;

int main() {
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, NULL);
    
    // Draw the circle centered at (250, 250) with radius 100
    c.circle(250, 250, 100);
    
    delay(500);
    closegraph();
    return 0;
}
