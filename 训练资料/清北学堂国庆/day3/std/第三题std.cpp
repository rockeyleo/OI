#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
const int N=1e5;
int gi() {
  char c;int w;bool q=true;
  while (((c=getchar())<'0'||'9'<c)&&c!='-');
  if (c=='-') q=false,w=0; else w=c-'0';
  while ('0'<=(c=getchar())&&c<='9') w=(w<<1)+(w<<3)+c-'0';
  return q?w:-w;
}
int n,m,S,T;
int head[N],nxt[N],to[N],pre[N];long long w1[N],w2[N],dis[N],ans=1e18;bool in[N];
struct P{ long long x,y; };
struct Q{ int k;long long dis; bool operator < (const Q &b) const { return dis>b.dis; } };
inline P djstl(register long long p1,register long long p2) {
	int i,k;P ans=(P){0,0};
	priority_queue<Q>q;
	for (i=1;i<=n;i++) dis[i]=1e18,in[i]=false;
	q.push((Q){S,dis[S]=0});
	while ((k=q.top().k)!=T) {
		q.pop();if (in[k]) continue;in[k]=true;
		for (i=head[k];i;i=nxt[i]) if (dis[k]+w1[i]*p1+w2[i]*p2<dis[to[i]]) {
				pre[to[i]]=i;
				q.push((Q){to[i],dis[to[i]]=dis[k]+w1[i]*p1+w2[i]*p2});
			}
	}
	for (k=T;k;k=to[pre[k]^1]) ans.x+=w1[pre[k]],ans.y+=w2[pre[k]];
	return ans;
}
inline void work(const P &l,const P &r) {
	P mid=djstl(l.y-r.y,r.x-l.x);
	if (mid.x*(l.y-r.y)+mid.y*(r.x-l.x)<l.y*r.x-l.x*r.y) work(l,mid),work(mid,r);
	else ans=min(ans,min(l.x*l.y,r.x*r.y));
}
int main() {
	n=gi(),m=gi(),S=gi(),T=gi();register int tot=1,a,b;register P l,r;
	while (m--) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
		w1[tot]=w1[tot-1]=gi(),w2[tot]=w2[tot-1]=gi();
	}
	l=djstl(1,0);r=djstl(0,1);
	work(l,r);
	printf("%lld\n",ans);
}
