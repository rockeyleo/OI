#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
char tar[7] = "KAIXUE";
int n,m,ans;
void bfs(int y,int x,int ch){
    if(ch == 5){
        // cout<<x<<" "<<y<<endl;
        ans++;
        return;
    }
    if(x>1 and a[y][x-1]==tar[ch+1])bfs(y,x-1,ch+1);
    if(y>1 and a[y-1][x]==tar[ch+1])bfs(y-1,x,ch+1);
    if(x<m and a[y][x+1]==tar[ch+1])bfs(y,x+1,ch+1);
    if(y<n and a[y+1][x]==tar[ch+1])bfs(y+1,x,ch+1);
    return;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='K')bfs(i,j,0);
        }
    }
    cout<<ans;
}