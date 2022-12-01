#include<bits/stdc++.h>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define LL long long
using namespace std;
const int N=1e5+100;
inline int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int head[N],nxt[N<<1],to[N<<1];
int q[N],val[N],fa[N],in[N],st[N];LL f[N],pre[N],suf[N],dis[N];
int main()
{
	fre("attack");
	int n=gi(),i,a,b,tot=0,l,r,C,k,len=0;LL ans=0,sum,D;
	for (i=1;i<=n;i++) val[i]=gi();
	for (i=1;i<n;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
	}
	l=0,q[r=1]=1;dis[1]=0;D=0;
	while (l!=r) {
		if ((dis[k=q[++l]]+=val[k])>D) D=dis[k],C=k;
		for (i=head[k];i;i=nxt[i]) if (to[i]!=fa[k]) fa[to[i]]=k,q[++r]=to[i],dis[to[i]]=dis[k];
	}
	l=0,q[r=1]=C;dis[C]=0;D=0;fa[C]=0;
	while (l!=r) {
		if ((dis[k=q[++l]]+=val[k])>D) D=dis[k],C=k;
		for (i=head[k];i;i=nxt[i]) if (to[i]!=fa[k]) fa[to[i]]=k,q[++r]=to[i],dis[to[i]]=dis[k];
	}
	for (k=C;k;k=fa[k]) st[++len]=k,in[k]=true;
	for (a=1;a<=len;a++) {
		l=0,q[r=1]=st[a];
		while (l!=r) for (i=head[k=q[++l]];i;i=nxt[i]) if (to[i]!=fa[k]&&!in[to[i]]) q[++r]=to[i],fa[to[i]]=k;
		while (r) {
			for (i=head[k=q[r--]],f[k]=val[k];i;i=nxt[i]) if (to[i]!=fa[k]&&!in[to[i]]) {
					if (!in[k]) ans=max(ans,f[k]+f[to[i]]);
					f[k]=max(f[k],f[to[i]]+val[k]);
				}
			if (!in[k]) ans=max(ans,f[k]);
		}
	}
	for (i=1,sum=0;i<=len;sum+=val[st[i++]]) pre[i]=max(pre[i-1],sum+f[st[i]]);
	ans+=sum;
	for (i=len,sum=0;i;sum+=val[st[i--]]) suf[i]=max(suf[i+1],sum+f[st[i]]);
	for (i=1;i<len;i++) ans=max(ans,pre[i]+suf[i+1]);
	cout<<ans<<endl;
	return 0;
}
