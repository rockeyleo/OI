#include <bits/stdc++.h>
using namespace std;
const int M = 5050;
int dp[M][2];
int head[M],nxt[M],to[M],cnt;

void dfs(int u,int fa){
	dp[u][0] = 0; dp[u][1] = 1;
	for(int i=head[u];i;i=nxt[i]){
		int tt = to[i];
		if(tt==fa)continue;
		dfs(tt,u);
		dp[u][0] += dp[tt][1];
		dp[u][1] += min(dp[tt][1],dp[tt][0]);
	}
}

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int name,k;
		cin>>name>>k;
		for(int j=1;j<=k;j++){
			int t;
			cin>>t;
			add(name,t);
			add(t,name);
		}
	}
	dfs(0,-1);
	cout<<min(dp[0][1],dp[0][0]);
}
