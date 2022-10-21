#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
// int dis[M],nxt[M],head[M],vis[M],to[M],cnt,val[M],cnt;
int fa[M],rk[M],cnt;
struct edge{
    int f,t,v;
}node[M];

void add(int f,int t,int v){
    node[++cnt].f = f;
    node[cnt].t = t;
    node[cnt].v = v;
}

// void add(int f,int t,int v){
//     to[++cnt] = t;
//     nxt[cnt] = head[f];
//     head[f] = cnt;
//     val[cnt] = v;
// }

int find(int a){
    if(fa[a]==a)return a;
    return(fa[a]=find(fa[a]));
}

void uion(int u,int v){
    if(rk[u]>rk[v]){
        fa[v] = u;
    }else if(rk[u]==rk[v]){
        fa[v] = u;
        rk[u]++;
    }else{
        fa[u] = v;
    }
}

void krus(){
    int cnt =0;
    for(int i=1;i<=m;i++){
        int u = find(node[i].f);
        int v = find(node[i].t);
        if(u==v){continue;}
        uion(u,v);  //事实证明按秩合并在稠密图没啥用
        // fa[u]=v;
        if(cnt>n-1)break;
    }
}

int n,m,q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
        add(t,f,v);
    }
    krus();
    cin>>q;
    for(int i=1;i<=q;i++){
        int f,t;
        cin>>f>>t;
        if(fa[f]!=fa[t]){
            cout<<-1<<endl;
        }else{
            
        }
    }
}