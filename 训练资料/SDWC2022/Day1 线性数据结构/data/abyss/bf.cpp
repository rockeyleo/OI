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
const int N=300010;int a[N];
int main()
{
	freopen("data.in","r",stdin);
	int n=inn(),k=inn(),ans=1;
	rep(i,1,n) a[i]=inn();
	rep(i,1,n)
	{
		int mn=a[i],mx=a[i];
		rep(j,i+1,n)
		{
			mn=min(mn,a[j]),mx=max(mx,a[j]);
			if(mx-mn>k) break;ans=max(ans,j-i+1);
		}
	}
	return !printf("%d\n",ans);
}
