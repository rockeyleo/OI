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
const int N=200010;char s[N],t[N];
inline int lcp(char *s,int n,char *t,int m)
{
	rep(i,1,min(n,m)) if(s[i]!=t[i]) return i-1;
	return min(n,m);
}
int main()
{
	freopen("data.in","r",stdin);
	scanf("%s%s",s+1,t+1);
	int n=(int)strlen(s+1),m=(int)strlen(t+1),ans=0;
	rep(i,1,n) rep(j,1,m) ans=max(ans,lcp(s+i-1,n-i+1,t+j-1,m-j+1));
	return !printf("%d\n",ans);
}
