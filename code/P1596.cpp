#include <bits/stdc++.h>
using namespace std;
int sq[1001][1001];
int ans =0;
int n,m;
bool bfs(int x,int y){  //x - i - n    y - j - m
    if(sq[x][y]!=1 or x>n or y>m or x<0 or y<0)return false;
    sq[x][y]=-1;
    bfs(x+1,y);
    bfs(x,y+1);
    bfs(x-1,y);
    bfs(x,y-1);
    bfs(x+1,y+1);
    bfs(x+1,y-1);
    bfs(x-1,y-1);
    bfs(x-1,y+1);
    return true;
}
int main(){
    cin>>n>>m;
    memset(sq,0,sizeof(sq));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='W')sq[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(bfs(i,j))ans++;
        }
    }
    cout<<ans;
}