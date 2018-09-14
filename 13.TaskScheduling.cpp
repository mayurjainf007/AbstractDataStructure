#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#define MAX 100
using namespace std;
struct Job {
	char id[5];
	int deadline;
	int profit;
};
int minValue(int x, int y) {
	if(x < y) return x;
	return y;
}
bool cmp(struct Job a, struct Job b){
	return a.profit > b.profit;
}
void jobsd(struct Job jobs[], int n) {
	sort(jobs, jobs+n, cmp);
	printf("\n%10s %10s %10s\n", "Job", "Deadline", "Profit");
	for(int i=0; i<n; i++) {
		printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
	}
	int i, j, k, maxprofit;
	int timeslot[MAX];
	int filledTimeSlot = 0;
	int dmax = 0;
	for(i=0; i<n; i++)
		if(jobs[i].deadline > dmax)
			dmax = jobs[i].deadline;
	for(i=1; i<=dmax; i++)
		timeslot[i] = -1;
	cout<<"\n Maximum DeadLine : "<<dmax<<endl;
	for(i = 1; i <= n; i++) {
		k = minValue(dmax, jobs[i - 1].deadline);
		while(k >= 1) {
			if(timeslot[k] == -1) {
				timeslot[k] = i-1;
				filledTimeSlot++;
				break;
			}
			k--;
		}
		if(filledTimeSlot == dmax)
			break;
	}
	cout<<"\n Required Jobs: ";
	for(i=1; i<=dmax; i++) {
		printf("%s", jobs[timeslot[i]].id);
		if(i < dmax)
			cout<<" --> ";
	}
	maxprofit = 0;
	for(i = 1; i <= dmax; i++) {
		maxprofit += jobs[timeslot[i]].profit;
	}
	cout<<"\n Max Profit : "<<maxprofit<<endl;
}
int main() {
	int n;
	double time;
	Job jobs[50];
	cin>>n;
	for(int i=0; i<n; i++){
		cout<<" Input  : ";
		cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
	}
	clock_t start = clock();
	jobsd(jobs, n);
	clock_t end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
	return 0;
}

//	Algorithm: Job-Sequencing-With-Deadline (D, J, n, k) 
//	D(0) := J(0) := 0 
//	k := 1 
//	J(1) := 1   // means first job is selected 
//	for i = 2 … n do 
//	   r := k 
//	   while D(J(r)) > D(i) and D(J(r)) ? r do 
//	      r := r – 1 
//	   if D(J(r)) = D(i) and D(i) > r then 
//	      for l = k … r + 1 by -1 do 
//	         J(l + 1) := J(l) 
//	         J(r + 1) := i 
//	         k := k + 1 

//O(n^2)
