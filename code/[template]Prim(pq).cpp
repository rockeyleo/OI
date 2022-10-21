#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int dis[M],vis[M],val[M],to[M],nxt[M],head[M],cnt,ans,tot;
struct node{
    int name,dis;
    bool friend operator<(node a,node b){
        return a.dis>b.dis;
    }
}tmp;

priority_queue<node>pq;

void prim(){
    tmp.name = 1; tmp.dis = 0;
    pq.push(tmp);
    while(!pq.empty()){
        int now = pq.top().name; pq.pop();
        if(vis[now]==1)continue;
        vis[now]=1;
        tot++;
        ans += dis[now];
        for(int i=head[now]; i; i=nxt[i]){
            if(dis[to[i]]>val[i]){
                dis[to[i]]=val[i];
                tmp.name = to[i]; tmp.dis = dis[to[i]];
                pq.push(tmp);
            }
        }
    }
}

int main(){
    int m,n;
    auto add = [](int f,int t,int v){
        nxt[++cnt] = head[f];
        head[f] = cnt;
        to[cnt] = t;
        val[cnt] = v;
    };
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
        add(t,f,v);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    prim();
    if(tot ==n){  //这个地方和Kruskal不一样！！！！这里的total用于记录所有被标记的节点，而Kruskal则是记录边数
        cout<<ans;
    }else{
        // cout<<ans<<endl
        cout<<"orz";
    }
}