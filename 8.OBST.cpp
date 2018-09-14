#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define z 20
using namespace std;
int C[z][z], W[z][z], R[z][z], q[z], p[z], nk, key[z];
void compute(){
	int x, min;
	int i, j, k, h, m;
	for(i=0; i<=nk; i++) {
		W[i][i] = q[i];
		for(j=i+1; j<=nk; j++)
			W[i][j] = W[i][j-1] + p[j] + q[j];
	}
	for(i=0; i<=nk; i++)
		C[i][i] = W[i][i];
	for(i=0; i<=nk-1; i++) {
		j = i + 1;
		C[i][j] = C[i][i] + C[j][j] + W[i][j];
		R[i][j] = j;
	}
	for(h=2; h<=nk; h++)
		for(i=0; i<=nk-h; i++) {
			j = i + h;
			m = R[i][j-1];
			min = C[i][m-1] + C[m][j];
			for(k=m+1; k<=R[i+1][j]; k++){
				x = C[i][k-1] + C[k][j];
				if(x < min) {
					m = k;
					min = x;
				}
			}
			C[i][j] = W[i][j] + min;
			R[i][j] = m;
		}
	cout<<"\n The Weight matrix W:\n";
	for(i=0; i<=nk; i++){
		for(j=i; j<=nk; j++)
			cout<<" "<<W[i][j];
		cout<<endl;
	}
	cout<<"\n The Cost matrix C:\n";
	for(i=0; i<=nk; i++){
		for(j=i; j<=nk; j++)
			cout<<" "<<C[i][j];
		cout<<endl;
	}
	cout<<"\n The Root matrix R:\n";
	for(i=0; i<=nk; i++){
		for(j=i; j<=nk; j++)
			cout<<" "<<R[i][j];
		cout<<endl;
	}
}
void obst(){
	float average;
	compute();
	printf(" C[0] = %d W[0] = %d\n", C[0][nk], W[0][nk]);
	average = C[0][nk]/(float)W[0][nk];
	cout<<" The cost per weight ratio is: "<<average<<endl;
}
int main(){
	int i, k;
	double time;
	cout<<" Input number of key: ";
	cin>>nk;
	for(i=1; i <=nk; i++) {
		printf(" key[%d]    = ",i);
		cin>>key[i];
		cout<<" frequency = ";
		cin>>p[i];
	}
	for(i=0 ; i<=nk; i++) {
		printf(" q[%d] = ", i); 
		cin>>q[i];
	}
	clock_t start;
	start = clock();
	obst();
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
	return 0;
}
//	
//	Optimal-Binary-Search-Tree(p, q, n) 
//	e[1…n + 1, 0…n],  
//	w[1…n + 1, 0…n], 
//	root[1…n + 1, 0…n]  
//	for i = 1 to n + 1 do 
//	   e[i, i - 1] := qi - 1 
//	   w[i, i - 1] := qi - 1  
//	for l = 1 to n do 
//	   for i = 1 to n – l + 1 do 
//	      j = i + l – 1 e[i, j] := 8 
//	      w[i, i] := w[i, i -1] + pj + qj 
//	      for r = i to j do 
//	         t := e[i, r - 1] + e[r + 1, j] + w[i, j] 
//	         if t < e[i, j] 
//	            e[i, j] := t 
//	            root[i, j] := r 
//	return e and root 

//O(n^3)
