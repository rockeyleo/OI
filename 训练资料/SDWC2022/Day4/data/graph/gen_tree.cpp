#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int pa[100005];
int find(int x)
{
	return x==pa[x]?x:pa[x];
}
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int n=rnd.next(maxn/3*2,maxn);
	if(strcmp(argv[2],"-n")==0)n=maxn;
	for(int i=1;i<=n;i++)pa[i]=i;
	printf("%d %d\n",n,n-1);
	for(int i=1;i<=n-1;i++)
	{
		int u=rnd.next(1,n);
		int v=rnd.next(1,n);
		while(find(u)==find(v))
		{
			u=rnd.next(1,n);
			v=rnd.next(1,n);
		}
		printf("%d %d\n",u,v);
		pa[find(u)]=find(v);
	}
	return 0;
}
