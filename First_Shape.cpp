
#include<iostream>

#include <graphics.h>
#include<math.h>
 void DDALine(float x0, float y0, float x1, float y1) {

    int dx = x1 - x0;
    int dy= y1 - y0;

    int step;
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);


    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;


    float x = x0;
    float y = y0;

    for (int i = 0; i < step; i ++) {

          putpixel(round(x), round(y), BLUE);
        x += x_incr;
        y += y_incr;
    }
}





void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);

    }
}


int main()
{
    int xc , yc, r ;
    float x0 , y0 , x1, y1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circleBres(350, 250,30);
    circleBres(350, 250, 60);
    DDALine(401.9, 280, 298.1, 280);
    DDALine(401.9, 280, 350, 190);
    DDALine(298.1, 280, 350, 190);



    delay(100000);
    closegraph();
    return 0;

}
