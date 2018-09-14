#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>

using namespace std;

void Insertion_sort(float A[], int n){
	int key,i;
	for(int j=1; j<n; j++){
		key = A[j];
		i=j-1;
		while(i>=0 && A[i]>key){
			int temp = A[i+1];
			A[i+1] = A[i];
			A[i] = temp;
			i--;
		}
		A[i+1] = key;
	}
}


int main(){
	int n,i,x=4;
	float Array[500000];
	double start,end,time,timea;

	do{
		cout<<"\n Main Menu..\n 1. Enter Ur Own Terms\n 2. Best Case(Sorted Array)\n 3. Average Case(Random Array)\n 4. Worst Case(Reverse Array)\n 5. Exit";
		cout<<"\n Enter Ur Option : ";
		cin>>i;	
		if(i != 5){
			cout<<"\n Enter The No Of Elements :  ";\
			cin>>n;
		}
		switch(i){
			case 1 : cout<<"\n 1. Enter Ur Own Terms";
				for(int i=0; i<n; i++)
					cin>>Array[i];
				break;
			case 2 : cout<<"\n 2. Best Case(Sorted Array)";
				for(int i=0; i<n; i++)
					Array[i] = i+1;
				break;
			case 3 : cout<<"\n 3. Average Case(Random Array)";
				for(int i=0; i<n; i++)
					Array[i] = rand()%n + 1;
				break;
			case 4 : cout<<"\n 4. Worst Case(Reverse Array)";
				for(int i=0; i<n; i++)
					Array[i] = n-i+1;
				break;
			case 5 : cout<<"\n 5. Exit";
				exit(0);
			default:
				cout<<" Retry...";
				main();
				break;
		}
		
		clock_t starta;
		starta = clock();
		Insertion_sort(Array,n);
		clock_t enda;
		enda = clock();
		
		if(i == 1){
			cout<<"\n\n Sorted Array : \n";
			for(int i=0; i<n; i++)
				cout<<Array[i]<<" ";
			cout<<endl<<endl;
		}
	
		cout<<"\n Starting Time : "<<starta;
		cout<<"\n Ending Time   : "<<enda;
		timea = (enda - starta);
		
		cout<<"\n Time : "<<timea<<" Milliseconds\n";
	
	}while(x--);
	return 0;
}

//
// function insertionSortR(array A, int n)
//     if n>0
//        insertionSortR(A,n-1)
//        x ? A[n]
//        j ? n-1
//        while j >= 0 and A[j] > x
//            A[j+1] ? A[j]
//            j ? j-1
//        end while
//        A[j+1] ? x
//     end if
// end function

//	O(n)
//	O(n^2)
//	O(n^2)
