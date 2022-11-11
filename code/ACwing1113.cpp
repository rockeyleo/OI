#include <bits/stdc++.h>
using namespace std;
const int M = 1001;
int n,m;
char g[M][M];
bool vis[M][M];
int dx[5] = {0,-1,0,1,0}, dy[5] = {0,0,1,0,-1};

int dfs(int x,int y){
	int cnt = 1;
	vis[x][y] = 1;
	for(int i=1;i<=4;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
		if(g[nx][ny]!='.')continue;
		if(vis[nx][ny])continue;
		cnt+=dfs(nx,ny);
	}
	return cnt;
}

int main(){
	while(cin>>m>>n,m or n){    //??????????
		for(int i=0;i<n;i++)cin>>g[i];
		int x,y;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j] == '@'){
					x=i, y=j;
				}
			}
		}
		cout<<dfs(x,y)<<endl;
	}
}
