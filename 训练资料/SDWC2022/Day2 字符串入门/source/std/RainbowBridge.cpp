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
const int N=500010;int nxt[N],k[N];char s[N];vector<int> g[N];
inline int getnxt(char *s,int n,int *nxt)
{
	nxt[1]=0;
	rep(i,2,n)
	{
		int &j=nxt[i];j=nxt[i-1];
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
	}
	return 0;
}
int main()
{
	freopen("RainbowBridge.in","r",stdin);
	freopen("RainbowBridge.out","w",stdout);
	scanf("%s",s+1);lint ans=0;
	int t=inn(),n=(int)strlen(s+1);
	getnxt(s,n,nxt);
	for(int i=n;i;i--) k[nxt[i]]+=k[i]+1;
	if(!t) rep(i,1,n) ans+=k[i];
	else rep(i,1,n) ans+=(lint)i*k[i];
	return !printf("%lld\n",ans);
}
