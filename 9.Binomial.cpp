#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std; 
int binomialCoeff(int n, int k){
	if (k==0 || k==n)
    	return 1;
	int x = binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
//	printf("\n C(%d, %d) is %d ", n, k, x);
	return x;
}
int main(){
	int n,k;
	double time;
	cout<<"n, r";
	cin>>n>>k;	
	clock_t start;
	start = clock();
	printf("\n Value of C(%d, %d) is %d \n", n, k, binomialCoeff(n, k));
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
	return 0;
}

//	binomial(n,k)
//	k=0 or k=n ?
//		return 1
//	return(binomial(n-1,k-1)+binomial(n-1,k))
//	
//	O(nk)
