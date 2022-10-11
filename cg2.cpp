#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(int x1,int x2,int y1,int y2)
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
int main()
{
	cout<<"enter values for x1,y1,x2,y2";
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	dda(x1,y1,x2,y2);
	delay(5000);
	closegraph();
}
