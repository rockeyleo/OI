#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51][51];
int a[51][51];  //a[x][y] ×óÏÂÎªÕı n-x m-y
int prex[51],prey[51];
int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	int m,n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j][i]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[k][0][j][i] = a[k][a-1]
			}
		}
	}
}

//dp[x][y][j][k] = max({dp[x-1][y]})
