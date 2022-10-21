#include<bits/stdc++.h>
using namespace std;
inline int Abs(int x) {return x<0?-x:x;}
int n,x[100100];
int f[510][510],g[510][510];
int ans[510*510];
int main() {
//	freopen("lis8.in","r",stdin);
//	freopen("lis8.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) g[j][k]=1e9;
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) g[j+1][k+1]=min(g[j+1][k+1],f[j][k]);
		for(int k=1;k<=n;k++) for(int j=0;j<n;j++) g[j+1][k]=min(g[j+1][k],g[j][k]);
		for(int j=1;j<=n;j++) for(int k=0;k<=n;k++) f[j][k]=min(f[j][k],g[j][k]+Abs(j-x[i]));
	}
//	cerr<<f[n][n]<<endl;
	for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) {
		if(f[j][k]>n*n) continue;
		ans[f[j][k]]=max(ans[f[j][k]],k);
	}
	for(int i=1;i<=n*n;i++) ans[i]=max(ans[i],ans[i-1]);
	for(int i=0;i<=n*n;i++) cout<<ans[i]<<' ';
}
/*
9
8 2 4 9 5 6 3 7 1


*/
