#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51][51];
int a[51][51];
int main(){
//	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	while(true){
		int x,y,v;
		cin>>y>>x>>v;
		if(x==0 and y==0 and v==0){
			break;
		}
		a[x][y] = v;
	}
	dp[1][1][1][1] = 0;
	for(int y=1;y<=n;y++){
		for(int x=1;x<=n;x++){
			for(int j=1;j<=n;j++){
				for(int i=1;i<=n;i++){
					dp[x][y][i][j]=max({
						dp[x-1][y][i-1][j],
						dp[x][y-1][i-1][j],
						dp[x-1][y][i][j-1],
						dp[x][y-1][i][j-1]
					})+a[x][y]+a[i][j];
					if(x==i and y==j)dp[x][y][i][j]-=a[x][y];
					//cout<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<dp[x][y][i][j]<<endl;
				}
			}
		}
	}
	cout<<dp[n][n][n][n]<<endl;
}
