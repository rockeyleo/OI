#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define MAXN 2005
#define LL long long
using namespace std;
inline int read()
{
	int num=0,sgn=1;
	char ch=getchar();
	while (ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if (ch=='-')sgn=-1,ch=getchar();
	while (ch>='0'&&ch<='9')num*=10,num+=ch-'0',ch=getchar();
	return num*sgn;
}
int n,k,h[MAXN];
int l,r,mid;
bool check(int m)
{
	int dp[MAXN];
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
		dp[i]=i-1;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if ((LL)abs(h[i]-h[j])<=(LL)(j-i)*(LL)m)
				dp[j]=min(dp[j],dp[i]+j-i-1);
	for (int i=1;i<=n;i++)
		if (dp[i]+n-i<=k)return 1;
	return 0;
}
int main()
{
	freopen("planning.in","r",stdin);
	freopen("planning.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	l=0;r=2000000000;
	while (l<=r)
	{
		mid=l+(r-l)/2;
		if (check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
