#include<bits/stdc++.h>
#define MAXN 3000
#define MOD 998244353
#define LL long long
using namespace std;
int n,k;
LL s1[MAXN+5][MAXN+5],ans;
int main()
{
	scanf("%d%d",&n,&k);
	s1[1][1]=1ll;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s1[i][j]=s1[i-1][j]*(LL)(i-1)+s1[i-1][j-1];
			s1[i][j]%=MOD;
		}
	}
	for (int i=1;i<=k;i++)
	{
		ans+=s1[n][i];
		ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}