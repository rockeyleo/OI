#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int cnt,fa[M],rk[M];
int n,m,ans;
struct edge{
    int f,t,v;
}node[M];

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

int Krus(){
    int cnt =0;
    for(int i=1;i<=m;i++){
        int u = find(node[i].f);
        int v = find(node[i].t);
        if(u==v){continue;}
        uion(u,v);
        // fa[u]=v;
        ans += node[i].v;
        cnt++;
        if(cnt>n-1)break;
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    int sum;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        node[++cnt].f = f;
        node[cnt].t = t;
        node[cnt].v = v;
        sum+=v;
    }
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    sort(node+1,node+m+1,[](edge a,edge b){return a.v<b.v;});
    if(Krus()==n-1){
        // cout<<ans<<endl;
        cout<<sum-ans<<endl;
    }
}