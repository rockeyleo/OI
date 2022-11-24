#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+100;
typedef long long ll;
const int inf=1e9;
ll dp[maxn];
ll da[maxn];
ll a[maxn],n,ans;
int main(){
//	freopen("lis.in","r",stdin);
//	freopen("lis.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1e9;
	}
	da[n]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=1;
		}
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]){
			da[i]=da[i+1]+1;
		}else{
			da[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i-1]!=1&&a[i+1]>a[i-1])ans=max(da[i+1]+dp[i-1]+1,ans);
	}
	for(int i=2;i<=n;i++){
		if(dp[i]!=n){
			ans=max(ans,dp[i]+1);
		}else{
			ans=max(ans,dp[i]);
		}
	}
	for(int i=1;i<n;i++){
		if(da[i]!=n){
			ans=max(ans,da[i]+1);
		}else{
			ans=max(ans,da[i]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
