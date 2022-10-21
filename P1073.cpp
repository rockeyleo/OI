#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
queue<int>q;
int val[M*3],head[M*3],to[M*3],nxt[M*3],cnt;
int vv[M],vis[M*3];
int n,m;
int dis[M*3];

void add(int f,int t,int v){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
    val[cnt] = v;
}

void spfa(int s){
    dis[s]=0;
    q.push(s); vis[s] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop(); vis[now] = 0;
        for(int i = head[now]; i; i = nxt[i]){
            if(dis[to[i]] > dis[now]+val[i]){
                dis[to[i]] = dis[now]+val[i];
                if(!vis[to[i]]){
                    q.push(to[i]);
                    vis[to[i]] = 1;
                }
            }
        }
    }   
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        cin>>vv[i];
    }
    for(int i=1;i<=m;i++){
        int f,t,op;
        cin>>f>>t>>op;
        if(op == 1){
            add(f,t,0);
            add(f+n,t+n,0);
            add(f+n*2,t+n*2,0); //层内自由转移，设边权为0
        }else{
            add(f,t,0);
            add(f+n,t+n,0);
            add(f+n*2,t+n*2,0);
            add(t,f,0);
            add(t+n,f+n,0);
            add(t+n*2,f+n*2,0);
        }
    }
    for(int i=1;i<=n;i++){
        add(i,i+n,vv[i]);  //第二层图是买入后转移，本应是负的，这里写成正的方便spfa跑最短路
        add(i+n,i+n*2,-vv[i]);  //同理
    }
    spfa(1);
    int ans = -dis[n*3];
    cout<<max(ans,0);
}