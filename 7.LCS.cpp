#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
 
void lcs( char X[50], char Y[50]){
	int m = strlen(X);
	int n = strlen(Y);
	int L[m+1][n+1];
	char B[m][n];
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1]){
				L[i][j] = L[i-1][j-1] + 1;
				B[i][j] = '*';
			}
			else{
				if(L[i-1][j] >= L[i][j-1]){
					L[i][j] = L[i-1][j];
					B[i][j] = '|';
				}else{
					L[i][j] = L[i][j-1];
					B[i][j] = '<';
				}
			}
		}
	}
  	int index = L[m][n];
  	char lcs[index+1];
   	lcs[index] = '\0';
	int i = m, j = n;
	while (i > 0 && j > 0){
		if (X[i-1] == Y[j-1]){
			lcs[index-1] = X[i-1];
			i--; j--; index--;
		}
		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	cout<<"LCS of "<<X<<" and "<<Y<<" is "<<lcs<<"\n\n";
	cout<<" L - Matrix >\n";
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++)
			cout<<"   "<<L[i][j]<<"   ";
		cout<<endl;	
	}
	cout<<"\n\n K - Matrix >\n";
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			cout<<"   "<<B[i][j]<<"   ";
		cout<<endl;	
	}
}
int main(){
	char X[50],Y[50];
	double time;
	cin>>X>>Y;
	clock_t start;
	start = clock();
	lcs(X, Y);
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
	return 0;
}

//	Algorithm: LCS-Length-Table-Formulation (X, Y)
//	m := length(X) 
//	n := length(Y) 
//	for i = 1 to m do 
//	   C[i, 0] := 0 
//	for j = 1 to n do 
//	   C[0, j] := 0 
//	for i = 1 to m do 
//	   for j = 1 to n do 
//	      if xi = yj 
//	         C[i, j] := C[i - 1, j - 1] + 1 
//	         B[i, j] := ‘D’ 
//	      else 
//	         if C[i -1, j] = C[i, j -1] 
//	            C[i, j] := C[i - 1, j] + 1 
//	            B[i, j] := ‘U’ 
//	         else 
//	         C[i, j] := C[i, j - 1] + 1 
//	         B[i, j] := ‘L’ 
//	return C and B

//O(mn)
