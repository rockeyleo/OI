#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
int main()
{
	FILE *fsd=fopen("seed.txt","r");unsigned int sd,ccc;fscanf(fsd,"%u%u",&sd,&ccc);
	FILE *gsd=fopen("seed.txt","w");sd+=12321,ccc+=1;fprintf(gsd,"%u\n%u\n",sd,ccc);
	freopen("data.in","w",stdout),srand((unsigned int)time(0)+sd);
	int n=1000,d=n,k=300;printf("%d %d\n",n,k);
	for(int las=n/2,i=1;i<=n;printf("%c"," \n"[i==n]),i++)
		printf("%d",las=getn(max(1,las-d),min(las+d,n)));
	return 0;
}
