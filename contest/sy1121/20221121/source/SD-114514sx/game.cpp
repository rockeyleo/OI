#include<cstdio>
#include<algorithm>
using namespace std;
int n,nd[100001],id[100001],cntid,maxans,minans=0x3f3f3f3f;
bool flag[11];
struct Edge{
    int to,nxt;
}e[200001];
int check(int now=1,bool player=0,int fa=0){
    if(now!=1 && e[nd[now]].nxt==0){//leaf
        return id[now];
    }
    int best=0;
    if(player)best=0x3f3f3f3f;
    for(int i=nd[now];i;i=e[i].nxt){
        if(e[i].to==fa)continue;
        if(player)best=min(best,check(e[i].to,!player,now));
        else best=max(best,check(e[i].to,!player,now));
    }
    return best;
}
void dfs(int now){
    if(now>cntid){
        int tans=check(1,0);
        maxans=max(maxans,tans);
        minans=min(minans,tans);
        return;
    }
    for(int i=1;i<=cntid;++i){
        if(flag[i])continue;
        id[now]=i;
        flag[i]=1;
        dfs(now+1);
        flag[i]=0;
    }
}
void dfs0(int now,int fa){
    if(now!=1 && e[nd[now]].nxt==0){//leaf
        id[now]=++cntid;
        return;
    }
    for(int i=nd[now];i;i=e[i].nxt){
        if(e[i].to==fa)continue;
        dfs0(e[i].to,now);
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    int u,v;
    auto adde = [](int u,int v,int i){e[i]={v,nd[u]};nd[u]=i;};
    for(int i=1;i<n;++i){ 
        scanf("%d%d",&u,&v);
        adde(u,v,i); adde(v,u,i+n);
    }
    dfs0(1,0);
    dfs(1);
    printf("%d %d",maxans,minans);
    return 0;
}