#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int nxt[M], cnt, dis[M], head[M], to[M], val[M],
s, m, n, num[M], vis[M];
queue<int> q;
bool spfa();

int main(){
    auto add = [](int f,int t,int v){
        to[++cnt] = t;
        nxt[cnt] = head[f];
        head[f] = cnt;
        val[cnt] = v;
    };
    cin>>n>>m>>s;
    memset(dis,0x3f,sizeof(dis));
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    for(int i = 1; i <= m; i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
    }
    if(spfa()){
        for(int i = 1; i <= n; i++){
            cout<<dis[i]<<" ";
        }
    }else{
        cout<<"NO"<<endl;
    }
}

bool spfa(){
    q.push(s); vis[s] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop(); vis[now] = 0;
        for(int i = head[now]; i; i = nxt[i]){
            if(dis[to[i]] > dis[now]+val[i]){
                dis[to[i]] = dis[now]+val[i];
                if(!vis[to[i]]){
                    num[to[i]] = num[now]+1;
                    if(num[to[i]] > n) return false;
                    q.push(to[i]);
                    vis[to[i]] = 1;
                }
            }
        }
        // q.pop();
    }   
    return true;
}