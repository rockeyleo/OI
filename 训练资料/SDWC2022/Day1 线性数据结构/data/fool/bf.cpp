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
const int N=200010;int l[N],r[N],del[N];
inline int check(int l,int r,int L,int R) { return l<=R&&L<=r; }
int main()
{
	freopen("data.in","r",stdin);
	int n=inn(),ans=0;
	rep(i,1,n)
	{
		l[i]=inn(),r[i]=inn(),ans=0;
		rep(j,1,i-1) if(!del[j] && check(l[i],r[i],l[j],r[j])) del[j]=1,ans++;
		printf("%d\n",ans);
	}
	return 0;
}
