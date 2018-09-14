#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n){
	int i, w, M[n], j=0;
	int K[n+1][W+1];
	for (i=0; i<=n; i++){
		for (w = 0; w <= W; w++){
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w){
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
				M[j++] = 
			}
			else
				K[i][w] = K[i-1][w];
		}
	}
	for(int i=0; i<=n; i++){
		for(int w=0; w<=W; w++){
			cout<<"\t "<<K[i][w];
			w += 9;
		}
		cout<<endl;
	}
	return K[n][W];
}
int main(){
    int n, W, val[10], wt[10];
    double time;
    cin>>n>>W;
    cout<<"\n Value \t Weight\n";
	for(int i=0; i<n; i++)
		cin>>val[i]>>wt[i];
	clock_t start;
	start = clock();
	cout<<" Max Value We Can Obtain : "<<knapSack(W, wt, val, n);
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
    return 0;
}

//	Dynamic-0-1-knapsack (v, w, n, W) 
//	for w = 0 to W do 
//	   c[0, w] = 0 
//	for i = 1 to n do 
//	   c[i, 0] = 0 
//	   for w = 1 to W do 
//	      if wi = w then 
//	         if vi + c[i-1, w-wi] then 
//	            c[i, w] = vi + c[i-1, w-wi] 
//	         else c[i, w] = c[i-1, w] 
//	      else 
//	         c[i, w] = c[i-1, w]

//O(nW)
