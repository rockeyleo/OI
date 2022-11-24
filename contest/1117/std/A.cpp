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
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
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
		register int cnt = 0 ;
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
int n,m,o[1000002],deg[1000002],tag[1000002];
vector<int>g[1000002],f[1000002];
int q[1000002],l,r;
bool vis[1000002];
int main() {
	cin>>n>>m;
	F(i,1,n)read(o[i]),o[i]^=1;
	F(i,1,m){
		int x=read(),y=read();
		g[x].push_back(y);
		f[y].push_back(x);
		++deg[x];
	}
	l=1;
	F(i,1,n){
		if(!deg[i]){
			q[++r]=i;
			vis[i]=true;
		}
	}
	while(l<=r){
		int pos=q[l++];
		for(int i:f[pos]){
			--deg[i];
			if(!deg[i]){
				q[++r]=i;
				vis[i]=true;
			}
		}
	}
	reverse(q+1,q+r+1);
	F(i,1,n)if(!vis[i]&&o[i]){
		puts("-1");return 0;
	}
	int ans=0;
	F(i,1,r){
		int pos=q[i];
		if(o[pos]^tag[pos]){
			++ans;tag[pos]^=1;
		}
		if(tag[pos])for(int j:g[pos])tag[j]^=1;
	}
	cout<<ans<<endl;
	return 0;
}
