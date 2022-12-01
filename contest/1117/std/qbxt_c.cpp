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
#define int __int128
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
const int N=2e5+5;
int n,q,a[N],c[N],w[N];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
struct Seg {
	int val[N<<2];
	void update(int x,int l,int r,int p,int v) {
		if(l==r) {
			val[x]=v;
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=val[lc]+val[rc];
	}
	int query(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return val[x];
		int res=0;
		if(L<=mid) res+=query(lc,l,mid,L,R);
		if(mid+1<=R) res+=query(rc,mid+1,r,L,R);
		return res;
	}
} sm;

struct seg {
	int l,r,c;
	bool operator < (const seg &p)const {
		return l<p.l;
	}
};

set<seg> sg;

inline set<seg>::iterator split(int x) {
	if(x==n+1) return sg.end();
	auto it=prev(sg.upper_bound((seg) {
		x,0,0
	}));
	if(it->l==x) return it;
	seg tmp=*it;
	sg.erase(it);
	sg.insert((seg) {
		tmp.l,x-1,tmp.c
	});
	return sg.insert((seg) {
		x,tmp.r,tmp.c
	}).first;
}
__int128 O=0;
inline int work(int x,int y,int z,int p) {
	int tmp=max(a[x]-(y?a[x-1]:0),O)+max(a[x]-(z?a[x+1]:0),O);
	if(p) sm.update(1,1,n,x,tmp*w[x]);
	return tmp*w[x];
}

inline int Q(int x) {
	if(x==0||x==n+1) return -1;
	return prev(sg.upper_bound((seg) {
		x,0,0
	}))->c;
}

void update(int x) {
	if(x==0||x==n+1) return;
	int flg1=0,flg2=0,c=Q(x);
	if(x!=1&&Q(x-1)==c) flg1=1;
	if(x!=n&&Q(x+1)==c) flg2=1;
	work(x,flg1,flg2,1);
}

inline void assign(int l,int r,int c) {
	auto R=split(r+1),L=split(l);
	for(; L!=R;) {
		seg tmp=*L;
		++L;
		sg.erase(tmp);
		if(tmp.l!=l&&tmp.l!=r) work(tmp.l,1,1,1);
		if(tmp.r!=tmp.l&&tmp.r!=l&&tmp.r!=r) work(tmp.r,1,1,1);
	}
	auto it=sg.insert((seg) {
		l,r,c
	}).first;
	int flg1=0,flg2=0;
	if(it!=sg.begin()&&prev(it)->c==c) flg1=1;
	if(next(it)!=sg.end()&&next(it)->c==c) flg2=1;
	if(l==r) work(l,flg1,flg2,1);
	else work(l,flg1,1,1),work(r,1,flg2,1);
	update(l-1);
	update(r+1);
}

signed main() {
	n=read();
	q=read();
	for(int i=1; i<=n; ++i)
		a[i]=read(),c[i]=read(),w[i]=read();
	for(int i=1; i<=n; ++i) {
		work(i,c[i]==c[i-1],c[i]==c[i+1],1);
		sg.insert((seg) {
			i,i,c[i]
		});
	}
	while(q--) {
		int opt=read();
		if(opt==1) {
			int x=read();
			a[x]=read();
			w[x]=read();
			int c1=Q(x),c2=Q(x-1),c3=Q(x+1);
			work(x,c1==c2,c1==c3,1);
			if(x!=1) work(x-1,c2==Q(x-2),c2==c1,1);
			if(x!=n) work(x+1,c3==c1,c3==Q(x+2),1);
		} else if(opt==2) {
			int l=read(),r=read(),c=read();
			assign(l,r,c);
		} else {
			int l=read(),r=read(),ans=0;
			if(l+1<=r-1) ans=sm.query(1,1,n,l+1,r-1);
			ans+=work(l,0,Q(l+1)==Q(l)&&l!=r,0);
			if(l!=r) ans+=work(r,Q(r-1)==Q(r),0,0);
			write(ans);
			puts("");
		}
	}
	return 0;
}
