#include <cctype>
#include <cstdio>
constexpr int N=1e5+1;
bool f;
char c;
int i,n,m,u,v,t,ans,d[N],sz[N],fa[N],son[N],dep[N],top[N];
struct G{
	int t,h[N],v[N<<1],nxt[N<<1];
	void add_edge(int ui,int vi){
		v[++t]=vi;
		nxt[t]=h[ui];
		h[ui]=t;
	}
}g;
inline void swap(int &a,int &b){t=a,a=b,b=t;}
inline void qscan(int &x){
	x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
}
void dfs1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=g.h[u];i;i=g.nxt[i]){
		int v=g.v[i];
		if(sz[v])continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v; 
	}
}
void dfs2(int u,int t){
	top[u]=t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i=g.h[u];i;i=g.nxt[i]){
		int v=g.v[i];
		if(v!=fa[u]&&v!=son[u])dfs2(v,v); 
	}
}
int lca(int x,int y){
	for(;top[x]!=top[y];x=fa[top[x]])
		if(dep[top[x]]<dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	qscan(n);
	for(i=1;i<n;++i){
		qscan(u),qscan(v);
		g.add_edge(u,v),g.add_edge(v,u);
		++d[u],++d[v];
	}
	for(i=1;i<=n;++i)
		if(d[i]>2){
			f=true;
			break;
		}
	dfs1(1),dfs2(1,1);
	qscan(m);
	if(f)
		while(m--){
			qscan(u),qscan(v);
			if(dep[u]+dep[v]-(dep[lca(u,v)]<<1)&1)putchar(48),putchar(10);
			else{
				for(ans=0,i=1;i<=n;++i)if(dep[u]-(dep[lca(u,i)]<<1)==dep[v]-(dep[lca(v,i)]<<1))++ans;
				printf("%d\n",ans);
			}
		}
	else
		while(m--){
			qscan(u),qscan(v);
			printf("%d\n",dep[u]+dep[v]-(dep[lca(u,v)]<<1)&1^1);
		}
}
