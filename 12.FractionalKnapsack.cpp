#include <iostream>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;
struct Item{
    int value, weight;
};
bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n){
	sort(arr, arr + n, cmp);
    for (int i=0; i<n; i++)
        cout<<arr[i].value<<"\t"<<arr[i].weight<<" : "<<((double)arr[i].value/arr[i].weight)<<endl;
	int curWeight = 0;
    double finalvalue = 0.0;
    for (int i=0; i<n; i++){
        if (curWeight + arr[i].weight <= W){
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }else{
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main(){
	int W,n;
	double time;
    cin>>n>>W;
    Item arr[50];
    for(int i=0; i<n; i++){
    	cin>>arr[i].value;
    	cin>>arr[i].weight;
	}
	cout<<endl;
	clock_t start;
	start = clock();
	cout << " Maximum value we can obtain = "<< fractionalKnapsack(W, arr, n);
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
    return 0;
}

	//Algorithm: Greedy-Fractional-Knapsack (w[1..n], p[1..n], W) 
	//for i = 1 to n 
	//   do x[i] = 0 
	//weight = 0 
	//for i = 1 to n 
	//   if weight + w[i] = W then  
	//      x[i] = 1 
	//      weight = weight + w[i] 
	//   else 
	//      x[i] = (W - weight) / w[i] 
	//      weight = W 
	//      break 
	//return x
	
//	O(nlgn)
