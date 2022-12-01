#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define MAXN 10000005
#define MOD 1000000007
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
int n,m,l,r,x;
int num[MAXN],cnt[MAXN];
bool vis[MAXN];
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		x=read();
		num[x]++;
	}
	for (int i=2;i<MAXN;i++)
		if (!vis[i])for (int j=i;j<MAXN;j+=i)
		{
			vis[j]=1;
			cnt[i]+=num[j];
			cnt[i]%=MOD;
		}
	for (int i=2;i<MAXN;i++)
	{
		cnt[i]+=cnt[i-1];
		cnt[i]%=MOD;
	}
	while (m--)
	{
		l=read();r=read();
		printf("%d\n",(cnt[r]-cnt[l-1]+MOD)%MOD);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
