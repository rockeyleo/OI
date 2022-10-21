#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int pa[100005],x[1000005],y[1000005],m;
int find(int x)
{
	return x==pa[x]?x:pa[x];
}
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxc=atoi(argv[2]);
	int n=rnd.next(max(10,maxn/3*2),maxn);
	if(strcmp(argv[3],"-n")==0)n=maxn;
	int a=rnd.next(maxc,min(500,n/2));
	int b=n-a;
	for(int i=1;i<=n;i++)pa[i]=i;
	int now=n;
	while(now>maxc)
	{
		int u=rnd.next(1,a);
		int v=rnd.next(1,b);
		v+=a;
		if(rnd.next(0,1)&1)x[++m]=u,y[m]=v;
		else x[++m]=v,y[m]=u;
		u=find(u),v=find(v);
		if(u!=v)pa[u]=v,now--;
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)pa[i]=i;
	shuffle(pa+1,pa+n+1);
	for(int i=1;i<=m;i++)printf("%d %d\n",pa[x[i]],pa[y[i]]);
	return 0;
}
