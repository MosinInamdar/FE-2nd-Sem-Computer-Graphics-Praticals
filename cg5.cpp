#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
using namespace std;
void drawline (int x1, int y1, int x2, int y2)
{
    int dx,dy,m,s;
    float xi,yi,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        s=abs(dx);
    else
        s=abs(dy);
    xi=dx/(float)s;
    yi=dy/(float)s;
    x=x1;
    y=y1;
    putpixel(x1,y1,WHITE);
    for(m=0;m<s;m++)
    {
        x+=xi;
        y+=yi;
        putpixel(x,y,WHITE);
    }

{
        x+=xi;
        y+=yi;
        putpixel(x,y,WHITE);
    }
}
void rectangle(int x1,int y1,int x2,int y2)
{
	int n=(x1+x2)/2;
	int m=(y1+y2)/2;
	int c=y1/2;
	int d=x2/2;
	int q =y2/2;
	int e=x1/2;
	drawline(x1,y1,x2,y1);
     drawline(x2,y1,x2,y2);
     drawline(x2,y2,x1,y2);
     drawline(x1,y2,x1,y1);
     drawline(n,y1,x2,m);
     drawline(x2,m,n,y2);
     drawline(n,y2,x1,m);
     drawline(x1,m,n,y1);
     drawline((3*(x1)+x2)/4,(3*(y1)+y2)/4,(3*(x2)+x1)/4,(3*(y1)+y2)/4);
     drawline((3*(x2)+x1)/4,(3*(y1)+y2)/4,(3*(x2)+x1)/4,(3*(y2)+y1)/4);
     drawline((3*(x2)+x1)/4,(3*(y2)+y1)/4,(3*(x1)+x2)/4,(3*(y2)+y1)/4);
     drawline((3*(x1)+x2)/4,(3*(y2)+y1)/4,(3*(x1)+x2)/4,(3*(y1)+y2)/4);
    }

int main()
{
	int x1,y1,x2,y2;
	cout<<"Enter value of x1,y1,x2,y2 : "<< endl;
	cin>>x1>>y1>>x2>>y2;
    int gd = DETECT, gm = DETECT, gmode;
    initgraph(&gd, &gm, NULL);
    rectangle(x1,y1,x2,y2);
    delay(300);	
    getch();
    closegraph();
    return 0;
}
