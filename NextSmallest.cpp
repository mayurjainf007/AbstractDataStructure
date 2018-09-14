#include<stdio.h>

int FindMaxSum(int *arr, int n){
    for (int i=0; i<n-1; i++)
       for (int j=0; j<n-i-1; j++) 
           if (arr[j] > arr[j+1])
              arr[j] = arr[j+1];
    return 0;
}
 
int main(){
	int arr[] = {1,9,3,10,4,5,8,7,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	FindMaxSum(arr,n);
	for (int i=0; i<n; i++)
		printf("%d ",arr[i]);
	return 0;
}
