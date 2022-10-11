// cpp program for translation
// of a single line
#include<bits/stdc++.h>
#include<graphics.h>
  
using namespace std;
  
void line(int x1,int x2,int y1,int y2)
{
	int dx=x2-x1,dy=y2-y1,steps;
	float xinc,yinc,x=x1,y=y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;
	for(int i=0;i<steps;i++)
	{
		putpixel(round(x),round(y),RED);
		x+=xinc;
		y+=yinc;
		}
}
// function to translate line
void translateLine ( int P[][2], int T[])
{
    /* init graph and line() are used for 
       representing line through graphical
       functions 
    */
    int gd = DETECT, gm, errorcode;
    initgraph (&gd, &gm, "c:\\tc\\bgi"); 
      
    // drawing original line using graphics functions
    setcolor (2);
    line(P[0][0], P[0][1], P[1][0], P[1][1]);
  
    // calculating translated coordinates
    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];
  
    // drawing translated line using graphics functions
    setcolor(3);
    line(P[0][0], P[0][1], P[1][0], P[1][1]);
    closegraph();
}
  
// driver program
int main()
{
    int P[2][2] = {5, 8, 12, 18}; // coordinates of point
    int T[] = {2, 1}; // translation factor
    translateLine (P, T);
    return 0;
} 
