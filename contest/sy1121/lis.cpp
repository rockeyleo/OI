#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int num[M];
int pre[M];
int dp[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}

int main(){
	freopen("lis1.in","r",stdin);
	freopen("lis.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		num[i] = read();
		dp[i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=max(1,i-2);j<=i;j++){
			if(num[i]>num[j] and num[i]-num[j]>=i-j){
//				cout<<i<<" "<<num[i]<<" "<<j<<" "<<num[j]<<endl;
				if(dp[j]+1>dp[i]){
					dp[i] = dp[j]+1;
					pre[i] = i-j-1+pre[j];
//					cout<<i<<" "<<dp[i]<<" ";
//					cout<<pre[i]<<endl;
				}
			}
//			if(num[j]<num[i]){
//				dp[i] = max(dp[i],dp[j]+1);
//			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i]+pre[i]);
	}
	cout<<ans<<endl;
}
