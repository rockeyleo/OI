#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int m,n;
int dis[M],vis[M],val[M],to[M],nxt[M],head[M],cnt,ans,tot;


void prim(){
    while(true){
        int now = 0;
        for(int i=1 ;i<=m;i++){
            if(!vis[i] and dis[i]<dis[now]){
                now = i;
            }
        }
        if(!now)break;
        if(vis[now]==1)continue;
        vis[now]=1;
        tot++;
        ans += dis[now];
        for(int i=head[now]; i; i=nxt[i]){
            if(dis[to[i]]>val[i]){
                dis[to[i]]=val[i];
            }
        }
    }
}

int main(){
    int sum;
    auto add = [](int f,int t,int v){
        nxt[++cnt] = head[f];
        head[f] = cnt;
        to[cnt] = t;
        val[cnt] = v;
    };  //注意auto类型的lambda函数在C++11还不支持，比赛就别偷懒了
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t,v;
        cin>>f>>t>>v;
        add(f,t,v);
        add(t,f,v);
        sum+=v;
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    prim();
    
    if(tot ==n){
        cout<<sum-ans;
    }
    // }else{
    //     // cout<<ans<<endl
    //     cout<<"orz";
    // }
}