#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+5,INF=0x3f3f3f3f3f3f3f3f;

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	return x;
}

int a[N],n;

namespace solve1{
	int ans=0;
	int dp[N];

	void solve()
	{
		for(int i = 1;i<=n;i++)//改变第i位
		{
			int t=a[i];
			for(int j = 1;j<=n;j++)
			{
				if(i==j)
				{
					if(a[j+1]>a[j-1]+1)a[j]=a[j-1]+1;
					else ans=max(ans,dp[j-1]+1),a[j]=-INF;
				}
				if(a[j]>a[j-1])
					dp[j]=dp[j-1]+1;
				else
					dp[j]=1;

				ans=max(ans,dp[j]);
			}
			a[i]=t;
		}

		printf("%lld",ans);		
	}

}

namespace solve2{

	int ans=1;
	int a[N];
	pii dp[N][2];

	void solve()
	{
		dp[1][0]=make_pair(1,a[1]);
		dp[1][1]=make_pair(1,-INF);
		for(int i = 2;i<=n;i++)
		{
	//		dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
			if(a[i+1]>a[i-1]+1)
				dp[i][1]=make_pair(dp[i-1][0].first+1,a[i-1]+1);
			else
			{
				ans=max(ans,dp[i-1][0].first+1);
				if(a[i]<=a[i-1])
					dp[i][1]=make_pair(1,-INF);
			}
			if(a[i]>a[i-1])
			{
				dp[i][0].first=dp[i-1][0].first+1;
				dp[i][0].second=a[i];
			}
			else
			{
				dp[i][0].first=1;
				dp[i][0].second=a[i];
			}

			if(dp[i-1][0].first+1>dp[i][1].first && a[i+1]>a[i-1]+1)
			{
				dp[i][1].first=dp[i-1][0].first+1;
				dp[i][1].second=a[i-1]+1;
			}
			else if(dp[i-1][1].first+1==dp[i][1].first && a[i+1]>a[i-1]+1)
				dp[i][1].second=min(dp[i][1].second,a[i-1]+1);
			
			if(a[i]>dp[i-1][1].second && dp[i-1][1].first+1>dp[i][1].first)
			{
				dp[i][1].first=dp[i-1][1].first+1;
				dp[i][1].second=a[i];
			}
			else if(dp[i-1][1].first+1==dp[i][1].first)
				dp[i][1].second=min(dp[i][1].second,a[i]);

	//		printf("%lld %lld %lld\n",i,dp[i][0].first,dp[i][1].first);
			ans=max(ans,max(dp[i][0].first,dp[i][1].first));

			if(a[i+1]<=dp[i][1].second)
			{
				dp[i][1]=make_pair(-INF,1);
			}
		}

		printf("%lld",ans);
	}
}

signed main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);

	n=read();
	for(int i = 1;i<=n;i++)
		a[i]=read();
	if(n<=2000)solve1::solve();
	else solve2::solve();

	return 0;
}