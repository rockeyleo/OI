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
	scanf("%d%d",&n,&m);
	printf("%d\n",n/2*(n-n/2)-m);
	return 0;
}
