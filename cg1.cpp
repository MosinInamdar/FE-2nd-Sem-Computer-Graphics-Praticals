#include<iostream>
#include<graphics.h>

int main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	line(20,40,200,400);
	setcolor(GREEN);
	circle(205,250,100);
	delay(5000);
	closegraph();
}
