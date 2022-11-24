#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define ll long long
#define MAXN 1000005
using namespace std;
inline int read()
{
	int num=0,sgn=1;
	char ch=getchar();
	while (ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if (ch=='-')sgn=-1,ch=getchar();
	while (ch>='0'&&ch<='9')num*=10,num+=ch-'0',ch=getchar();
	return num*sgn;
}
struct carpet
{
	ll a,b,c,d;
	carpet(){}
	carpet(ll _a,ll _b,ll _c,ll _d)
	{a=_a;b=_b;c=_c;d=_d;}
}cp[MAXN],pre[MAXN],suf[MAXN];
carpet operator+(carpet A,carpet B)
{
	if ((A.a==-1)||(B.a==-1))return carpet(-1,-1,-1,-1);
	carpet S;
	S.a=max(A.a,B.a);S.b=max(A.b,B.b);
	S.c=min(A.c,B.c);S.d=min(A.d,B.d);
	if ((S.a>=S.c)||(S.b>=S.d))return carpet(-1,-1,-1,-1);
	return S;
}
int T,p,q,n;
int a,b,c,d;
ll ans;
ll calc(carpet A)
{
	if (A.a==-1)return 0;
	return (A.c-A.a)*(A.d-A.b);
}
int main()
{
	T=read();
	while (T--)
	{
		p=read();q=read();n=read();
		for (int i=1;i<=n;i++)
		{
			a=read();b=read();c=read();d=read();
			cp[i]=carpet(a,b,c,d);
		}
		pre[0]=carpet(0,0,p,q);
		for (int i=1;i<=n;i++)
			pre[i]=pre[i-1]+cp[i];
		suf[n+1]=carpet(0,0,p,q);
		for (int i=n;i>=1;i--)
			suf[i]=suf[i+1]+cp[i];
		ans=0;
		for (int i=1;i<=n;i++)
			ans+=calc(pre[i-1]+suf[i+1]);
		ans-=calc(pre[n])*(ll)(n-1);
		cout<<ans<<endl;
	}
	return 0;
}