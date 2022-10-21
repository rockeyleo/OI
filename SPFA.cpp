#include <bits/stdc++.h>
using namespace std;
int m,n,s;
const int M = 500100;
int dis[M],vis[M],val[M],to[M],head[M],cnt,num[M],nxt[M];

bool spfa(){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop(); vis[now] = 0;
        for(int i = head[now]; i; i=nxt[i]){
            if(dis[to[i]] > dis[now]+val[i]){
                dis[to[i]] = dis[now] + val[i];
                if(vis[to[i]]==0){
                    vis[to[i]] = 1;
                    q.push(to[i]);
                    num[to[i]] ++;
                    if(num[to[i]]>=n){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    auto add = [](int f,int t,int v){
        to[++cnt] = t;
        nxt[cnt] = head[f];
        head[f] = cnt;
        val[cnt] = v;
    };
    cin>>n>>m>>s;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
    if(spfa()){
        cout<<"NO"<<endl;
    }else{
        for(int i = 1; i <= n; i++){
            cout<<dis[i]<<" ";
        }
    }

}