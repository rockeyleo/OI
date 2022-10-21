#include <bits/stdc++.h>
using namespace std;
struct node{
    int name,dis;
    friend bool operator<(node a,node b){
        return(a.dis>b.dis);
    }
}tmp;

const int M = 500100;
int dis[M],to[M],head[M],val[M],nxt[M],vis[M],cnt;


void add(int f,int t,int v){
    to[++cnt]=t;
    nxt[cnt]=head[f];
    head[f]=cnt;
    val[cnt]=v;
}
priority_queue<node>q;

void dij(){
    while(!q.empty()){
        int now = q.top().name;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int i=head[now];i;i=nxt[i]){
            if(dis[to[i]]>dis[now]+val[i]){
                dis[to[i]]=dis[now]+val[i];
                tmp.name=to[i]; tmp.dis=dis[to[i]]; q.push(tmp);
            }
        }
    }
}

int main(){
    int n,m,s;
    cin>>m>>n>>s;
    for(int i=1;i<=n;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    tmp.name=s; tmp.dis=0; q.push(tmp);
    dij();
    for(int i=1;i<=m;i++){
        cout<<dis[i]<<" ";
    }
}