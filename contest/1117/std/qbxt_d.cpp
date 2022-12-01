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
		if(x==0){
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
#define mod 998244353
int n,pw[100002],len[100002],a[20][20],p[20],w[20][20];
char s[16][100002];
bool gg[16];
inline int inv(int x){
	int p=mod-2,rt=1;
	while(p){
		if(p&1)rt=1ll*rt*x%mod;
		p>>=1;x=1ll*x*x%mod;
	}
	return rt;
}
inline int gauss(int n){
	++n;
	F(i,1,n-1)a[i][n]=mod-1,a[i][n+1]=0;
	F(i,1,n+1)a[n][i]=1;
	a[n][n]=0;
	F(i,1,n){
		F(j,i,n)if(a[j][i]){
			if(i!=j)F(k,i,n+1)swap(a[i][k],a[j][k]);
			break;
		}
		int v=inv(a[i][i]);
		F(j,i,n+1)a[i][j]=1ll*a[i][j]*v%mod;
		F(j,i+1,n){
			int v=a[j][i];
			F(k,i,n+1)a[j][k]=(a[j][k]-1ll*v*a[i][k])%mod;
		}
	}
	return a[n][n+1];
}
inline bool bl(int x,int y){
	F(i,1,len[y]-len[x]+1)if(memcmp(s[x]+1,s[y]+i,len[x])==0)return true;
	return false;
}
int main() {
	pw[0]=1;
	F(i,1,100000)pw[i]=1ll*pw[i-1]*26%mod;
	cin>>n;
	F(i,0,n-1){
		scanf("%s",s[i]+1);
		len[i]=strlen(s[i]+1);
	}
	F(i,0,n-1){
		F(j,0,n-1)if(i!=j&&!gg[j]&&bl(i,j)){
			gg[i]=true;
			break;
		}
	}
	F(i,0,n-1)F(j,0,n-1)if(!gg[i]&&!gg[j]){
		F(k,1,min(len[i],len[j]))if(memcmp(s[i]+1,s[j]+len[j]-k+1,k)==0)(w[i][j]+=pw[k])%=mod;
	}
	ll ans=0;
	F(S,1,(1<<n)-1){
		int cnt=0;
		F(j,0,n-1)if(S>>j&1)p[++cnt]=j;
		bool flag=true;
		F(j,1,cnt)if(gg[p[j]]){
			flag=false;
			break;
		}
		if(!flag)continue;
		F(i,1,cnt)F(j,1,cnt)a[i][j]=w[p[i]][p[j]];
		if(__builtin_parity(S))ans+=gauss(cnt);
		else ans-=gauss(cnt);
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}
