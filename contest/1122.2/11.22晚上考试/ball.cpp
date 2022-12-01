#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include<set>
#include<algorithm>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define LL long long
#define md double
#define RG register
using namespace std;
const int inf=2147483647;
const int N=1e5+100;
inline int gi() {
	RG int w=0;
	RG bool q=1;
	RG char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
struct P{ int x,y; bool operator < (const P &b) const { return y==b.y?x>b.x:y<b.y; } }p[N];
inline bool cmp(const P &a,const P &b) { return a.x==b.x?a.y<b.y:a.x>b.x; }
int main()
{
    int n=gi(),i;long long a=0,b=0;char c;while ((c=getchar())!='t'&&c!='y');
	for (i=1;i<=n;i++) p[i].x=gi(),p[i].y=gi();
	sort(p+1,p+1+n,cmp);
	if (c=='y') { a+=p[1].x; for (i=1;i<n;i++) p[i]=p[i+1]; n--; }
	for (i=1;i<=n;i+=2) b+=p[i].y;
	for (i=2;i<=n;i+=2) a+=p[i].x;
	priority_queue<P>q;
	for (i=n-1-(n&1);i>0;i-=2) {
		q.push(p[i+1]);
		if (p[i].y<=q.top().y) {
			b+=q.top().y;a-=q.top().x;q.pop();
			a+=p[i].x;b-=p[i].y;q.push(p[i]);
		}
	}
	printf("%lld %lld\n",a,b);
	return 0;
}
