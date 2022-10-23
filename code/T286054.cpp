#include<bits/stdc++.h>
using namespace std;
const int M = 2000001;
int head[M],nxt[M],to[M],cnt;
int in[M],out[M];

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

void 

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t;
        in[t]++;out[f]++;
        scanf("%d",&f);scanf("%d",&t);
        add(f,t);add(t,f);
    }
    for(int i=1;i<=n;i++){
        if(in[n]==0){
            dfs(n);
        }
    }
}