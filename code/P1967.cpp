#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int nxt[M],head[M],to[M],cnt;
int fa[M],rk[M],val[M],tot;
struct edge{
    int f,t,v;
}node[M];

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int find(int a){
    if(fa[a]==a)return a;
    return(fa[a] = find(fa[a]));
}

void krus(){
    sort(node+1,node+1+m,[](edge a,edge b){return a.v>b.v;});
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    tot = n;
    for(int i=1;i<=m;i++){
        int a = find(node[i].f), b = find(node[i].t);
        if(a!=b){
            val[++tot] = node[i].v; //tot就是新建的点的编号，所以需要初始化成n
            fa[a] = fa[b] = fa[cnt] = tot;  //注意cnt这个新建点还没有初始化
            add(a,tot); add(tot,a);  //新出现的边是无权的
            add(b,tot); add(tot,b);
        }
    }
}

int lca(int a,int b){

}

int n,m,q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int f,t,v;
        cin>>f>>t>>v;
        node[i].f = f;
        node[i].t = t;
        node[i].v = v;  //边是双向边
    }
    krus();
    cin>>q;
    for(int i=1;i<=q;i++){
        int f,t;
        cin>>f>>t;
        if(find(f)!=find(t)){
            cout<<-1<<endl;
        }else{
            cout<<val[lca(f,t)];  //LCA是在重构树上跑的
        }
    }
}