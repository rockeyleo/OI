#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define MAXN 2000005
#define Abs(x) (((x)>0)?(x):(-(x)))
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
int T,n,s[MAXN];
int pos,neg,ans,mn;
int main()
{
	T=read();
	while (T--)
	{
		n=read();
		pos=neg=ans=0;
		for (int i=1;i<=n;i++)
		{
			s[i]=read();
			if (s[i]>=0)pos=1;
			if (s[i]<=0)neg=1;
			ans+=Abs(s[i]);
		}
		if (n==1)
		{
			printf("%d\n",s[1]);
			continue;
		}
		mn=ans;
		for (int i=2;i<=n;i++)
			mn=min(mn,Abs(s[i])+Abs(s[i-1])-Abs(s[i]-s[i-1]));
		if (pos*neg)printf("%d\n",ans);
		else printf("%d\n",ans-mn);
	}
	return 0;
}