//这个题根本就不需要讨论可行解是不是正的……当然最长路也能跑
#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int n,m;
int head[M],to[M],val[M],nxt[M],dis[M],vis[M],num[M],cnt = 0;
queue<int> q;
void add(int f,int t,int v){
    val[++cnt] = v;
    to[cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}


int spfa(){
    while(!q.empty()){
        int now = q.front(); vis[now] = 0; q.pop();
        for(int i = head[now]; i; i = nxt[i]){
            if(dis[to[i]]<dis[now]+val[i]){ //改求最长路
                dis[to[i]] = dis[now] + val[i];
                if(vis[to[i]]==0){
                    vis[to[i]]=1;
                    num[to[i]]++;
                    if(num[to[i]]> n+1)return 1; //注意多了一个0源点
                    q.push(to[i]);
                }
            }
        }
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int op;
        int a,b,c;
        cin>>op;
        switch(op){     //1:a-b>=c | 2:a-b<=c -> b-a>=-c | 3:a-b=0 -> b+0<=a/a+0<=b
            case 1:{
                cin>>a>>b>>c;
                add(b,a,c);
                break;
            }
            case 2:{
                cin>>a>>b>>c;
                add(a,b,-c);
                break;
            }
            case 3:{
                cin>>a>>b;
                add(a,b,0);
                add(b,a,0);
            }
        }
        // cin>>a>>b>>c;
        // add(b,a,c);
    }
    for(int i=1;i<=n;i++){
        add(0,i,0); //加入源点0
    }
    for(int i=1;i<=n;i++){
        dis[i]=-0x3f3f3f3f;
    }
    dis[0] = 0;
    num[0] = 1;
    vis[0] = 1;
    q.push(0);
    if(spfa()){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}