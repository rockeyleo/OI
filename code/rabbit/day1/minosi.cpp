#include <bits/stdc++.h>
using namespace std;
int g[30][30];  //g[x][y]
int len[30][30];
int xx[4] = {1,0,-1,0};
int yy[4] = {0,1,0,-1};
queue<pair<int,int>>q;
int n,m,a;
void bfs(){
	while(!q.empty()){
		pair<int,int>tmp = q.front(); q.pop();
		int nx = tmp.first, ny = tmp.second;
		if(nx==m and ny==n)return;
//		cout<<nx<<" "<<ny<<endl;
//		cout<<nx<<" "<<ny<<" "<<len[nx][ny]<<endl;
		for(int i=0;i<4;i++){
			int tx = nx+xx[i], ty = ny+yy[i];
//			cout<<tx<<" "<<ty<<endl;
			if(tx<1 or tx>m or ty<1 or ty>n)continue;
			if(g[tx][ty])if(i==1 or i==2)continue;
			if(!g[tx][ty])if(i==0 or i==3)continue;
			if(true){
//				cout<<tx<<" "<<ty<<" "<<endl;
				len[tx][ty] = len[nx][ny]+1;
				q.push({tx,ty});
			}
		}
	}
}

int main(){
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char tmp;
			cin>>tmp;
			if(tmp=='B'){   //B-1 W-0
				g[j][i] = 1;
			}else{
				g[j][i] = 0;
			}
		}
	}
	int ans = 0x3f3f3f3f;
	len[1][1] = 1;
	q.push({1,1});
	bfs();
//	cout<<len[m][n]<<endl;
 if(len[m][n]==a){
		printf("Perfect Ending");
	}else if(len[m][n]==0){
		printf("Bad Ending");
	}else{
		printf("Good Ending");
	}
}
