#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200002],cnt,fa[200002],siz[200002],mn,pos;
ll ans;
struct edge{int to,next,w;}e[200002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void add(re int x,re int y,re int w){e[++cnt]=(edge){y,head[x],w},head[x]=cnt;}
struct Edge{
	int x,y,z1,z2;
	bool operator <(const Edge A)const{return z1<A.z1;}
}E[200002];
inline void dfs(re int x,re int y){
	siz[x]=1;re int mx=0;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x),mx=max(mx,siz[e[i].to]),siz[x]+=siz[e[i].to];
	mx=max(mx,n-siz[x]);
	if(mx<mn)mn=mx,pos=x;
}
inline void dfs1(re int x,re int y,re ll z){
	ans+=z;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs1(e[i].to,x,z+e[i].w);
}
int main(){
	n=read(),m=read(),mn=1e9;
	for(re int i=1;i<=n;++i)fa[i]=i;
	for(re int i=1;i<=m;++i)E[i].x=read(),E[i].y=read(),E[i].z1=read(),E[i].z2=read();
	sort(E+1,E+m+1);
	for(re int i=1;i<=m;++i)if(root(E[i].x)^root(E[i].y))add(E[i].x,E[i].y,E[i].z2),add(E[i].y,E[i].x,E[i].z2),fa[root(E[i].x)]=root(E[i].y);
	dfs(1,1),dfs1(pos,pos,0),printf("%lld",ans*2);
}
