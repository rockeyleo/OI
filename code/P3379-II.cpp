#include <bits/stdc++.h>
using namespace std;
int n,m,s;
const int M = 500100;
int head[M*2],nxt[M*2],to[M*2],dep[M*2],vis[M*2],cnt;
int f[M*2][26];

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

void dfs(int x=s,int from=0)//预处理lca
{
    vis[x]=1;
    for(int ct=head[x];ct;ct=nxt[ct])
    {
        if(to[ct]==from)continue;
        int y=to[ct];
        f[y][0]=x;
        for(int i=1;i<=15;++i)
            f[y][i]=f[f[y][i-1]][i-1];
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}

int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);   //保证a>=b
    for(int i=15;i>=0;i--){
        if(dep[f[a][i]]>=dep[b])a = f[a][i];
    }
    if(a==b)return a;
    for(int i=15;i>=0;i--){
        if(f[a][i]!=f[b][i]){
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;i++){
        int f,t;
        cin>>f>>t;
        add(f,t);
        add(t,f);
    }
    f[s][0]=s,dep[s]=1;
    dfs();
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}