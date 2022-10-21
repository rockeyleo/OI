#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
bool isprime[M];
int prime[M];int cnt=0;
int main(){
    for(int i=1;i<=M;i++)isprime[i]=1;
    for(int i=2;i<=M;i++){
	    if(isprime[i]){prime[++cnt]=i;}
	    for(int j=1;j<=cnt and i*prime[j]<=M;j++){
		    isprime[i*prime[j]]=0;
		    if(i%prime[j]==0)break;
	    }
    }
    for(int i=1;i<=100;i++){
        cout<<prime[i]<<" ";
    }
}