#include <bits/stdc++.h>
using namespace std;
int n;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int sp[1001][1001];
pair<int,int> pre[1001][1001];
pair<int,int>q[1000010];

void bfs(int x,int y){
    int j=0, k=0;
    sp[x][y] = -1;
    q[0]={x,y};
    while(j<=k){
        int xx = q[j].first, yy = q[j++].second;
        for(int i=0;i<4;i++){
            int nx = xx+dx[i], ny = yy+dy[i];
            if(sp[nx][ny]==-1 or sp[nx][ny]==1 or nx>n-1 or ny>n-1 or nx<0 or ny<0)continue;
            q[++k] = {nx,ny};
            pre[nx][ny] = {xx,yy};
            sp[nx][ny] = -1;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sp[i][j];
        }
    }
    bfs(1,1);
    int tx=0,ty=0;
    while(true){
        cout<<tx<<" "<<ty<<endl;
        if(tx==n-1 and ty==n-1)break;
        tx = pre[tx][ty].first;
        ty = pre[tx][ty].second;
    }
}