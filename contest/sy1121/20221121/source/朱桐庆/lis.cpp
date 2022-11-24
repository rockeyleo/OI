#include<bits/stdc++.h>
using namespace std;
int n,a[300005],dp1[300005],dp2[300005];
int maxn,vis,dis[300005],now; 
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp1[1]=1;
	dp2[2]=1;
	for(int i=2;i<=n;i++)	
		{
		if(a[i-1]<a[i])dp1[i]=dp1[i-1]+1;
		else dp1[i]=1;
		maxn=max(maxn,dp1[i]);
		}
	for(int j=1;j<=n;j++)
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis&&!dis[i-1]&&a[i]-a[i-2]>=2)
			{
				vis=1;
				dis[i-1]=1;
				now=i;
				dp2[i]=dp1[i-2]+2;
				
			}
			if(vis&&dp1[i]==dp1[now]+1&&i==now+1)
			{
				now++;
				dp2[i]=dp2[i-1]+1;
			}
			maxn=max(maxn,dp2[i]);
			}
		vis=0;
		dp1[1]=1;
		now=0;
		}	
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
7 2 3 1 5 6
*/
