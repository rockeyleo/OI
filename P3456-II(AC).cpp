#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int>q[1000500];
int xx[] = {1,-1,0,0,1,-1,1,-1};
int yy[] = {0,0,1,-1,1,-1,-1,1};
int hei[1005][1005];
int vis[1005][1005];
void bfs(int x,int y,bool &high,bool &low){
    vis[x][y]=1;
    int cnt = 1;
    int j=0,k=0;
    q[0] = {x,y};
    while(j<=k){
        int nx = q[j].first, ny = q[j++].second;
        for(int i=0;i<8;i++){
            int dx = xx[i]+nx, dy = yy[i]+ny;
            if(dx>n or dy>n or dx<1 or dy<1)continue;
            if(hei[dx][dy]!=hei[nx][ny]){
                if(hei[dx][dy]>hei[nx][ny]){
                    high = true;
                }else{
                    low = true;
                }
            }else if(!vis[dx][dy]){
                q[++k]={dx,dy};
                vis[dx][dy]=1;
            }
        }
    }
}

int main(){
    cin>>n;
    int f = 0,g = 0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>hei[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){  
        for(int j=1;j<=n;j++){
            if(vis[i][j])continue;
            bool high = false,low = false;
            bfs(i,j,high,low);
            if(!high)f++;
            if(!low)g++;
        }
    }
    cout<<f<<" "<<g<<endl;
}