#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
int head[M],nxt[M],to[M],val[M],cnt;
int u[M],c[M];
int n,p;

void add(int f,int t,int v){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int main(){
    ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>u[i];
    }
    for(int i=1;i<=p;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
}