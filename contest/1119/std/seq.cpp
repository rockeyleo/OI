#include<bits/stdc++.h>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define LL long long
using namespace std;
const int inf=2147483647;
const int N=1e6+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int d[N],ans;
int pre[N],suf[N],all[N];int s[N];
#define lc (i<<1)
#define rc (i<<1|1)
inline void update(int i) {
	s[i]=s[lc]+s[rc]-(suf[lc]&&pre[rc]);
	all[i]=all[lc]&all[rc];
	pre[i]=pre[lc]|(all[lc]&&pre[rc]);
	suf[i]=suf[rc]|(all[rc]&&suf[lc]);
}
inline void build(int i,int l,int r) {
	if (l==r) pre[i]=suf[i]=s[i]=d[l]>0,all[i]=d[l]==0;
	else {
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid+1,r);
		update(i);
	}
}
inline void modify(int i,int l,int r,int k) {
	if (l==r) pre[i]=suf[i]=s[i]=d[l]>0,all[i]=d[l]==0;
	else {
		int mid=(l+r)>>1;
		if (k<=mid) modify(lc,l,mid,k);
		else modify(rc,mid+1,r,k);
		update(i);
	}
}
int main()
{
	fre("seq");
    int n,i,T=gi(),Q,l,r,c;LL sum;
	while (T--) {
		n=gi()-1;Q=gi();
		for (i=0;i<=n;i++) d[i]=gi();
		for (i=n;i;i--) d[i]-=d[i-1];d[0]=0;
		sum=0;
		for (i=1;i<=n;i++) sum+=max(d[i],0);
		build(1,1,n);
		while (Q--)
			if (gi()) printf("%lld %d\n",sum,s[1]<<1);
			else {
				l=gi()-1,r=gi(),c=gi();
				if (l) {
					sum-=max(d[l],0);
					d[l]+=c;modify(1,1,n,l);
					sum+=max(d[l],0);
				}
				if (r<=n) {
					sum-=max(d[r],0);
					d[r]-=c;modify(1,1,n,r);
					sum+=max(d[r],0);
				}
			}
	}
	return 0;
}
