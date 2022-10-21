#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxv=atoi(argv[2]);
	int n=rnd.next(maxn/3*2,maxn);
	if(strcmp(argv[3],"-n")==0)n=maxn;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",0,rnd.next(-maxv,maxv));
	return 0;
}
