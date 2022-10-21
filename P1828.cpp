#include <bits/stdc++.h>
using namespace std;
int cow[700];
const int M = 50010;
int val[M],to[M],head[M],nxt[M],vis[M],dis[M],cnt;
void add(int f,int t,int v){
    val[++cnt] = v;
    to[cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}
struct node{
    int name,dis;
    friend bool operator<(node a,node b){return a.dis>b.dis;}
}tmp;
priority_queue<node>pq;
void dij(int s){
    memset(vis,0,sizeof(vis));    //vis数组也要清空 ！！！！！
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    tmp.name = s; tmp.dis = 0; pq.push(tmp);
    while(!pq.empty()){
        int cur = pq.top().name;
        pq.pop();
        if(vis[cur])continue;
        vis[cur]=1;
        for(int i=head[cur];i;i=nxt[i]){
            int now = to[i];
            if(dis[now]>dis[cur]+val[i]){
                dis[now] = dis[cur]+val[i];
                tmp.name = now; tmp.dis = dis[now]; pq.push(tmp);
            }
        }
    }
}

int main(){
    int n,p,c;
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++){
        cin>>cow[i];
    }
    for(int i=1;i<=c;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
        add(t,f,v);
    }
    long long ans = 0x3f3f3f3f;
    for(int i=1;i<=p;i++){
        dij(i);
        long long tmp = 0;
        for(int j=1;j<=n;j++){
            // cout<<dis[cow[j]]<<" ";
            tmp+=dis[cow[j]];
        }
        // cout<<endl;
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;
}