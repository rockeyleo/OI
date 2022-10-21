#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxm=atoi(argv[2]);
	int n=rnd.next(maxn/3*2,maxn);
	int m=rnd.next(maxm/3*2,maxm);
	if(strcmp(argv[3],"-n")==0)n=maxn,m=maxm;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)printf("%llu ",rnd.next(0ull,(1ull<<62)-1)*4ull+rnd.next(0,3));
	printf("\n");
	while(m--)
	{
		int l=rnd.next(1,n),r=rnd.next(1,n);
		printf("%d %d\n",min(l,r),max(l,r));
	}
	return 0;
}
