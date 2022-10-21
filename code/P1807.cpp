#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M = 500100;
int vis[M],val[M],to[M],head[M],dis[M],nxt[M],cnt;
queue<int>q;

void add(int f,int t,int v){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
    val[cnt] = v;
}

void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,-v);
    }
    spfa(1);
    if(dis[n]==0x3f3f3f3f){
        cout<<-1;
    }else{
        cout<<-dis[n]<<endl;
    }
}
