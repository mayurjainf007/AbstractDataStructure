#include <bits/stdc++.h>
using namespace std;
 
int firstNonRepeating(int *arr,int *c, int n){
    map<int, int> mp;
    for (int i = 0; i < n; i++) 
       mp[arr[i]]++;
    int j=0;
    for (int i=0; i<n; i++) 
       if (mp[arr[i]] != 1)
            c[j++] = arr[i];
//        else if(mp[arr[i]] == 1)
//            c[j++] = arr[i];
    return j;
}

int main(){
    int arr[] = { 9, 4, 9, 6, 7, 4,6,234,12,55,2,3,55,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int c[n];
    int x = firstNonRepeating(arr, c, n);
    for (int i=0; i<x; i++)
  		cout<<c[i]<<" ";
    return 0;
}
