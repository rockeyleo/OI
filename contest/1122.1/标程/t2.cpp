#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n,dp[N][N];
struct Ask{
	int a,b;
}A[N];
int cmp(Ask x,Ask y){
	return x.a>y.a;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&A[i].a);
	for (int i=1;i<=n;i++)scanf("%d",&A[i].b);
	sort(A+1,A+n+1,cmp);
	memset(dp,192,sizeof dp);
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
		if (i&1)dp[i][0]=dp[i-1][0]+A[i].a;
		else dp[i][0]=dp[i-1][0];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			dp[i][j]=max(dp[i-1][j-1]-A[i].b,dp[i-1][j]+((i-j)&1?1:0)*A[i].a);
	for (int i=0;i<=n;i++)printf("%d\n",dp[n][i]);
	return 0;
}
