#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;
void search(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    for (int i=0; i<=N-M; i++){
    	int j;
    	for (j=0; j<M; j++)
    		if (txt[i+j] != pat[j])
    			break;
    	if (j == M)
    		cout<<"\n Pattern found At Index    :  "<<i;
    }
}
int main(){
	clock_t start,end;
	char txt[100];
	char pat[100];
	cout<<" Enter String  : ";
	gets(txt);
	cout<<" Enter Pattern : ";
	gets(pat);
	start=clock();
	search(pat, txt);
	end=clock();
	cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
	return 0;
}

//	NAIVE-STRING-MATCHER(T, P)
//	1  n  length[T]
//	2  m  length[P]
//	3  for s  0 to n - m
//	4        do if P[1 . . m] = T[s + 1 . . s + m]
//	5              then print "Pattern occurs with shift" s

//O((n-m+1)m)
