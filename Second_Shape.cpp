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
    putpixel(xc+x, yc+y ,RED);
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


    circleBres(300,200,83);
    DDALine(300,100,150,200);
    DDALine(150,200,300,300);
    DDALine(300,300,450,200);
    DDALine(300,100,450,200);
    DDALine(150,100,450,100);
    DDALine(150,300,450,300);
    DDALine(450,300,450,100);
    DDALine(150,300,150,100);


    delay(100000);
    closegraph();
    return 0;

}

