#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1005,M=1e6+5;
int n,q,a[M],lf[N][N],rf[N][N];

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			lf[i][j]=INF,rf[i][j]=-INF;
	lf[1][1]=1;rf[1][1]=1e6;
	for(int i=1;i<n;++i)
		for(int j=1;j<=i;++j)
		{
			int w=read();
			if(lf[i][j]>rf[i][j])
				continue;
			if(w<lf[i][j])
			{
				lf[i+1][j+1]=min(lf[i+1][j+1],lf[i][j]);
				rf[i+1][j+1]=max(rf[i+1][j+1],rf[i][j]);
			}
			else if(w>=rf[i][j])
			{
				lf[i+1][j]=min(lf[i+1][j],lf[i][j]);
				rf[i+1][j]=max(rf[i+1][j],rf[i][j]);
			}
			else
			{
				lf[i+1][j]=min(lf[i+1][j],lf[i][j]);
				rf[i+1][j]=max(rf[i+1][j],w);
				lf[i+1][j+1]=min(lf[i+1][j+1],w+1);
				rf[i+1][j+1]=max(rf[i+1][j+1],rf[i][j]);
			}
		}
	for(int i=1;i<=q;++i)
		a[read()]++;
	for(int i=1;i<=1000000;++i)
		a[i]+=a[i-1];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			int res=0;
			if(lf[i][j]<=rf[i][j])
				res=a[rf[i][j]]-a[lf[i][j]-1];
			write(res);putchar(' ');
		}
		puts("");
	}
	return 0;
}
