#include<iostream>
#include<cstdio>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int s,n,m;
//edge
int head[100005],total;
struct edge
{
    int next,w,to;
    void add(int u,int v,int wi)
    {
        next=head[u];
        head[u]=total;
        to=v;
        w=wi;
    }
} e[100005<<1];
//spfa
deque<int> dq;
int dis[100005];
bool vis[100005];
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
inline void pop()
{
    dq.pop_front();
    if(!dq.empty()&&dis[dq.front()]>dis[dq.back()])
        swap(dq.front(),dq.back());
}
inline void spfa()
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    vis[s]=1;
    push(s);
    while(!dq.empty())
    {
        //gettop
        int u=dq.front();
        vis[u]=0;
        pop();
        for(int i=head[u]; i; i=e[i].next)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                    push(v),vis[v]=1;
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[++total].add(u,v,w);
    }
    spfa();
    for(int i=1; i<=n; i++)
        if(i!=n)
            printf("%d ",dis[i]);
        else printf("%d",dis[i]);
    return 0;
}