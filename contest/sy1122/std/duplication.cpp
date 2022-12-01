#include<bits/stdc++.h>
#define MAXN 600000
using namespace std;
struct node
{int type,pos;}a[MAXN+5];
int n,m,L,R,M;
bool cmp(const node&A,const node&B)
{return A.pos<B.pos;}
bool check(int step)
{
	int pre,pt,hd,dis;
	for (pt=1;a[pt].type!=1;pt++);
	pre=(pt>1)?1:0;
	while (true)
	{
		if (pre&&a[pt].pos-a[pre].pos>step)return 0;
		if (!pre)dis=step;
		else dis=max(step-(a[pt].pos-a[pre].pos)*2,(step-(a[pt].pos-a[pre].pos))/2);
		for (hd=pt+1;hd<=n+m;hd++)
		{
			if (a[hd].type==1)break;
			if (a[hd].pos-a[pt].pos>dis)break;
		}
		if (hd>n+m)return 1;
		if (a[hd].type==1)pre=0,pt=hd;
		else
		{
			pre=hd;
			for (pt=hd+1;a[pt].type!=1&&pt<=n+m;pt++);
			if (pt>n+m)return 0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		a[i].type=1,scanf("%d",&a[i].pos);
	for (int i=1;i<=m;i++)
		a[n+i].type=2,scanf("%d",&a[n+i].pos);
	sort(a+1,a+n+m+1,cmp);
	L=0;R=2000000000;
	while (L<=R)
	{
		M=((long long)L+R)/2;
		if (check(M))R=M-1;
		else L=M+1;
	}
	printf("%d\n",L);
	return 0;
}