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
int g[500002][2],cnt[500002],n;
inline void ed(int x,int y){
	if(g[x][0]==y||g[x][1]==y)return;
	if(cnt[x]==2||cnt[y]==2||(x==y&&cnt[x]==1)){
		puts("0");
		exit(0);
	}
	g[x][cnt[x]++]=y;
	g[y][cnt[y]++]=x;
}
bool vis[500002];
int tot,fac[500002],pw[500002],ifac[500002],num2,num,mul=1;
inline void dfs(int pos){
	++tot;
	vis[pos]=true;
	F(i,0,cnt[pos]-1)if(!vis[g[pos][i]])dfs(g[pos][i]);
}
inline int inv(int x){
	int p=mod-2,rt=1;
	while(p){
		if(p&1)rt=1ll*rt*x%mod;
		x=1ll*x*x%mod,p>>=1;
	}
	return rt;
}
int main() {
	cin>>n;
	F(i,1,read())ed(read(),read());
	fac[0]=pw[0]=1;
	F(i,1,n)fac[i]=1ll*fac[i-1]*i%mod,pw[i]=pw[i-1]*2%mod;
	ifac[n]=inv(fac[n]);
	UF(i,n-1,0)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	F(i,1,n)if(cnt[i]==0)++num,vis[i]=true;
	F(i,1,n)if(cnt[i]==1&&!vis[i]){
		tot=0;
		dfs(i);
		if(tot==1);
		else if(tot==2)++num2,++num;
		else mul=(mul<<1)%mod,++num;
	}
	F(i,1,n)if(!vis[i]){
		tot=0;
		dfs(i);
		if(tot>2)mul=(mul<<1)%mod;
	}
	ll ans=0;
	F(i,0,num2){
		if(i&1)ans-=1ll*pw[num2-i]*fac[num-i]%mod*fac[num2]%mod*ifac[i]%mod*ifac[num2-i]%mod;
		else ans+=1ll*pw[num2-i]*fac[num-i]%mod*fac[num2]%mod*ifac[i]%mod*ifac[num2-i]%mod;
	}
	cout<<(ans%mod+mod)*mul%mod;
	return 0;
}

