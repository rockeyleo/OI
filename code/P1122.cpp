#include <bits/stdc++.h>
using namespace std;
const int M = 50501;
int head[M],nxt[M],cnt,to[M];
int dp[M],val[M];

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

void dfs(int fa,int now){
	for(int i=head[now];i;i=nxt[i]){
		int tt = to[i];
		if(tt==fa)continue;
		dfs(now,tt);
		dp[now] += max(0,dp[tt]);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		dp[i] = val[i];
	}
	for(int i=1;i<=n-1;i++){
		int f,t;
		cin>>f>>t;
		add(f,t);
		add(t,f);
	}
	dfs(-1,1);
	int ans = -1999999999;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
}
