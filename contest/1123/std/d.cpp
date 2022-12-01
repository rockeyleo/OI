#include <bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
using namespace std;
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
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
const int MAXN=2010;
int a[MAXN][MAXN],b[MAXN][MAXN],n,now[MAXN],k[MAXN];
bool vis[MAXN];
int main(){
	read(n);
	F(i,1,n)F(j,1,n+1)read(a[i][j]);
	F(i,1,n)F(j,1,n+1)b[i][a[i][j]]=j;
	UF(i,n,1){
		while(vis[b[i][++k[i]]]);
		vis[b[i][k[i]]]=true;
	}
	write(min_element(vis+1,vis+n+2)-vis);
    return 0;
}

