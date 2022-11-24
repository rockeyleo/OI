#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef pair<int,int> pii;
int dep[N],fat[N][23];
struct node{
	int to,nxt;
}e[N<<1];
int n,m;
int tot,cnt,maxdep,siz[N],dfn[N],h[N];
pii rrange[N];
inline void add(int u,int v){e[++tot].to=v,e[tot].nxt=h[u],h[u]=tot;}
void dfs(int u,int fa){
	siz[u]++;
	dfn[u]=++cnt;
	rrange[u].first=cnt;
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)continue;
		fat[v][0]=u;
		dep[v]=dep[u]+1;
		for(int j=1;j<=maxdep;j++)fat[v][j]=fat[fat[v][j-1]][j-1];
		dfs(v,u);
		siz[u]+=siz[v];
	}
	rrange[u].second=cnt;
}
inline int lca(int x,int y){
	for(int i=maxdep;~i;i--){
		if(dep[fat[x][i]]>=dep[y])x=fat[x][i];
	}
	if(x==y)return x;
	for(int i=maxdep;~i;i--){
		if(fat[x][i]!=fat[y][i])x=fat[x][i],y=fat[y][i];
	}
	return fat[x][0];
}
int Find(int x,int dis){
	int tmp=dep[x];
	for(int i=maxdep;~i;i--){
		if(tmp-dep[fat[x][i]]<=dis)x=fat[x][i];
	}
	return x;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	maxdep=__lg(n+1)+1;
	dep[1]=1;
	dfs(1,-1);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(x==y){
			printf("%d\n",n);
			continue;
		}
		if(dep[x]==dep[y]){
			int u=lca(x,y);
			int ans=n;
			for(int i=h[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(v==fat[u][0])continue;
				if(rrange[v].first<=dfn[x]&&rrange[v].second>=dfn[x])ans-=siz[v];
				else if(rrange[v].first<=dfn[y]&&rrange[v].second>=dfn[y])ans-=siz[v];
			}
			printf("%d\n",ans);
		}else{
			if(dep[x]<dep[y])swap(x,y);
			int ans=1;
			int u=lca(x,y);
			int dis=dep[x]+dep[y]-dep[u]*2;
			if(dis&1){
				puts("0");
				continue;
			}
			u=Find(x,dis>>1);
			for(int i=h[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(v==fat[u][0])continue;
				if(rrange[v].first<=dfn[x]&&rrange[v].second>=dfn[x])continue;
				ans+=siz[v];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
9
1 2
1 3
2 8
2 9
3 4
3 5
3 6
5 7
114514
*/
