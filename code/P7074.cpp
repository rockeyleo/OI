#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int dp[1001][1001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[j][i];
			dp[j][i]=-0x3f3f3f3f;
		}
	}
	dp[1][1]=a[1][1];
	for(int x=1;x<=m;x++){
		for(int y=1;y<=n;y++){
			dp[x+1][y] = max(dp[x+1][y],dp[x][y]+a[x+1][y]);
			dp[x][y+1] = max(dp[x][y+1],dp[x][y]+a[x][y+1]);
			dp[x][y-1] = max(dp[x][y-1],dp[x][y]+a[x][y-1]);
			//cout<<x<<" "<<y<<" "<<dp[x][y]<<endl;
		}
	}
	cout<<dp[m][n]<<endl;
}
