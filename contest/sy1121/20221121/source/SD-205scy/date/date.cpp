#include<cstdio>
#include<queue>
// #define AK printf("AK:%d\n",++ak);
// #define AK1 printf("AK1:%d\n",++ak1);
// #define AK2 printf("AK2:%d\n",++ak2);
// int ak,ak1,ak2;
using namespace std;
int n,m,nd[100001],x,y,dp[100001],f[100001][20];
int sz[100001];
struct Edge{
    int to,nxt;
}e[200001];
void dfs0(int now,int fa){
    sz[now]=1;
    for(int i=nd[now];i;i=e[i].nxt){
        if(e[i].to==fa)continue;
        dfs0(e[i].to,now);
        sz[now]+=sz[e[i].to];
    }
}
void bfs0(){
    queue<int> q;
    dp[1]=1; q.push(1);
    int now;
    while(!q.empty()){
        now=q.front(); q.pop();
        for(int i=nd[now];i;i=e[i].nxt){
            if(dp[e[i].to])continue;
            dp[e[i].to]=dp[now]+1;
            f[e[i].to][0]=now;
            for(int j=1,t=__lg(dp[e[i].to]);j<=t;++j){
                f[e[i].to][j]=f[f[e[i].to][j-1]][j-1];
            }
            q.push(e[i].to);
        }
    }
}
int getLCA(int x,int y){
    if(dp[y]>dp[x])swap(x,y);
    while(dp[x]>dp[y])x=f[x][__lg(dp[x]-dp[y])];
    if(x==y)return x;
    for(int i=__lg(dp[x]);i>=0;--i){
        if(f[x][i]==f[y][i])continue;
        x=f[x][i]; y=f[y][i];
    }
    return f[x][0];
}
int getJump(int x,int h){
    for(int i=0;h;++i,h>>=1){
        // printf("ERR:%d\n",h);
        if(h&1)x=f[x][i];
    }
    return x;
}
int main(){
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    //input
    scanf("%d",&n);
    int u,v;
    auto adde = [](int u,int v,int i){e[i]={v,nd[u]};nd[u]=i;};
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        adde(u,v,i); adde(v,u,i+n);
    }
    //init
    dfs0(1,0);
    bfs0();
    //solve
    scanf("%d",&m);
    int lca,mid,disx,disy;
    while(m--){
        scanf("%d%d",&x,&y);
        if(x==y){
            printf("%d\n",sz[1]);
            continue;
        }
        lca=getLCA(x,y);
        disx=dp[x]-dp[lca];
        disy=dp[y]-dp[lca];
        if((disx+disy)&1){
            printf("0\n"); continue;
        }
        mid=disx+disy>>1;
        if(disx==0){
            disy=getJump(y,mid-1);
            mid=getJump(y,mid);
            printf("%d\n",sz[mid]-sz[disy]);
            continue;
        }
        else if(disy==0){
            disx=getJump(x,mid-1);
            mid=getJump(x,mid);
            printf("%d\n",sz[mid]-sz[disx]);
            continue;
        }
        if(disx>disy)mid=getJump(x,mid);
        else mid=getJump(y,mid);
        // printf("%d, %d\n",disx,disy);
        if(dp[x]==dp[y]){
            disx=getJump(x,disx-1);
            disy=getJump(y,disy-1);
            printf("%d\n",sz[1]-sz[disx]-sz[disy]);
        }
        else if(dp[x]>dp[y]){
            disx=getJump(x,dp[x]-dp[mid]-1);
            // disy=getJump(x,dp[x]-dp[mid]+2);
            printf("%d\n",sz[mid]-sz[disx]);
        }
        else{
            // disx=getJump(y,dp[y]-dp[mid]+2);
            disy=getJump(y,dp[y]-dp[mid]-1);
            printf("%d\n",sz[mid]-sz[disy]);
        }
        // printf("%d, %d\n",disx,disy);
        // printf("%d,%d,%d,%d\n",sz[1],sz[2],sz[3],sz[4]);
        // printf("%d\n",sz[1]-sz[disx]-sz[disy]);
    }
    return 0;
}