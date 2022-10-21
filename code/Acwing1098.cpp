#include <bits/stdc++.h>
using namespace std;
int n,m;
int sq[101][101];
int vis[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
pair<int,int> q[100000];
int bfs(int x,int y){
    int ans = 1;
    if(vis[x][y]==1)return 0;
    vis[x][y]=1;
    q[0] = {x,y};
    int j=0,k=0;
    while(j<=k){
        int xx = q[j].first, yy = q[j++].second;
        for(int i=0;i<=3;i++){
            int nx = xx+dx[i], ny = yy+dy[i];
            if(vis[nx][ny] or nx>n or ny>m or nx<1 or ny<1)continue;
            if(((sq[nx][ny]>>i)&1)==1)continue;
            q[++k] = {nx,ny};vis[nx][ny]=1;ans++;
        }
    }
    // ans+=(sq[x+1][y]&1)==0?bfs(x+1,y):0;
    // ans+=((sq[x][y+1]>>1)&1)==0?bfs(x,y+1):0;
    // ans+=((sq[x-1][y]>>2)&1)==0?bfs(x-1,y):0;
    // ans+=((sq[x][y-1]>>3)&1)==0?bfs(x,y-1):0;
    // //cout<<ans<<endl;
    return ans;
}

int main(){
    int cnt = 0;
    int room = 0;
    memset(vis,0,sizeof(sq));
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>sq[j][i];  //i - m - y    j - n - x
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int tmp = bfs(j,i);
            if(tmp!=0)room++;
            cnt = max(tmp,cnt);
        }
    }
    cout<<room<<"\n"<<cnt<<endl;
}