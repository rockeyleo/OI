#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int nxt[M],head[M],to[M],cnt;
int fa[M],val[M],vis[M],tot;
vector<int> root; int f[M][25], dep[M];
int n,m,q;
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
            fa[a] = fa[b] = fa[tot] = tot;  //注意cnt这个新建点还没有初始化
            add(a,tot); add(tot,a);  //新出现的边是无权的
            add(b,tot); add(tot,b);
        }
    }
}

void dfs(int now, int fath=0) {
    vis[now]=1;
	f[now][0] = fath; dep[now] = dep[fath] + 1;
	for(int i = 1;(i<<1)<=dep[now]; ++i)
		f[now][i] = f[f[now][i-1]][i-1];
	for(int i = head[now]; i; i = nxt[i])
		if(to[i] != fath) dfs(to[i], now);
}

// void dfs(int x,int from=0)//预处理lca
// {
//     vis[x]=1;
//     for(int ct=head[x];ct;ct=nxt[ct])
//     {
//         if(to[ct]==from)continue;
//         int y=to[ct];
//         f[y][0]=x;
//         for(int i=1;i<=15;++i)
//             f[y][i]=f[f[y][i-1]][i-1];
//         dep[y]=dep[x]+1;
//         dfs(y,x);
//     }
// }

int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);   //保证a>=b
    for(int i=15;i>=0;i--){
        if(dep[f[a][i]]>=dep[b])a = f[a][i];
    }
    if(a==b)return a;
    for(int i=15;i>=0;i--){
        if(f[a][i]!=f[b][i] and f[a][i]!=0 and f[b][i]!=0){
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

int main(){
    // freopen("P1967_3.in","r",stdin);
    // freopen("P1967_3.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        node[i].f = f;
        node[i].t = t;
        node[i].v = v;  //边是双向边
    }
    krus();
    for(int i=tot;i>=1;i--){
        if(!vis[i]){
            dfs(i);
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int f,t;
        cin>>f>>t;
        if(find(f)!=find(t)){
            cout<<-1<<endl;
        }else{
            cout<<val[lca(f,t)]<<endl;  //LCA是在重构树上跑的
        }
    }
}