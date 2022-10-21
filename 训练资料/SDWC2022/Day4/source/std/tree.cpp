#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,pa[1005],minn[1005],maxx[1005];
int a[1005][1005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&minn[i],&maxx[i]);
		if(!a[i][minn[i]])
		{
			if(find(i)==find(minn[i]))
			{
				printf("-1\n");
				return 0;
			}
			pa[find(i)]=find(minn[i]);
			a[i][minn[i]]=a[minn[i]][i]=1;
		}
		if(!a[i][maxx[i]])
		{
			if(find(i)==find(maxx[i]))
			{
				printf("-1\n");
				return 0;
			}
			pa[find(i)]=find(maxx[i]);
			a[i][maxx[i]]=a[maxx[i]][i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=minn[i];j<=maxx[i];j++)
		{
			if(i<minn[j]||i>maxx[j])continue;
			if(find(i)!=find(j))
			{
				a[i][j]=a[j][i]=1;
				pa[find(i)]=find(j);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(find(i)!=find(1))
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    if(a[i][j])printf("%d %d\n",i,j);
	return 0;
}
