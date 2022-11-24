#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5,LOGN=22,INF=0x3f3f3f3f3f3f3f3f;

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	return x;
}

struct Edge{
	int nxt,to;
}e[N<<1];
int h[N],cnt;

inline void adde(int u,int v)
{
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	h[u]=cnt;
}

int mn=INF,mx=0;
int n,m,depth[N],fa[N],rudu[N],lv[N],nol,to[N],val[N];
bool vis[N];

int dfs2(int u,int last)
{
	if(rudu[u]==0)
		return val[to[u]];
	int res;
	if(depth[u]&1)res=0;
	else res=INF;
	for(int i = h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==last)continue;
		int tmp=dfs2(v,u);
		if(depth[u]&1)
			res=max(res,tmp);
		else
			res=min(res,tmp);
	}
	return res;
}

void dfs1(int i)
{
	if(i==nol+1)
	{
		int res = dfs2(1,0);
		mx=max(res,mx);
		mn=min(res,mn);
		return;
	}
	for(int j=1;j<=nol;j++)
	{
		if(vis[j])continue;
		vis[j]=1;
		val[i]=j;
		dfs1(i+1);
		vis[j]=0;
	}
}

void dfs3(int u,int last,int dep)
{
	depth[u]=dep;
	for(int i = h[u];i;i=e[i].nxt)
		if(e[i].to!=last)
			dfs3(e[i].to,u,dep+1);
}

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	n=read();
	for(int i = 1;i<n;i++)
	{
		int u=read(),v=read();
		adde(u,v);
		adde(v,u);
		fa[v]=u;
		rudu[u]++;
	}
	for(int i = 1;i<=n;i++)
	{
		if(rudu[i]==0)
		{
			lv[++nol]=i;
			to[i]=nol;
		}
	}		
	dfs3(1,0,1);
	dfs1(1);
	printf("%lld %lld",mx,mn);

	return 0;
}
/*
5
1 2
1 3
2 4
2 5

*/