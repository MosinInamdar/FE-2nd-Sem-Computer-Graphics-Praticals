#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void translateLine(int P[3][3], int T[3][3])
{ 
 int mul[][3]
    for(int i=0;i<3;i++)    
	{    
		for(int j=0;j<3;j++)    
		{      
			mul[i][j]=0; 	
			for(int k=0;k<3;k++)    
				{    
					mul[i][j]+=P[i][k]*T[k][j];    
				}    
		}    
	}	  
}

int main()
{
	int n,m;
	int mul[3][3]={{0,0,0},
			   {0,0,0},
			   {0,0,0}};
	int P[3][3] = {{150,300,50},
			     {150,250,250},
			     {1,1,1}}; 
   
     //cout<<"Enter the Value of Tx : "<<endl;
     //cin>>m;
     //cout<<"Enter the Value of Ty : "<<endl;
     //cin>>n;
       int T[3][3] = {{1,0,0},
     		      {0,1,0},
     		      {5,5,1}};
	//int gdriver = DETECT,gmode;
	//initgraph(&gdriver,&gmode,NULL);
	//line(150,150,300,250);
	//line(300,250,50,250);
	//line(50,250,150,150);
	translateLine(P, T, mul);
	for(int i=0;i<3;i++)    
{    
for(int j=0;j<3;j++)    
{    
cout<<mul[i][j]<<" ";    
}    
cout<<"\n";    
}    
	//line(mul[0][0],mul[1][0],mul[0][1],mul[1][1]);
	//line(mul[0][1],mul[1][1],mul[0][2],mul[1][2]);
	//line(mul[0][2],mul[1][2],mul[0][0],mul[1][0]);
	delay(5000);
	closegraph();
}
