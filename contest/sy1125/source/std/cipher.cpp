#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define MAXN 200005
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
struct node
{
	int l,r;
	int f[2];
}t[10][MAXN*4];
int n,m,type,x,id,ans;
int op[MAXN],a[MAXN],b[MAXN];
char str[5];
void build(int l,int r,int k,int bit)
{
	t[bit][k].l=l;
	t[bit][k].r=r;
	if (l==r)
	{
		if (op[l]==1)t[bit][k].f[0]=0,t[bit][k].f[1]=a[l];
		if (op[l]==2)t[bit][k].f[0]=a[l],t[bit][k].f[1]=1;
		if (op[l]==3)t[bit][k].f[0]=a[l],t[bit][k].f[1]=(a[l]^1);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1,bit);
	build(mid+1,r,k<<1|1,bit);
	t[bit][k].f[0]=t[bit][k<<1|1].f[t[bit][k<<1].f[0]];
	t[bit][k].f[1]=t[bit][k<<1|1].f[t[bit][k<<1].f[1]];
}
void update(int u,int v,int k,int bit)
{
	if (t[bit][k].l==t[bit][k].r)
	{
		if (op[u]==1)t[bit][k].f[0]=0,t[bit][k].f[1]=v;
		if (op[u]==2)t[bit][k].f[0]=v,t[bit][k].f[1]=1;
		if (op[u]==3)t[bit][k].f[0]=v,t[bit][k].f[1]=(v^1);
		return;
	}
	int mid=(t[bit][k].l+t[bit][k].r)>>1;
	if (u<=mid)update(u,v,k<<1,bit);
	else update(u,v,k<<1|1,bit);
	t[bit][k].f[0]=t[bit][k<<1|1].f[t[bit][k<<1].f[0]];
	t[bit][k].f[1]=t[bit][k<<1|1].f[t[bit][k<<1].f[1]];
}
int main()
{
	freopen("cipher.in","r",stdin);
	freopen("cipher.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s%d",str+1,&b[i]);
		if (!strcmp(str+1,"AND"))op[i]=1;
		if (!strcmp(str+1,"OR"))op[i]=2;
		if (!strcmp(str+1,"XOR"))op[i]=3;
	}
	for (int j=0;j<10;j++)
	{
		for (int i=1;i<=n;i++)
			a[i]=(b[i]&(1<<j))?1:0;
		build(1,n,1,j);
	}
	while (m--)
	{
		scanf("%d",&type);
		if (type==1)
		{
			scanf("%d",&x);
			ans=0;
			for (int i=0;i<10;i++)
				ans|=((t[i][1].f[(x&(1<<i))?1:0])<<i);
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d%s%d",&id,str+1,&x);
			if (!strcmp(str+1,"AND"))op[id]=1;
			if (!strcmp(str+1,"OR"))op[id]=2;
			if (!strcmp(str+1,"XOR"))op[id]=3;
			for (int i=0;i<10;i++)
				update(id,(x&(1<<i))?1:0,1,i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
