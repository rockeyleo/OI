#include <bits/stdc++.h>
using namespace std;
const int M = 50;
int n,m,x,y;
int dx[8] = {-1,1,2,2,1,-1,-2,-2}, dy[8] = {2,2,1,-1,-2,-2,-1,1};
int ans;
bool vis[M][M];
void dfs(int x,int y,int cnt){
//	cout<<x<<" "<<y<<endl;
	if(vis[x][y])return;
	if(cnt == n*m){
		ans++; return;
	}
	vis[x][y] = true;
	for(int i=0;i<8;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(vis[nx][ny])continue;
		if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
		dfs(nx,ny,cnt+1);
	}
	vis[x][y] = false;
}

int main(){
	int t;cin>>t;
	while(t--){
		ans = 0;
//		memset(vis,0,sizeof(vis))s;
		cin>>n>>m>>x>>y;
		dfs(x,y,1);
		cout<<ans<<endl;
	}
	return 0;
}
