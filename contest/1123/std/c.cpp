//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0) {
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
const int mod=998244353;
int f[2][502][252][5],n,nn,k,ans[502],p[502];
namespace L {

	long long pw(long long x,long long p) {
		long long res=1;
		for(; p; p>>=1,x=x*x%mod)
			if(p&1)res=res*x%mod;
		return res;
	}
	long long getm(long long top,long long bot) {
		return (top*pw(bot,mod-2))%mod;
	}
	ll x[2002],y[2002],n,k;
	inline ll lagrange() {
		ll ans=0,fz,fm;
		F(i,1,n) {
			fz=y[i],fm=1;
			F(j,1,n) {
				if(i!=j) {
					fz=fz*(k-x[j]+mod)%mod;
					fm=fm*(x[i]-x[j]+mod)%mod;
				}
			}
			ans+=getm(fz,fm);
		}
		return ans%mod;
	}

}
int main() {
	cin>>nn>>k;
	n=min(nn,500);
	F(i,1,n)p[i]=L::pw(i,k);
	f[1][1][0][1]=1;
	auto *now=f[1],*lst=f[0];
	int ifac=1;
	F(i,2,n) {
		swap(now,lst);
		memset(now,0,sizeof(f[0]));
		F(s,0,i>>1) {
			F(p,1,3) {
				if(p&1) {
					int t=0;
					UF(j,i,1) {
						(t+=lst[j][s][p])%=mod;
						(now[j][s][p+1]+=t)%=mod;
					}
					t=0;
					F(j,1,i) {
						(now[j][s][1]+=t)%=mod;
						(t+=lst[j][s][p])%=mod;
					}
				} else {
					int t=0;
					UF(j,i,1) {
						(t+=lst[j][s][p])%=mod;
						(now[j][s][2]+=t)%=mod;
					}
					t=0;
					F(j,1,i) {
						(now[j][s][p+1]+=t)%=mod;
						(t+=lst[j][s][p])%=mod;
					}
				}
			}
			{
				int p=4;
				int t=0;
				UF(j,i,1) {
					(t+=lst[j][s][p])%=mod;
					(now[j][s][2]+=t)%=mod;
				}
				t=0;
				F(j,1,i) {
					(now[j][s+1][3]+=t)%=mod;
					(t+=lst[j][s][p])%=mod;
				}
			}
		}
		F(j,1,i)F(k,1,i>>1)F(s,1,4)ans[i]=(ans[i]+1ll*now[j][k][s]*p[k])%mod;
		ifac=L::getm(ifac,i);
		ans[i]=1ll*ans[i]*ifac%mod;
	}
	if(n==nn)write(ans[n]);
	else {
		L::n=101;
		L::k=nn;
		F(i,1,101)L::x[i]=399+i,L::y[i]=ans[399+i];
		write(L::lagrange());
	}
	return 0;
}

