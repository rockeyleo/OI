#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
int main()
{
	FILE *fsd=fopen("seed.txt","r");unsigned int sd,ccc;fscanf(fsd,"%u%u",&sd,&ccc);
	FILE *gsd=fopen("seed.txt","w");sd+=12321,ccc+=1;fprintf(gsd,"%u\n%u\n",sd,ccc);
	freopen("data.in","w",stdout),srand((unsigned int)time(0)+sd);
	int T=1;printf("%d\n",T);
	rep(id,1,T)
	{
		int n=26,v=n;printf("%d\n",n);
		rep(i,1,n) printf("%d%c",getn(0,v)," \n"[i==n]);
	}
	return 0;
}
