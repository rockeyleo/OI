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
set<pii> s;
int main()
{
	int n=inn();
	rep(i,1,n)
	{
		int l=inn(),r=inn(),ans=0;
		do{
			set<pii>::iterator it=s.lower_bound(mp(l,-1));
			if(it==s.end()||r<it->sec) break;
			ans++,s.erase(it);
		}while(1);
		s.insert(mp(r,l)),printf("%d\n",ans);
	}
	return 0;
}
