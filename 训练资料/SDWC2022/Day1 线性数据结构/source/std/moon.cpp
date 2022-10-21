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
unordered_map<lint,int> m;lint ans;int a[100];
void dfs(int tp,int k,int n,lint dlt)
{
	if(k<=n) dfs(tp,k+1,n,dlt+a[k]),dfs(tp,k+1,n,dlt-a[k]),dfs(tp,k+1,n,dlt);
	else{
		if(tp==1)
		{
			if(m.count(dlt)) m[dlt]++;
			else m[dlt]=1;
		}
		else{
			if(m.count(-dlt)) ans+=m[-dlt];
		}
	}
}
int main()
{
	freopen("moon.in","r",stdin);
	freopen("moon.out","w",stdout);
	for(int T=inn();T;T--)
	{
		int n=inn();rep(i,1,n) a[i]=inn();
		unordered_map<lint,int>().swap(m);
		ans=0,dfs(1,1,n/2,0),dfs(2,n/2+1,n,0);
		printf("%lld\n",ans);
	}
	return 0;
}
