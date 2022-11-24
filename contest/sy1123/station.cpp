#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#define MAXN 50005
#define MAXM 200005
#define MOD 19260817
#define STEP 233
#define LL long long
using namespace std;
inline int read()
{
	int num=0,sgn=1;
	char ch=getchar();
	while (ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if (ch=='-')sgn=-1,ch=getchar();
	while (ch>='0'&&ch<='9')num*=10,num+=ch-'0',ch=getchar();
	return num*sgn;
}
int n,m,r[MAXN];
int u[MAXM],v[MAXM],d[MAXN];
int hash[MOD],mx1[MOD],mx2[MOD],id1[MOD],id2[MOD];
int ans;
vector<int>g[MAXN];
vector<int>lar,lit;
int calc(int u,int v)
{return ((LL)u*u+v)%MOD;}
int find(int p,int q)
{
	if (p>q)p^=q^=p^=q;
	int id=calc(p,q);
	while (hash[id]&&(u[hash[id]]!=p||v[hash[id]]!=q))
		id+=STEP,id%=MOD;
	return hash[id];
}
int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++)
		r[i]=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read();v[i]=read();
		if (u[i]>v[i])u[i]^=v[i]^=u[i]^=v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
		d[u[i]]++;d[v[i]]++;
		int id=calc(u[i],v[i]);
		while (hash[id])id+=STEP,id%=MOD;
		hash[id]=i;
	}
	for (int i=1;i<=n;i++)
		if (d[i]*d[i]>=m)lar.push_back(i);
		else lit.push_back(i);
	for (int i=0;i<lar.size();i++)
		for (int j=i+1;j<lar.size();j++)
			for (int k=j+1;k<lar.size();k++)
			{
				int a=find(lar[i],lar[j]);
				if (!a)continue;
				int b=find(lar[i],lar[k]);
				if (!b)continue;
				int c=find(lar[j],lar[k]);
				if (!c)continue;
				if (id1[a]!=lar[k])
				{
					if (r[lar[k]]>=mx1[a])mx2[a]=mx1[a],id2[a]=id1[a],mx1[a]=r[lar[k]],id1[a]=lar[k];
					else if (r[lar[k]]>mx2[a])mx2[a]=r[lar[k]],id2[a]=lar[k];
				}
				if (id1[b]!=lar[j])
				{
					if (r[lar[j]]>=mx1[b])mx2[b]=mx1[b],id2[b]=id1[b],mx1[b]=r[lar[j]],id1[b]=lar[j];
					else if (r[lar[j]]>mx2[b])mx2[b]=r[lar[j]],id2[b]=lar[j];
				}
				if (id1[c]!=lar[i])
				{
					if (r[lar[i]]>=mx1[c])mx2[c]=mx1[c],id2[c]=id1[c],mx1[c]=r[lar[i]],id1[c]=lar[i];
					else if (r[lar[i]]>mx2[c])mx2[c]=r[lar[i]],id2[c]=lar[i];
				}
			}
	for (int i=0;i<lit.size();i++)
		for (int j=0;j<g[lit[i]].size();j++)
			for (int k=j+1;k<g[lit[i]].size();k++)
			{
				int e=find(g[lit[i]][j],g[lit[i]][k]);
				if (!e)continue;
				int x=find(lit[i],g[lit[i]][j]),y=find(lit[i],g[lit[i]][k]);
				if (id1[e]!=lit[i])
				{
					if (r[lit[i]]>=mx1[e])mx2[e]=mx1[e],id2[e]=id1[e],mx1[e]=r[lit[i]],id1[e]=lit[i];
					else if (r[lit[i]]>mx2[e])mx2[e]=r[lit[i]],id2[e]=lit[i];
				}
				if (id1[x]!=g[lit[i]][k])
				{
					if (r[g[lit[i]][k]]>=mx1[x])mx2[x]=mx1[x],id2[x]=id1[x],mx1[x]=r[g[lit[i]][k]],id1[x]=g[lit[i]][k];
					else if (r[g[lit[i]][k]]>mx2[x])mx2[x]=r[g[lit[i]][k]],id2[x]=g[lit[i]][k];
				}
				if (id1[y]!=g[lit[i]][j])
				{
					if (r[g[lit[i]][j]]>=mx1[y])mx2[y]=mx1[y],id2[y]=id1[y],mx1[y]=r[g[lit[i]][j]],id1[y]=g[lit[i]][j];
					else if (r[g[lit[i]][j]]>mx2[y])mx2[y]=r[g[lit[i]][j]],id2[y]=g[lit[i]][j];
				}
			}
	for (int i=1;i<=m;i++)
	{
		int id=find(u[i],v[i]);
		if (id1[id]&&id2[id])ans=max(ans,(r[u[i]]+1)*(r[v[i]]+1)+mx1[id]*mx2[id]);
	}
	printf("%d\n",ans);
	return 0;
}