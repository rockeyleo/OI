#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
const int N=2e6+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
pair<int,int>p[N];
struct Q{ LL w; int id; inline bool operator < (const Q &b) const { return w>b.w; } };
int main()
{
#ifndef ONLINE_JUDGE
	freopen("mice.in","r",stdin);
	freopen("mice.out","w",stdout);
#endif
	int n=gi(),m=gi(),i,k,s=-n;LL ans=0,w;
	const LL inf=1e15;
	for (i=1;i<=n;i++) p[i]=make_pair(gi(),-1);
	while (m--) p[++n].x=gi(),s+=p[n].y=gi();
	if (s<0) return puts("-1"),0;
	sort(p+1,p+1+n);
	priority_queue< LL , vector<LL> , greater<LL> >q0;
	priority_queue<Q>q1;
	for (i=1;i<=n;i++)
		if (p[i].y==-1) {
			w=inf;
			if (!q1.empty()) {
				k=q1.top().id;w=p[i].x+q1.top().w;q1.pop();
				if (p[k].y) p[k].y--,q1.push((Q){-p[k].x,k});
			}
			ans+=w;
			q0.push(-p[i].x-w);
		} else {
			while (p[i].y&&!q0.empty()&&p[i].x+q0.top()<0) {
				p[i].y--;
				w=p[i].x+q0.top();q0.pop();
				ans+=w;q1.push((Q){-p[i].x-w,0});
			}
			if (p[i].y) q1.push((Q){-p[i].x,i}),p[i].y--;
		}
	cout<<ans<<endl;
	return 0;
}
