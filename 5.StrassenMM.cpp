#include<iostream>
#include<conio.h>

using namespace std;
int main(){
	int a[2][2],b[2][2],c[2][2],i,j;
	int p1,p2,p3,p4,p5,p6,p7;
	cout<<"\n Enter First Matrix Elements 2x2 >\n";
	for(i=1;i<=2;i++)
		for(j=1;j<=2;j++)
			cin>>a[i][j];
	cout<<"\n Enter Second Matrix Elements 2x2 >\n";
	for(i=1;i<=2;i++)
		for(j=1;j<=2;j++)
			cin>>b[i][j];
	
	p1=a[1][1]*(b[1][2]-b[2][2]);
	p2=(a[1][1]+a[1][2])*b[2][2];
	p3=(a[2][1]+a[2][2])*b[1][1];
	p4=a[2][2]*(b[2][1]-b[1][1]);
	p5=(a[1][1]+a[2][2])*(b[1][1]+b[2][2]) ;
	p6=(a[1][2]-a[2][2])*(b[2][1]+b[2][2]) ;
	p7=(a[1][1]-a[2][1])*(b[1][1]+b[1][2]) ;
	
	c[1][1]=p5+p4-p2+p6;
	c[1][2]=p1+p2;
	c[2][1]=p3+p4;
	c[2][2]=p5+p1-p3-p7;
	
	cout<<"\n Strassen Matrix Multiplication Result >>\n";
	for(i=1;i<=2;i++){
		for(j=1;j<=2;j++)
			cout<<" "<<c[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}

//O(n^2.8)
