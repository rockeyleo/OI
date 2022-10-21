#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int f[501][501];
bool vis[501][501];

int main(){
    queue <pair<int,int>> q;
    int dx[8] = {1,2,-1,-2,-1,-2,1,2};
    int dy[8] = {2,1,2,1,-2,-1,-2,-1};
    memset(f,-1,sizeof(f));
    memset(vis,false,sizeof(vis));
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    f[x][y] = 0;
    vis[x][y] = true;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int xx = q.front().first, yy=q.front().second;q.pop();
        for(int i =0;i<=7;i++){
            int u = xx+dx[i],v = yy+dy[i];
            if(!vis[u][v] and u<=n and v<=m and u>0 and v>0){
                f[u][v] = f[xx][yy]+1;
                vis[u][v] = true;
                q.push(make_pair(u,v));
            }
        }
        
    }

    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",f[i][j]);
        }
        cout<<endl;
    }
}