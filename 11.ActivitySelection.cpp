#include<iostream>
#include<stdio.h>
#include<time.h>
#include<algorithm>
using namespace std;
void printMaxActivities(int s[], int f[], int n){
	int i, j;
	cout<<" sorted according to final time\n";
	sort(f, f+n);
	for(int i=0;i<n;i++)
		cout<<s[i]<<" : "<<f[i]<<endl;
	cout<<"\n Following activities are selected >  ";
    i = 0;
    cout<<"\n "<<s[i]<<" : "<<f[i];
    for (j = 1; j < n; j++){
		if (s[j] >= f[i]){
			cout<<"\n "<<s[j]<<" : "<<f[j];
			i = j;
		}
	}
}
int main(){
	int n, s[50], f[50];
	double time;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>s[i]>>f[i];
    clock_t start;
	start = clock();
	printMaxActivities(s, f, n);
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
    return 0;
}

//	Greedy-Iterative-Activity-Selector(A, s, f):
//	Sort A by finish times stored in f
//	S = {A[1]} 
//	k = 1
//	n = A.length
//	for i = 2 to n:
//	if s[i] = f[k]: 
//	S = S U {A[i]}
//	k = i
//	return S

//O(n)	sorted list
//O(nlgn)  unsorted list
