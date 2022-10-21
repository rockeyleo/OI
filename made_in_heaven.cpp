#include <bits/stdc++.h>
using namespace std;
namespace made_in_heaven{
	const int MB(1<<20);
	static char buf[MB],*p1(buf),*p2(buf),puf[MB],*p3(puf),*p4(puf+MB);
    static streambuf *Buf(cin.rdbuf()),*Puf(cout.rdbuf());
	#define gc() (p1==p2&&(p2=(p1=buf)+Buf->sgetn(buf,MB),p1==p2)?EOF:*p1++)
	#define pc(c) ((p3==p4)?(Puf->sputn(p3=puf,MB),*p3++=c):(*p3++=c))
	template<typename T>
	inline void read(T &x){
        x=0;char c=gc();int f=1;
        while(c<48||c>57){if(c=='-')f=-1;c=gc();}
        while(c>=48&&c<=57) x=(x<<1)+(x<<3)+(c&15),c=gc();
        x*=f;
    } 
    template<typename T,typename ...Args>
    inline void read(T& x,Args& ...args){
        read(x);read(args...);
    }
    template<typename T>
    inline void write(const char c,T x){
		static char st[20];int tp=0;
		if(x<0){pc('-'),x=-x;}
		if(!x){pc('0');}
		while(x)st[++tp]=(x%10)|48,x/=10; 
		while(tp)pc(st[tp--]);
		pc(c);
    }
    template<typename T,typename ...Args>
	inline void write(const char c,T x,Args ...args){
		write(c,x);write(c,args...);
    }
    inline int fh(){
    	Puf->sputn(puf,p3-puf);
    	return 0;
	}
}
using namespace made_in_heaven;