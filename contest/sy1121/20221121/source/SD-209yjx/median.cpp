#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5,INF=0x3f3f3f3f3f3f3f3f;

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	return x;
}

int a[N],b[N];
int n,cnt;

bool check()
{
	for(int i = 1;i<=n;i++)
		if(a[i]!=b[i])return false;
	return true;
}

signed main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);

	n=read();
	a[1]=-INF;
	for(int i = 1;i<=n;i++)
		b[i]=read();
	
	double st=clock();

	for(cnt=0;!check();cnt++)
	{
		if(cnt%100==0 && ((double)clock()-st)/CLOCKS_PER_SEC>0.95)
		{
			puts("-1");
			return 0;
		}

		swap(a,b);
		b[1]=a[1],b[n]=a[n];
		for(int i = 2;i<n;i++)
			b[i]=a[i-1]+a[i]+a[i+1]-min(a[i-1],min(a[i],a[i+1]))-max(a[i-1],max(a[i],a[i+1]));

		for(int i = 1;i<=n;i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	printf("%lld",cnt-1);

	return 0;
}