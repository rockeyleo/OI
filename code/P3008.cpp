#include <bits/stdc++.h>
using namespace std;
// struct node{
//     int dis,name;
//     friend bool operator<(node a,node b){return a.dis>b.dis;}
// }tmp;
const int M = 500100;
int val[M],to[M],nxt[M],head[M],vis[M],cnt;
int dis[M];
// int num[M];
// queue<int>q;
deque<int>dq;
// priority_queue<node>pq;

void add(int f,int t,int v){
    val[++cnt] = v;
    to[cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

// void dij(int s){
//     memset(vis,0,sizeof(vis));
//     memset(dis,0x3f,sizeof(dis));   //多测不清空，爆零两行泪
//     dis[s] = 0;
//     tmp.name = s; tmp.dis = 0; pq.push(tmp);
//     while(!pq.empty()){
//         int cur = pq.top().name;
//         pq.pop();
//         if(vis[cur])continue;
//         vis[cur] = 1;
//         for(int i=head[cur];i;i=nxt[i]){
//             int now = to[i];
//             if(dis[now]>dis[cur]+val[i]){
//                 dis[now] = dis[cur] + val[i];
//                 tmp.name = now; tmp.dis = dis[now]; pq.push(tmp);
//             }
//         }
//     }
// }

inline void push(int x)
{
    if(!dq.empty())
    {
        if(dis[x]<dis[dq.front()])
            dq.push_front(x);
        else dq.push_back(x);
        if(dis[dq.front()]>dis[dq.back()])
            swap(dq.front(),dq.back());
    }
    else dq.push_back(x);
}

inline void pop(){
    dq.pop_front();
    if(!dq.empty() and dis[dq.front()]>dis[dq.back()])
        swap(dq.front(),dq.back());
}

inline void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    vis[s]=1;
    push(s);
    while(!dq.empty()){
        //gettop
        int u=dq.front();
        vis[u]=0;
        pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i],w=val[i];
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                    push(v),vis[v]=1;
            }
        }
    }
}

// void spfa(int s){
//     memset(dis,0x3f,sizeof(dis));
//     memset(num,0,sizeof(num));
//     memset(vis,0,sizeof(vis));
//     q.push(s); vis[s] = 1; dis[s] = 0;
//     while(!q.empty()){
//         int now = q.front(); q.pop(); vis[now] = 0;
//         for(int i = head[now]; i; i = nxt[i]){
//             if(dis[to[i]] > dis[now]+val[i]){
//                 dis[to[i]] = dis[now]+val[i];
//                 if(!vis[to[i]]){
//                     num[to[i]] = num[now]+1;
//                     // if(num[to[i]] > n) return;
//                     q.push(to[i]);
//                     vis[to[i]] = 1;
//                 }
//             }
//         }
//     }   
//     return;
// }

int main(){
    int t,r,p,s;
    cin>>t>>r>>p>>s;
    int minn = 0x3f3f3f3f;
    for(int i=1;i<=r;i++){
        int f,t,v;
        cin>>f>>t>>v;
        // minn = minn(v,minn);
        add(f,t,v);
        add(t,f,v);
    }

    for(int i=1;i<=p;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
    spfa(s);
    for(int i=1;i<=t;i++){
        if(dis[i]==0x3f3f3f3f){
            cout<<"NO PATH"<<endl;
        }else{cout<<dis[i]<<endl;}
    }
}