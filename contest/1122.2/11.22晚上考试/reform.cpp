#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include<set>
#include<algorithm>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define LL long long
#define md double
using namespace std;
const int inf=2147483647;
const int N=1e6+100;
int getint();
int a[N],b[N],n,m;
int last[N],prea[N],preb[N],nxt[N];
int ans[N],ansl;
int main()
{
#ifndef ONLINE_JUDGE
	fre("reform");
#endif
	int T,A,i,j;
    for (T=getint(),A=getint();T--;) {
		n=getint(),m=getint();
		
		for (i=1;i<=A;i++) last[i]=0;
		for (i=1;i<=n;i++) prea[i]=i-last[a[i]=getint()],last[a[i]]=i;
		for (i=1;i<=A;i++) last[i]=0;
		for (i=1;i<=m;i++) preb[i]=i-last[b[i]=getint()],last[b[i]]=i;

		nxt[1]=0;
		for (i=2,j=0;i<=m;i++) {
			while (j&&preb[j+1]!=min(preb[i],j+1)) j=nxt[j];
			nxt[i]=(j+=preb[j+1]==min(preb[i],j+1));
		}

		ansl=0;preb[m+1]=inf;
		for (i=1,j=0;i<=n;i++) {
			while (j&&min(prea[i],j+1)!=preb[j+1]) j=nxt[j];
			if ((j+=min(prea[i],j+1)==preb[j+1])==m) ans[++ansl]=i;
		}
		printf("%d\n",ansl);
		for (i=1;i<ansl;i++) printf("%d ",ans[i]-m+1);printf("%d\n",ans[ansl]-m+1);
	}
	return 0;
}
int getint()
{
	int w=0;
	bool q=1;
	char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
