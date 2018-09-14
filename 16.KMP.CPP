#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps){
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M){
    	if (pat[i] == pat[len]){
    		len++;
    		lps[i] = len;
    		i++;
    	}else{
			if (len != 0)
				len = lps[len-1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[100];
    computeLPSArray(pat, M, lps);
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N){
    	if(pat[j] == txt[i]){
    		j++;	i++;	}
		if(j == M){
			cout<<"\n Found Pattern At Index "<<i-j;
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i]){
			if (j != 0)
				j = lps[j-1];
			else
				i++;
		}
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
    KMPSearch(pat, txt);
    end=clock();
   	cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
	return 0;
}

//	KMP-MATCHER(T, P)
//	1 n  length[T]
//	2 m  length[P]
//	3   COMPUTE-PREFIX-FUNCTION(P)
//	4 q  0
//	5 for i  1 to n
//	6      do while q > 0 and P[q + 1]  T[i]
//	7             do q  [q]
//	8        if P[q + 1] = T[i]
//	9           then q  q + 1
//	10        if q = m
//	11           then print "Pattern occurs with shift" i - m
//	12                q  [q]
//	COMPUTE-PREFIX-FUNCTION(P)
//	1 m  length[P]
//	2  [1]  0
//	3 k  0
//	4 for q  2 to m
//	5      do while k > 0 and P[k + 1  P[q]
//	6            do k  [k]
//	7        if P[k + 1] = P[q]
//	8           then k  k + 1
//	9        [q]  k
//	10 return 

//O(m+n)
