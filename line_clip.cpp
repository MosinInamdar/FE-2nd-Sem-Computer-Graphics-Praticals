
#include<graphics.h>
#include<iostream>
using namespace std;

//Regions
    int INSIDE = 0;
    int TOP = 1;
    int BOTTOM = 2;
    int LEFT = 4;
    int RIGHT = 8;

    int xmax=200;
    int ymax=200;
    int xmin=100;
    int ymin=100;

int compute_code(int x,int y){

    int pt = INSIDE;

    if (y > ymax)
        pt = TOP;
    else if (y < ymin)
        pt = BOTTOM;
    if (x > xmax)
        pt = RIGHT;
    if (x < xmin)
        pt = LEFT;

    return pt;
}

void line_clipping(int x1,int y1,int x2,int y2){

    int pt1 = compute_code(x1,y1);
    int pt2 = compute_code(x2,y2);

    bool accept = false;
    cout<<pt1<<pt2;
    while (true)
    {

    if ((pt1 == 0) && (pt2 == 0)){
        cout<<"INside\n";
        accept = true;
        break;
    }
    else if (pt1 & pt2){
        cout<<"OUTside\n";
        break;
    }
    else{
        int outpt;
        double x,y;
        if (pt1 != 0)
            outpt = pt1;
        else
            outpt = pt2;

        if (outpt & TOP){
            x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            y = ymax;
        }
        else if (outpt & BOTTOM){
            x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            y = ymin;
        }
        else if (outpt & RIGHT){
            y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            x = xmax;
        }
        else if (outpt & LEFT){
            y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            x = xmin;
        }

        if (outpt == pt1){
            x1 = x;
            y1 = y;
            pt1 = compute_code(x1,y1);
        }
        else{
            x2 = x;
            y2 = y;
            pt2 = compute_code(x2,y2);
        }
    }

    }


    if (accept) {
        cout << "Line accepted from " << x1 << ", "
            << y1 << " to " << x2 << ", " << y2 << endl;
    }
    else{
        cout << "Line rejected" << endl;
    }
}

int main(){

    line_clipping(50,50,270,230);


    return 0;
}
