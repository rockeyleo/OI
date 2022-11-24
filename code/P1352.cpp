#include <bits/stdc++.h>
using namespace std;
const int M = 8080;
//int val[M];
int head[M],nxt[M],cnt,to[M];
int dp[M][2];
int in[M];

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	in[t]++;
}

void dfs(int now,int from){
	for(int i=head[now];i;i=nxt[i]){
		int tt = to[i];
		if(tt==from)continue;
		dfs(tt,now);
		dp[now][1] += dp[tt][0];
		dp[now][0] += max(dp[tt][1],dp[tt][0]);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i][1];
	}
	for(int i=1;i<=n-1;i++){
		int f,t;
		cin>>f>>t;
//		add(f,t);
		add(t,f);
	}
	int root = 0;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dfs(i,0);
			root = i;
			break;
		}
	}
	cout<<max(dp[root][1],dp[root][0]);
}
