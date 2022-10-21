#include<cstdio>
#include<cstdlib>
using namespace std;

typedef long long ll;
int T; ll N,a,b;

inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld %lld",&N,&a,&b);
		if (((N/gcd(a,b))&1)) puts("baiyun");
		else puts("baitu");
	}
	return 0;
}
