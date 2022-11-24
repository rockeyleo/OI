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

int n,m,depth[N],du[N],fa[N][LOGN],son[N];

int dfs1(int u,int last,int dep)
{
	depth[u]=dep;
	fa[u][0]=last;
	for(int i=1;fa[u][i-1];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	int s=1;
	for(int i = h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==last)continue;
		s+=dfs1(v,u,dep+1);
	}
	return son[u]=s;
}

int LCA(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	int len=depth[x]-depth[y];
	for(int i = 0;i<LOGN-3;i++)
		if(len&(1<<i))
			x=fa[x][i];
	if(x==y)return x;
	for(int i = LOGN-4;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int getdis(int x,int y)
{
	return depth[x]+depth[y]-(depth[LCA(x,y)]<<1);
}

void solve1()
{
	for(int i = 1;i<=m;i++)
	{
		int x=read(),y=read(),ans=0;
		if(getdis(x,y)&1)
		{
			printf("%lld\n",ans);
			continue;
		}
		for(int j = 1;j<=n;j++)
			if(getdis(x,j)==getdis(y,j))
				ans++;
		printf("%lld\n",ans);
	}
}
void solve2()
{
	for(int i = 1;i<=m;i++)
		printf("%d\n",!(getdis(read(),read())&1));
}

int ans;

int jump(int x,int len)
{
	int sx=x;
	for(int i = LOGN-4;i>=0;i--)
		if(getdis(sx,fa[x][i])<len)
			x=fa[x][i];
	ans-=son[x];
	return fa[x][0];
}

void solve3()
{
	for(int i = 1;i<=m;i++)
	{
		ans=0;
		int x=read(),y=read();
		int len=getdis(x,y);
		if(len&1)
		{
			printf("%d\n",0);
			continue;
		}
		if(depth[x]<depth[y])swap(x,y);
		int lca=LCA(x,y);
		if(y!=lca&&LCA(y,lca)==lca)
		{
			ans+=n-son[lca];
			jump(y,len>>1);
		}
		else if(depth[x]==depth[y])
			jump(y,len>>1);
		ans+=son[jump(x,len>>1)];
			
		printf("%lld\n",ans);
	}
}

signed main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);

	bool flag=1;
	n=read();
	for(int i = 1;i<n;i++)
	{
		int u=read(),v=read();
		adde(u,v);
		adde(v,u);
		du[u]++,du[v]++;
		if(du[u]>2||du[v]>2)
			flag=0;
	}
	m=read();
	dfs1(1,0,1);
	if(n<=1000)solve1();
	else if(flag)solve2();
	else solve3();

	return 0;
}

/*
7
1 2
1 3
2 4
1 5
5 6
5 7
100
2 3
*/