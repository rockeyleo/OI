#include <bits/stdc++.h>
using namespace std;
const int M = 100001;
int val[M],nxt[M],to[M],head[M];
int cnt;
int m,n;

void add(int f,int t,int v){
    val[++cnt] = v;
    to[cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int main(){
    for(int i=1;i<=n;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
}