// Write C++ program to draw the pattern. Use DDA line and Bresenham‘s circle drawing algorithm.

# include <graphics.h> //graphics.h library is used to include  graphical operations in a program.
# include <math.h>
# include <iostream>
using namespace std ;

void DDALine(int x1,int y1,int x2,int y2,int Color); //declare function

int main()
{
    
    int x1,y1,x2,y2,r,r1,Color;
    int gd,gm; gd=DETECT;    //Initialize the variables for the graphics driver and graphics mode
                             // gm is Graphics mode which is a computer display mode that generates image using pixels.
                            // DETECT is a macro defined in "graphics.h" header file
initgraph(&gd,&gm,NULL);    // initgraph initializes the graphics system by loading a graphics driver from disk
 
    cleardevice(); // The header file graphics.h contains cleardevice() function which clears the screen in graphics mode and sets the current position to (0,0)
                     //call function
  DDALine(100,113,50,200,4);  //x1,y1,x2,y2,value of color
  DDALine(50,200,150,200,4);
  DDALine(150,200,100,113,4);

r=50/sqrt(3); //formula to find out radius of small circle
x1=(100+50+150)/3;
y1=(113+200+200)/3;

circle(x1,y1,r);    //draw small circle

r1=100/sqrt(3);   //formula to find out radius of outer circle
circle(x1,y1,r1); //draw outer circle

delay(10000); //delay() function is used to hold the program's execution for given number of milliseconds
 
    return 0;
}
                 // define function
void DDALine(int x1,int y1,int x2,int y2,int Color)
{
    float dX,dY,Steps;
    float xInc,yInc,i,x,y;

    dX = x2 - x1;
    dY = y2 - y1;

    if (abs(dX) > abs(dY))
    {
        Steps = abs(dX);
    }
    else
    {
        Steps = abs(dY);
    }

    xInc = dX/Steps;
    yInc = dY/Steps;

    x = x1;
    y = y1;

    for (i=1;i<=Steps; i++)
    {
        putpixel(x,y,Color);//The header file graphics. h contains putpixel() function which plots a pixel at location (x, y)of specified color
        x = x+xInc;
        y=y+yInc;
    }
}
