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
const int N=300010;
struct Q{
	pii v[N];int cnt,fp,rp,l;Q() { cnt=0,l=1,fp=1,rp=0; }
	inline void push(int x) { while(fp<=rp&&v[rp].fir<=x) rp--;v[++rp]=mp(x,++cnt); }
	inline void pop() { if(fp<=rp&&v[fp].sec==l) fp++;l++; }
	inline int max() { assert(fp<=rp);return v[fp].fir; }
}q1,q2;int a[N];
int main()
{
	int n=inn(),k=inn(),ans=1;
	rep(i,1,n) a[i]=inn();
	for(int i=1,j=1;i<=n;i++)
	{
		q1.push(a[i]),q2.push(-a[i]);
		while(q1.max()+q2.max()>k) q1.pop(),q2.pop(),j++;
		ans=max(ans,i-j+1);
	}
	return !printf("%d\n",ans);
}
