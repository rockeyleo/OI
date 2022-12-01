#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+100,M=11;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
const int mod=1e9+7;
int f[N][M];
int fa[N],st[N];
inline int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return ans;
}
inline void dp(int a,int b) {
	for (int i=M-1;i;i--)
		for (int j=1;j<i;j++)
			f[a][i]=(f[a][i]+1LL*f[a][j]*f[b][i-j])%mod;
}
inline void Idp(int a,int b) {
	for (int i=1;i<M;i++)
		for (int j=1;j<i;j++)
			f[a][i]=(f[a][i]-1LL*f[a][j]*f[b][i-j])%mod;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	int n=gi(),m=gi(),i,k,s,t,top;
	for (i=1;i<=n;i++) f[i][1]=gi();
	for (i=2;i<=n;i++) fa[i]=gi();
	for (i=n;i>1;i--)
		dp(fa[i],i);
	while (m--)
		if (gi()) {
			k=gi(),s=gi();
			for (i=1;i<M;i++) f[0][i]=0;
			for (t=k,top=0;t;t=fa[t]) st[++top]=t;
			while (t=st[top--]) {
				for (i=1;i<M;i++) f[n+1][i]=f[0][i],f[0][i]=f[t][i];
				dp(0,n+1);
				if (top) Idp(0,st[top]);
			}
			printf("%d\n",(f[0][s]+mod)%mod);
		} else {
			k=gi();
			for (t=k,top=0;t;t=fa[t]) st[++top]=t;
			reverse(st+1,st+1+top);
			for (i=1;i<top;i++)
				Idp(st[i],st[i+1]);
			t=1LL*qpow(f[k][1],mod-2)*gi()%mod;
			for (i=1;i<M;i++)
				f[k][i]=1LL*f[k][i]*t%mod;
			for (i=top-1;i;i--)
				dp(st[i],st[i+1]);
		}
	return 0;
}
