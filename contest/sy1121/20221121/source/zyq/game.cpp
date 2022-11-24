#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
struct bian{
    int to;
    int nxt;
};
int n,g[maxn],dep[maxn],d[maxn],v[maxn];
int head[maxn],cnt;
bian e[maxn];
void add(int u,int v){
    cnt++;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void input(){
    cin>>n;
    int u,v;
    for(int i = 1;i < n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
    }
}
void dfs(bool dep,int x){
    if(!head[x]){
        d[x] = v[x] = g[x] = 1;
        return;
    }
    for(int i = head[x];i;i = e[i].nxt){
        dfs(!dep,e[i].to);
        g[x] += g[e[i].to];
    }
    v[x] = d[x] = 1;
    if(dep){
        int sum = 0;
        for(int i = head[x];i;i = e[i].nxt){
            sum += v[e[i].to] - 1;
            d[x] = max(d[x],g[x]-g[e[i].to]+d[e[i].to]);
        }
        v[x] = max(v[x],sum+1);
    }else{
        int sum = 0;
        for(int i = head[x];i;i = e[i].nxt){
            sum += d[e[i].to] - 1;
            v[x] = max(v[x],g[x]-g[e[i].to]+v[e[i].to]);
        }
        d[x] = max(d[x],sum+1);
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    input();
    dfs(true,1);
    cout<<d[1]<<" "<<g[1] - v[1] + 1;
    return 0;
}
