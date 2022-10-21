#include<cstdio>
#include<algorithm>
#include<cstring>
#define ull unsigned long long
using namespace std;
int n,m;
ull f[1005][1005];
int main()
{
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%llu",&f[i][i]);
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
			f[i][i+l-1]=f[i][i+l-2]^f[i+1][i+l-1];
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
			f[i][i+l-1]=max(f[i][i+l-1],max(f[i][i+l-2],f[i+1][i+l-1]));
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%llu\n",f[l][r]);
	}
	return 0;
}
