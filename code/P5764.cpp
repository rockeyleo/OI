#include <bits/stdc++.h>
using namespace std;
struct node{
    int dis,name;
    friend bool operator<(node a,node b){return a.dis>b.dis;}
}tmp;
const int M = 500100;
int val[M],to[M],nxt[M],head[M],vis[M],cnt;
int dis[M];
int par[6],vp[6];
int pdis[10][10];
priority_queue<node>pq;

int dvis[7];
int ans=0x3f3f3f3f;
void dfs(int len,int sum,int pos){  //len:序列长度；sum：答案和；pos：当前位置
    if(sum>ans)return;  //最优性剪枝，加到中途就大于答案的情况完全不需要搜完
    if(len == 5){ans=min(sum,ans);return;}
    for(int i=1;i<=5;i++){
        if(dvis[i])continue;
        dvis[i] = 1;
        dfs(len+1,sum+pdis[pos][i],i);//转移到下一位置
        dvis[i]=0;   //注意回溯!
    }
}

void dij(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));   //多测不清空，爆零两行泪
    dis[s] = 0;
    tmp.name = s; tmp.dis = 0; pq.push(tmp);
    while(!pq.empty()){
        int cur = pq.top().name;
        pq.pop();
        if(vis[cur])continue;
        vis[cur] = 1;
        for(int i=head[cur];i;i=nxt[i]){
            int now = to[i];
            if(dis[now]>dis[cur]+val[i]){
                dis[now] = dis[cur] + val[i];
                tmp.name = now; tmp.dis = dis[now]; pq.push(tmp);
            }
        }
    }
}

void add(int f,int t,int v){
    val[++cnt] = v;
    to[cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=5;i++){
        cin>>par[i];
    }
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
        add(t,f,v);
    }
    par[0]=1;   //把起点也加在映射里面方便访问
    // dij(1);
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<endl;
    // }
    // while(1){
    //     int tmp = 0x3f3f3f3f;
    //     dij(par[nxt]);
    //     for(int j=1;j<=5;j++){
            
    //         if(vp[j])continue;
    //         // vp[i]=1;
    //         if(dis[par[j]]<tmp){
    //             nxt = j;
    //             tmp = dis[par[j]];
    //         }
    //     }
    //     if(tmp==0x3f3f3f3f)break;
    //     ans += tmp;
    //     vp[nxt]=1;
    // }    for(int i=1;i<=5;i++){
    //     pdis[1][i] = dis[par[i]];
    // }
    for(int i=0;i<=5;i++){
        dij(par[i]);
        for(int j=0;j<=5;j++){
            if(j!=i)pdis[i][j]=dis[par[j]];
        }
    }
    dfs(0,0,0);
    cout<<ans<<endl;
}