#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
const int M = 200001;
int head[M],nxt[M],to[M];
int cnt;
int tag[10001],vis[10001],dis[10001];
struct node{
    int name,dis;
    friend bool operator<(node a,node b){
        return(a.dis>b.dis);
    }
}tmp;
priority_queue<node>q;

void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    tmp.dis = 0; tmp.name = s; q.push(tmp);
    while(!q.empty()){
        int now = q.top().name;
        q.pop();
        if(vis[now] or tag[now]>=1)continue;
        vis[now]=1;
        for(int i=head[now];i;i=nxt[i]){
            if(tag[to[i]]>=1)continue;
            if(dis[to[i]]>dis[now]+1){
                dis[to[i]]=dis[now]+1;
                tmp.name=to[i]; tmp.dis=dis[to[i]]; q.push(tmp);
            }
        }
    }
}

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,to,v;
        cin>>f>>to;
        add(f,to);
    }
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        if(head[i]==0 and i!=t){
            tag[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=nxt[x]){
            if(tag[to[x]]){
                head[i]=0;
                break;
            }
        }
    }
    dij(s);
    if(dis[t]==0x3f3f3f3f){
        cout<<-1<<endl;
    }else{
        cout<<dis[t]<<endl;
    }
}