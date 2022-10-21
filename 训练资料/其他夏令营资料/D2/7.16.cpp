/*
for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) {
	f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

for(int i=2;i<=n;i++) Log2[i]=Log2[i>>1]+1;

inline int query(int l,int r) {
	int t=Log2[r-l+1];
	return max(f[l][t],f[r-(1<<t)+1][t]);
}

for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) {
	f[i][j]=f[i][j-1]+f[to[i][j-1]][j-1];
	to[i][j]=to[to[i][j-1]][j-1];
}



inline pair<int,int> query(int s,int x) {
	pair<int,int> now=0;
	int nowpos=s;
	for(int j=20;j>=0;i--) {
		if(now.first+now.second+f[nowpos][j]<=x) {
			now+=f[nowpos][j];
			nowpos=to[nowpos][j];
		}
	}
	if(from nowpos ,A can go) {
		...
	}
	return now;
}


Node {
	int l,r;
};
inline int cmp(Node &a,Node &b) {
	return a.r<b.r;
}

sort(a+1,a+n+1,cmp);
int now=0;
for(int i=1;i<=n;i++) {
	if(a[i].l>=now) {
		if(a[i].r>Right) {
			break;
		}
		ans++;now=a[i].r;
	}
}


vector<int> ver[maxn];

int f[maxn][21],dep[maxn];
inline void dfs(int x,int fa) {
	f[x][0]=fa;dep[x]=dep[fa]+1;
	for(int i=0;i<(int)ver[x].size();i++) {
		int y=ver[x][i];
		if(y==fa) continue;
		dfs(y,x);
	}
}

inline int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int delta=dep[x]-dep[y],i=0;delta;i++,delta>>=1) if(delta&1) {
		x=f[x][i];
	}
	if(x==y) return y;
	for(int j=20;j>=0;j--) if(f[x][i]!=f[y][i]) {
		x=f[x][i];y=f[y][i];
	}
	return f[x][0];
}

int main() {
	dfs(1,0);
	for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	
}*/

/*
#include<bits/stdc++.h>
using namespace std;
vector<int> ver[100];

vector<int> Euler;
inline void dfs(int x,int fa) {
	Euler.push_back(x);
	for(int i=0;i<(int)ver[x].size();i++) {
		int y=ver[x][i];
		if(y==fa) continue;
		dfs(y,x);
		Euler.push_back(x);
	}
}

int n;

int main() {
	cin>>n;
	for(int i=1;i<n;i++) {
		int x,y;cin>>x>>y;
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	dfs(1,0);
	for(int i=0;i<(int)Euler.size();i++) {
		cout<<Euler[i]<<' ';
	}
}
*/

/*
int F[maxn];
inline int find(int x) {return x==F[x]?x:F[x]=find(F[x]);}

vector<int> ver[maxn];

struct Node {
	int y,int id;
	Node(y,id) {}
};
vector<Node> Q[maxn];

bool vis[maxn];

inline void tarjan(int x,int fa) {
	vis[x]=1;
	for(int i=0;i<(int)Q[x].size();i++) {
		int y=Q[x][i].y;
		if(vis[y]) {
			ans[Q[x][i].id]=find(y);
		}
	}
	for(int i=0;i<(int)ver[x].size();i++) {
		int y=ver[x][i];if(y==fa) continue;
		tarjan(y,x);
	}
	
	F[x]=fa;
}

int main() {
	for(int i=1;i<=n;i++) F[i]=i;
	for(int i=1;i<=q;i++) {
		int x,y;scanf("%d%d",&x,&y);
		Q[x].push_back(Node(y,i));
		Q[y].push_back(Node(x,i));
	}
	tarjan(1,1);
	
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}*/
/*
int fa[maxn],size[maxn],hson[maxn],dep[maxn];
inline void dfs1(int x,int Fa) {
	fa[x]=Fa;size[x]=1;int mxsize=0;
	for(int i=0;i<(int)ver[x].size();i++) {
		int y=ver[x][i];if(y==Fa) continue;
		dfs1(y,x);
		size[x]+=size[y];
		if(size[y]>mxsize) mxsize=size[y],hson[x]=y;
	}
}

int id[maxn],top[maxn],tot=0;
inline void dfs2(int x,int Top) {
	top[x]=Top;id[x]=++tot;
	if(hson[x]) dfs2(hson[x],Top);
	for(int i=0;i<(int)ver[x].size();i++) {
		int y=ver[x][i];
		if(y==hson[x]||y==fa[x]) continue;
		dfs(y,y);
	}
}

inline int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}*/
/*
1 5 4 3
3 5 4 1
3 1 4 5

*/
/*
deque<int> q;

push_front()
pop_front();
push_back()
pop_back();
q[33];

vector<int> v

push_back();
pop_back();
v[33]
lower_bound(v.begin(),v.end(),4);

stack,queue
top(),front()
push()
pop()
size()
empty()

priority_queue<int,vector<int>,greater<int> > q;
top()  max


set<int>
insert
erase
count 0/1
find(4)   s.end()
s.lower_bound(4);x
lower_bound(s.begin(),s.end(),4)  x

multiset<int>
s.erase(s.find(4))

map<int,double> mp;

set<pair<int,double> >

mp[5]=9;mp[5]=10;
*/
/*#include<bits/stdc++.h>
using namespace std;

int c[maxn];

inline int lowbit(int x) {
	return x&-x;
	return x^(x&(x-1));
}

inline void add(int x,int v) {
	for(;x<maxn;x+=lowbit(x)) c[x]+=v;
}

inline int query(int x) {
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=c[x];
	return ans;
}

inline int findpos(int k) {
	int nowlen=0,nowsum=0;
	for(int j=19;j>=0;j--) if(c[nowlen+(1<<j)]+nowsum<k) {
		nowsum+=c[nowlen+(1<<j)];
		nowlen+=(1<<j);
	}
	return nowlen+1;
}

int main() {
	
}*/
/*
unsigned 32 01



*/
/*
#define lson (x<<1)
#define rson (x<<1|1)
int sum[maxn<<2],addv[maxn<<2],mulv[maxn<<2];

inline void pushup(int x) {
	sum[x]=sum[lson]+sum[rson];
}

inline void build(int x,int l,int r) {
	mulv[x]=1;
	if(l==r) {
		sum[x]=a[x];
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(x);
}

inline void setadd(int x,int l,int r,int v) {
	addv[x]+=v;
	sum[x]+=(r-l+1)*v;
}

inline void setmul(int x,int l,int r,int v) {
	addv[x]*=v;sum[x]*=v;
}

inline void pushdown(int x,int l,int r) {
	int mid=(l+r)>>1;
	if(addv[x]) {
		setadd(lson,l,mid,addv[x]);
		setadd(rson,mid+1,r,addv[x]);
		addv[x]=0;
	}
	if(mulv[x]!=1) {
		setmul(lson,l,mid,mulv[x]);
		setmul(rson,mid+1,r,mulv[x]);
		mulv[x]=1;
	}
}

inline int query(int x,int l,int r,int ql,int qr) {
	if(ql<=l&&qr>=r) return sum[x];
	int mid=(l+r)>>1,ans=0;pushdown(x,l,r);
	if(ql<=mid) ans+=query(lson,l,mid,ql,qr);
	if(qr>mid) ans+=query(rson,mid+1,r,ql,qr);
	return ans;
}

inline void Add(int x,int l,int r,int ql,int qr,int v) {
	if(ql<=l&&qr>=r) setadd(x,l,r,v);
	int mid=(l+r)>>1;pushdown(x,l,r);
	if(ql<=mid) Add(lson,l,mid,ql,qr,v);
	if(qr>mid) Add(rson,mid+1,r,ql,qr,v);
	pushup(x);
}

inline void Mul(int x,int l,int r,int ql,int qr,int v) {
	if(ql<=l&&qr>=r) setmul(x,l,r,v);
	int mid=(l+r)>>1;pushdown(x,l,r);
	if(ql<=mid) Mul(lson,l,mid,ql,qr,v);
	if(qr>mid) Mul(rson,mid+1,r,ql,qr,v);
	pushup(x);
}
*/
/*
struct Node {
	int sum,ans,lmax,rmax;
}seg[maxn<<2];
inline Node Merge(Node a,Node b) {
	Node res;
	res.sum=a.sum+b.sum;
	res.ans=max(max(a.ans,b.ans),a.rmax+b.lmax);
	res.lmax=max(a.lmax,a.sum+b.lmax);
	res.rmax=max(b.rmax,b.sum+a.rmax);
	return res;
}

inline void pushup(int x) {
	seg[x]=Merge(seg[lson],seg[rson]);
}

inline Node query(int x,int l,int r,int ql,int qr) {
	if(ql<=l&&qr>=r) return seg[x];
	int mid=(l+r)>>1;
	if(qr<=mid) return query(lson,l,mid,ql,qr);
	if(ql>mid) return query(rson,mid+1,r,ql,qr);
	return Merge(query(lson,l,mid,ql,qr),query(rson,mid+1,r,ql,qr));
}

inline void modify(int x,int l,int r,int p,int v) {
	if(l==r) {
		seg[x].sum=v;
		seg[x].lmax=seg[x].rmax=seg[x].ans=max(v,0);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) modify(lson,l,mid,p,v);
	if(p>mid) modify(rson,mid+,1,p,v);
	pushup(x);
}*/


/*
int mxv[maxn<<2],sum[maxn<<2];

inline void Gao(int x,int l,int r,int ql,int qr) {
	if(mxv[x]<=1) return;
	if(l==r) {
		sum[x]=mxv[x]=floor(sqrt(mxv[x]));
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) Gao(lson,l,mid,ql,qr);
	if(qr>mid) Gao(rson,mid+1,r,ql,qr);
	pushup(x);
}
*/





