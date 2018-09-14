#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

using namespace std;

void merge(int A[], int p, int q, int r){
	int i,j,k,l,C[10000];
	i = p;
	j = q+1;
	k = p;
	while(i<=q && j<=r)
		if(A[i] < A[j])
			C[k++] = A[i++];
		else
			C[k++] = A[j++];
	while(i<=q)
		C[k++] = A[i++];
	while(j<=r)
		C[k++] = A[j++];
	l = p;
	while(l<=r)
		A[l] = C[l++];
}

void merge_sort(int A[], int p, int r){
	int q;
	if(p<r){
		q = floor((p+r)/2);
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main(){
	int Array[10000],p,q,r,x=6;
	int n;
	double time;
	do{
		cout<<"\n Enter Num. Of Elements : ";
		cin>>n;
		for(int i=0;i<n;i++)
			Array[i] = rand()%n +1;
		cout<<" Elements Assinged. ";
		clock_t start;
		start = clock();
		merge_sort(Array,0,n-1);
		clock_t end;
		end = clock();
		time = (end - start);
		if(n < 100){
			cout<<"\n Sorted Array : \n";
			for(int i=0; i<n; i++)
				cout<<" "<<Array[i];
			cout<<endl;
		}
		cout<<endl;
		cout<<" Starting Time : "<<start<<"\n";
		cout<<" Ending Time : "<<end<<"\n";
		cout<<" Time : "<<time<<" Milliseconds\n";
	}while(--x);
	return 0;
}

//	MergeSort(A, p, r)
//	    If p > r 
//	        return;
//	    q = (p+r)/2;
//	    mergeSort(A, p, q)
//	    mergeSort(A, q+1, r)
//	    merge(A, p, q, r)

//	merge(A, p, q, r)
//		i = p, j = q+1, k = p
//		while i<=q && j<=r
//			do if(A[i] < A[j])
//				C[k++] = A[i++]
//			else
//				C[k++] = A[j++]
//		while(i<=q)
//			do C[k++] = A[i++]
//		while(j<=r)
//			do C[k++] = A[j++]
//		l = p
//		while(l<=r)
//			do A[l] = C[l++]


//	O(nlgn)
