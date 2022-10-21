#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int head[M],nxt[M],vis[M],to[M],dfn[M],low[M],cnt,tp;
int val[M];
int m,n;

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

void dfs(int s){
    if(vis[s])return;
    vis[s] = 1;
    dfn[s] = low[s] = ++tp;
    for(int i=head[s];i;i=nxt[i]){
        if(vis[to[i]])continue;
        dfs(to[i]);
        low[s] = min(low[s],low[to[i]]);
    }
    if(low[s] == dfn[s])
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int f,t;
        cin>>f>>t;
        add(f,t);
    }
    dfs(1);
}