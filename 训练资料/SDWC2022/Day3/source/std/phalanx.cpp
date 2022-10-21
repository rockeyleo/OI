#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll x[500005],y[500005];
int main()
{
	freopen("phalanx.in","r",stdin);
	freopen("phalanx.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]+=y[i];
		y[i]=x[i]-2*y[i];
	}
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	ll ans=0;
	for(int i=1;i<n;i++)ans+=(x[i+1]-x[i])*i*(n-i);
	for(int i=1;i<n;i++)ans+=(y[i+1]-y[i])*i*(n-i);
	printf("%lld\n",ans/2);
	return 0;
}
