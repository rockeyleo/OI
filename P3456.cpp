#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int>q[1000500];
int xx[] = {1,-1,0,0,1,-1,1,-1};
int yy[] = {0,0,1,-1,1,-1,-1,1};
int hei[1005][1005];
int vis[1005][1005];
int bfs(int x,int y,int opt){
    vis[x][y]=1;
    int cnt = 1;
    int j=0,k=0;
    q[0] = {x,y};
    while(j<=k){
        int nx = q[j].first, ny = q[j++].second;
        if(opt==1){
            for(int i=0;i<=7;i++){
                int dx = xx[i]+nx,dy = yy[i]+ny;
                if(dx>n or dy>n or dx<1 or dy<1)continue;
                if(hei[dx][dy]>hei[nx][ny])cnt=0;
            }
        }else{
            for(int i=0;i<=7;i++){
                int dx = xx[i]+nx,dy = yy[i]+ny;
                if(dx>n or dy>n or dx<1 or dy<1)continue;
                if(hei[dx][dy]<hei[nx][ny])cnt=0;
            }
        }
        if(cnt==0)return 0;
        for(int i=0;i<=7;i++){
            int dx = xx[i]+nx,dy = yy[i]+ny;
            if(vis[dx][dy] or dx>n or dy>n or dx<1 or dy<1)continue;
            if(hei[dx][dy]==hei[nx][ny]){
                q[++k]={dx,dy};
                vis[dx][dy]=1;
            }
        }
    }
    return cnt;
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
            int tmp =bfs(i,j,1);     //1山峰，2山谷
            if(tmp!=0){f++;}
        }
    }
    memset(vis,0,sizeof(vis));      //多测记得清空
    cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j])continue;
            int tmp =bfs(i,j,2);
            if(tmp!=0){g++;}
        }
    }
    cout<<f<<" "<<g<<endl;
}