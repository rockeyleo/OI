#include <bits/stdc++.h>
using namespace std;
const int M = 500000;
int head[M],to[M],nxt[M],cnt;
int in[M],out[M];
queue<int>q;

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
    in[t]++; out[f]++;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){

    }
}