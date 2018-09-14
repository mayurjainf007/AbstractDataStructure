#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

using namespace std;
static int n;
static bool z = true;

void quick(int a[], int lb, int ub){
	int p, temp, i, j;
	if(lb < ub){
 		p = a[lb];
		i = lb;
		j = ub;
		while(i < j){
			while(a[i]<=p && i<j )
				i++;
			while(a[j]>p && i<=j )
				j--;
			if(i <= j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[lb];
		a[lb] = temp;
		if(n < 100){
		cout<<endl;
			for(int i=lb; i<= ub; i++)
				cout<<a[i]<<" ";
		}
		quick(a, lb, j-1);
		quick(a, j+1, ub);
	}
}

int main(){
	int Array[20000],lb,ub,i,x=4;
	double time;
	cout<<"\n There Is No Such Senario For Best\n Case In Randomized Quick Sort\n";
	do{
		cout<<"\n Main Menu..\n 1. Enter Ur Own Terms\n 2. Average Case(Random Array)\n 3. Worst Case(Sorted Array)\n 4. Exit";
		cout<<"\n Enter Ur Option : ";
		cin>>i;
		if(i != 4){
			cout<<" Enter The No Of Elements :  ";
			cin>>n;		}
		switch(i){
			case 1 : cout<<"\n 1. Enter Ur Own Terms  >";
				for(int i=0; i<n; i++)
					cin>>Array[i];
				break;
			case 2 : cout<<"\n 2. Average Case(Random Array)  >";
				for(int i=0; i<n; i++)
					Array[i] = rand()%n + 1;
				break;
			case 3 : cout<<" 3. Worst Case(Reverse Array)  >";
				for(int i=0; i<n; i++)
					Array[i] = i+1;
				break;
			case 4 : cout<<"\n 4. Exit";
				exit(0);
			default:
				cout<<" Retry...";
				main();
				break;
		}
		lb = 0;
		ub = n-1;
		z = true;
		clock_t start;
		start = clock();
		quick(Array, lb, ub);
		clock_t end;
		end = clock();
		time = (end - start);
		
		if(n < 100){
			cout<<"\n Sorted Array : \n";
			for(int i=0; i<n; i++)
				cout<<Array[i]<<" ";
		}
		cout<<endl<<endl;
		cout<<" Starting Time : "<<start<<"\n";
		cout<<" Ending Time   : "<<end<<"\n";
		cout<<" Time : "<<time<<" Milliseconds\n";
	}while(x--);
	return 0;
}

	//algorithm quicksort(A, lo, hi) is
	//    if lo < hi then
	//        p := partition(A, lo, hi)
	//        quicksort(A, lo, p - 1 )
	//        quicksort(A, p + 1, hi)
	//
	//algorithm partition(A, lo, hi) is
	//    pivot := A[hi]
	//    i := lo - 1    
	//    for j := lo to hi - 1 do
	//        if A[j] < pivot then
	//            i := i + 1
	//            swap A[i] with A[j]
	//    if A[hi] < A[i + 1] then
	//        swap A[i + 1] with A[hi]
	//    return i + 1
	
//	O(nlgn)
//	O(nlgn)
//	O(n^2)
