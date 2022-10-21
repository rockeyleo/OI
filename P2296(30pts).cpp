#include <bits/stdc++.h>
using namespace std;
int n,m,st,t;
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

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int dfs(int s){
    if(s == st)return -1;
    if(tag[s]==1)return 1;
    if(tag[s]==-1)return 0;
    for(int i=head[s];i;i=nxt[i]){
        if(dfs(to[i])==1){
            tag[s]=2;
            return 0;
        }
    }
    tag[s]=-1;
    return 0;
}

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

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,to,v;
        cin>>f>>to;
        add(f,to);
    }
    cin>>st>>t;
    for(int i=1;i<=n;i++){
        // cout<<head[i]<<endl;
        if(head[i]==0 and i!=t){
            tag[i]=1;
        }
    }
    tag[t] = -1;
    int flag = 0;
    for(int i=head[st];i;i=nxt[i]){
        if(dfs(to[i])==-1){
            flag = 1;
            break;
        }
    }
    if(!flag){
        dij(st);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<tag[i]<<endl;
    // }
    if(dis[t]!=0x3f3f3f3f){
        cout<<dis[t];
    }else{
        cout<<-1;
    }
}