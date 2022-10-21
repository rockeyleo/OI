#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int a[100],b[100];
lint dfs(int k,int n,lint s)
{
	if(k>n)
	{
		if(s==0)
		{
			rep(i,1,n) printf("%c",b[i]==0?'C':(b[i]>0?'A':'B'));
			printf("\n");
			return 1;
		}
		return 0;
	}
	int ans=0;
	b[k]=1,ans+=dfs(k+1,n,s+a[k]);
	b[k]=0,ans+=dfs(k+1,n,s);
	b[k]=-1,ans+=dfs(k+1,n,s-a[k]);
	return ans;
}
int main()
{
//	freopen("data.in","r",stdin);
	for(int T=inn();T;T--)
	{
		int n=inn();rep(i,1,n) a[i]=inn();
		printf("%lld\n",dfs(1,n,0ll));
	}
	return 0;
}
