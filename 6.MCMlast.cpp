#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
int MatrixChainOrder(int p[10],int m[10][10],int t[10][10],int n){
	int j,num=0;
	for (int i=1; i<n; i++){
		m[i][i] = 0;
		t[i][i] = 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++){
			m[i][j] = 0;
			t[i][j] = 0;
		}
	for(int l=2; l<=n; l++){
		for(int i=1; i<=n-l+1; i++){
			j = i+l-1;
			m[i][j]=0x7fffffff;
			for(int k=i; k<=j-1; k++){
				num = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(num < m[i][j]){
					m[i][j] = num;
					t[i][j] = k;
				}
			}
		}
	}
	for (int x=1; x<n; x++){
		for(int y=1; y<n; y++)
			cout<<"\t "<<m[x][y];
		cout<<endl;
	}
	cout<<"\n K Matrix Is >  \n";;
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++)
			cout<<"\t "<<t[i][j];
		cout<<endl;
	}
	return m[1][n-1];
}
void PrintAnswer(int t[10][10],int i,int j){
	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		PrintAnswer(t,i,t[i][j]);
		PrintAnswer(t,t[i][j]+1,j);
		cout<<")";
	}
}

int main(){
	int p[10],n;
	double time;
	cout<<"Enter No. Of Array :  ";
	cin>>n;
	cout<<"\n Enter Size Of Matries(Row of 1st & Columns Of All Matries) >  \n ";
	for(int i=0; i<=n; i++){
		cin>>p[i];
	}
	int m[10][10],t[10][10];
	clock_t start;
	start = clock();
	int a = MatrixChainOrder(p,m,t,n+1);
	cout<<endl<<"\t";
	PrintAnswer(t,1,n);
	cout<<"\n Minimum number of multiplications is :  "<<a;
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
	return 0;
}


//	Matrix-Chain-Order(p)
//	n = length[p] - 1
//	for i = 1 to n
//	do m[i, i] = 0
//	for l = 2 to n = l is the chain length.
//	do for i = 1 to n - l + 1
//	do j = i + l - 1
//	m[i, j] = 8
//	for k = i to j - 1
//	do q = m[i, k] + m[k + 1, j] + p(i-1)p(k)p(j)
//	if q < m[i, j]
//	then m[i, j] = q
//	s[i, j] = k
//	return m and s

//O(n^2)
