#include <bits/stdc++.h>
using namespace std;
const int M = 110;
int n,xa,ya,xb,yb;
char g[M][M];
bool st[M][M];
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
bool dfs(int x,int y){
	if(g[x][y]=='#')return false; //建议把这个放在最前面以防起点就是障碍物（什么毒瘤数据）
	if(x==xb and y==yb)return true;
	st[x][y] = true; //需要保证每一个点只能被遍历一次
	for(int i=1;i<=4;i++){
		int nx = x+dx[i]; int ny = y+dy[i];
		if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
		if(st[nx][ny])continue;
		if(dfs(nx,ny))return true;
	}
	return false;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>g[i];  //注意读入顺序和本题的坐标表示法
		memset(st,0,sizeof(st));
		cin>>xa>>ya>>xb>>yb;
		if(dfs(xa,ya))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
