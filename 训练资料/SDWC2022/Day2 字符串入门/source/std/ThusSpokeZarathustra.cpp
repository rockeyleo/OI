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
const int N=200010;const ull bas=37;
char s[N],t[N];int n,m;ull hvs[N],hvt[N],mi[N];unordered_set<ull> sv;
inline void get_hv(char *s,int n,ull *hv) { rep(i,1,n) hv[i]=hv[i-1]*bas+(s[i]-'a'+1); }
inline ull ghv(ull *hv,int L,int R) { return hv[R]-hv[L-1]*mi[R-L+1]; }
inline int check(int k)
{
	int ans=0;
	rep(i,1,n-k+1) sv.insert(ghv(hvs,i,i+k-1));
	rep(i,1,m-k+1)
		if(sv.count(ghv(hvt,i,i+k-1))) { ans=1;break; }
	unordered_set<ull>().swap(sv);
	return ans;
}
int main()
{
	freopen("ThusSpokeZarathustra.in","r",stdin);
	freopen("ThusSpokeZarathustra.out","w",stdout);
	scanf("%s%s",s+1,t+1),n=(int)strlen(s+1),m=(int)strlen(t+1);
	mi[0]=1;rep(i,1,max(n,m)) mi[i]=mi[i-1]*bas;
	get_hv(s,n,hvs),get_hv(t,m,hvt);
	int L=0,R=min(n,m);
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check(mid)) L=mid+1;
		else R=mid-1;
	}
	return !printf("%d\n",R);
}
