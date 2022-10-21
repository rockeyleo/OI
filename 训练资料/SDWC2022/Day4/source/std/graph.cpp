#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[20005];
int n,m,edgenum,head[5005],flag[5005],a[5005],b[5005],num,cnt[2];
bool f[5005][5005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	cnt[flag[node]]++;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[to]==-1)
		{
			flag[to]=flag[node]^1;
			dfs(to);
		}
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	memset(flag,-1,sizeof(flag));
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==-1)
		{
			flag[i]=0;
			cnt[0]=cnt[1]=0;
			dfs(i);
			a[++num]=cnt[0],b[num]=cnt[1];
		}
	}
	f[0][0]=1;
	for(int i=1;i<=num;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j>=a[i])f[i][j]|=f[i-1][j-a[i]];
			if(j>=b[i])f[i][j]|=f[i-1][j-b[i]];
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(f[num][i])
			ans=max(ans,i*(n-i));
	}
	printf("%d\n",ans-m);
	return 0;
}
