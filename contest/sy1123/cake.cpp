#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
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
int n,v,c1,c2;
char s1[5],s2[5];
int indgr[5];
int mn[5][5],s[5][5],c[5][5],f[5];
int cnt,sum,ans;
bool flag;
int find(int x)
{
	if (x!=f[x])f[x]=find(f[x]);
	return f[x];
}
int main()
{
	scanf("%d",&n);
	memset(mn,0x3f,sizeof(mn));
	for (int i=1;i<=n;i++)
	{
		scanf("%d%s%s",&v,s1,s2);
		if (s1[0]=='X')c1=1;
		else if (s1[0]=='Y')c1=2;
		else if (s1[0]=='Z')c1=3;
		else if (s1[0]=='W')c1=4;
		if (s2[0]=='X')c2=1;
		else if (s2[0]=='Y')c2=2;
		else if (s2[0]=='Z')c2=3;
		else if (s2[0]=='W')c2=4;
		indgr[c1]++;indgr[c2]++;
		if (c1>c2)c1^=c2^=c1^=c2;
		mn[c1][c2]=min(mn[c1][c2],v);
		s[c1][c2]+=v;
		c[c1][c2]++;
	}
	for (int i=1;i<=4;i++)
		for (int j=i;j<=4;j++)
			sum+=s[i][j];
	for (int i=1;i<=4;i++)
		ans=max(ans,s[i][i]);
	for (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
			if (s[i][j])ans=max(ans,s[i][i]+s[j][j]+s[i][j]);
	for (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
			for (int k=j+1;k<=4;k++)
				if ((s[i][j]&&s[i][k])||(s[i][j]&&s[j][k])||(s[i][k]&&s[j][k]))
					ans=max(ans,s[i][i]+s[j][j]+s[k][k]+s[i][j]+s[i][k]+s[j][k]);
	for (int i=1;i<=4;i++)
		f[i]=i;
	for (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
			if (s[i][j])
			{
				if (find(i)!=find(j))
					f[find(i)]=find(j);
			}
	flag=1;
	for (int i=1;i<=4;i++)
		if (find(i)!=find(1))flag=0;
	if (flag)
	{
		for (int i=1;i<=4;i++)
			if (indgr[i]%2)cnt++;
		if (cnt<=2)ans=sum;
		else
		{
			if ((c[1][2]>1)||((c[1][3]||c[1][4])&&(c[2][3]||c[2][4])))ans=max(ans,sum-mn[1][2]);
			if ((c[1][3]>1)||((c[1][2]||c[1][4])&&(c[2][3]||c[3][4])))ans=max(ans,sum-mn[1][3]);
			if ((c[1][4]>1)||((c[1][2]||c[1][3])&&(c[2][4]||c[3][4])))ans=max(ans,sum-mn[1][4]);
			if ((c[2][3]>1)||((c[1][2]||c[2][4])&&(c[1][3]||c[3][4])))ans=max(ans,sum-mn[2][3]);
			if ((c[2][4]>1)||((c[1][2]||c[2][3])&&(c[1][4]||c[3][4])))ans=max(ans,sum-mn[2][4]);
			if ((c[3][4]>1)||((c[1][3]||c[2][3])&&(c[1][4]||c[2][4])))ans=max(ans,sum-mn[3][4]);
		}
	}
	printf("%d\n",ans);
	return 0;
}