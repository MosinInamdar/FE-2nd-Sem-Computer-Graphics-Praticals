#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void Mul(float matrix1[3][3], float matrix2[3][3]){//Matrix Multiplication 
 	float mult[3][3];
	int i,j,k;
     for(int i=0;i<3;i++)    
	 {    
		 for(int j=0;j<3;j++)    
		 {     
		 	mult[i][j]=0;  
			 for(int k=0;k<3;k++)    
				 {    
				 mult[i][j]+=matrix1[i][k]*matrix2[k][j];    
				 }    
		 }    
	 }
	 
	 line(mult[0][0],mult[0][1],mult[1][0],mult[1][1]);
	 line(mult[1][0],mult[1][1],mult[2][0],mult[2][1]);
	 line(mult[2][0],mult[2][1],mult[0][0],mult[0][1]);
	 delay(9000);	  
}
void translation(float cord_mat[3][3]){//Translation Factor Input 
	float tx,ty;
	cout<<"Enter translation factors : ";
	cin>>tx>>ty;
	setcolor(BLUE);
	float trans_mat[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};//Storing Translation Matrix 
	Mul(cord_mat,trans_mat);//Calling matrix multiplication method 
}
void Scaling(float cord_mat[3][3]){//Scaling Factor Input
	float Sx,Sy;
	cout<<"Enter Scaling factors : ";
	cin>>Sx>>Sy;
	setcolor(RED);
	float Scal_mat[3][3]={{Sx,0,0},{0,Sy,0},{0,0,1}};//Storing Scaling Matrix
	Mul(cord_mat,Scal_mat);
}
void Clockwise_Rotation(float cord_mat[3][3]){//Scaling Factor Input
	float angle;
	cout<<"Enter Rotation factors : ";
	cin>>angle;
	float rad=angle*0.01745;
	setcolor(RED);
	float rot_mat[3][3]={{cos(rad),-sin(rad),0},{sin(rad),cos(rad),0},{0,0,1}};
	Mul(cord_mat,rot_mat);
}
void Anticlockwise_Rotation(float cord_mat[3][3]){//Scaling Factor Input
	float angle2;
	cout<<"Enter Rotation factors : ";
	cin>>angle2;
	float rad2=angle2*0.01745;
	setcolor(RED);
	float arot_mat[3][3]={{cos(rad2),sin(rad2),0},{-sin(rad2),cos(rad2),0},{0,0,1}};
	Mul(cord_mat,arot_mat);
}

int main()
{	
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,NULL);
	float x1,y1,x2,y2,x3,y3;
	float x1_,y1_,x2_,y2_,x3_,y3_;
	cout<<"Enter coordinates of triangle "<<endl;
	cout<<"Enter x1,y1"<<endl;
	cin>>x1>>y1;
	cout<<"Enter x2,y2"<<endl;
	cin>>x2>>y2;
	cout<<"Enter x3,y3"<<endl;
	cin>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	int n;
	float cord_mat[3][3]={{x1,y1,1},{x2,y2,1},{x3,y3,1}};
	do{
	cout<<"Enter \n 1. For Translation \n 2. For Scaling \n 3. For Clockwise Rotation \n 4. For Anticlockwise Rotation \n 0. Exit"<<endl;
	cin>>n;
	
	switch(n){
	case 1:{
		translation(cord_mat);
		break;}
	case 2:{Scaling(cord_mat);break;}
	case 3:{Clockwise_Rotation(cord_mat);break;}
	case 4:{Anticlockwise_Rotation(cord_mat);break;}
	}
	}while(n!=0);
	closegraph();
	return 0;
}


