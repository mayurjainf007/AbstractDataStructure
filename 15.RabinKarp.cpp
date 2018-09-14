#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
using namespace std;
#define d 10
void search(char pat[], char txt[], int q){
	int M = strlen(pat);
    int N = strlen(txt);
    int i, j ;
    float k;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    for(i=0; i<M-1; i++)
    	h = (h*d)%q;
    for(i=0; i<M; i++){
		p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    for(i=0; i<=N-M; i++){
        if(p == t){
            for(j=0; j<M; j++){
                if(txt[i+j] != pat[j])
                	break;
            }
            if(j == M)
                cout<<"\n Pattern Found At Index "<<i;
        }
        if(i < N-M){
        	t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if(t < 0)
            t = (t + q);
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
    int q = 101; // A prime number
    start=clock();
    search(pat, txt, q);
    end=clock();
    cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
    return 0;
}

	//RABIN-KARP-MATCHER(T, P, d, q)
	//1 n  length[T]
	//2 m length[P]
	//3 h  dm-1 mod q
	//4 p  0
	//5 t0  0
	//6 for i  1 to m
	//7       do p  (dp + P[i]) mod q
	//8          t0  (dt0 + T[i]) mod q
	//9 for s  0 to n - m
	//10      do if p = ts
	//11            then if P[1 . . m] = T[s + 1 . . s + m]
	//12                    then "Pattern occurs with shift" s
	//13         if s < n - m
	//14           then ts+1  (d(ts - T[s + 1]h) + T[s + m + 1]) mod q
	
//	O(m+n)
