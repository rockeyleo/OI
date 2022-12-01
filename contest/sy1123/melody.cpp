#include<bits/stdc++.h>
#define MAXN 3000
using namespace std;
int n,m,a,b,x,y;
int nxt[MAXN+5],ans;
char s[MAXN+5],t[MAXN+5];
vector<int>d[MAXN+5];
void init()
{
	for (int i=2;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			d[j].push_back(i);
}
int main()
{
	scanf("%d%d%s",&a,&b,s+1);
	n=strlen(s+1);
	init();
	for (int st=1;st<=n;st++)
	{
		m=n-st+1;
		for (int i=1;i<=m;i++)
			t[i]=s[st+i-1];
		memset(nxt,0,sizeof(nxt));
		for (int i=1;i<m;i++)
		{
			int j=nxt[i];
			while (j&&(t[j+1]!=t[i+1]))j=nxt[j];
			nxt[i+1]=(t[j+1]==t[i+1])?(j+1):0;
		}
		for (int i=1;i<=m;i++)
		{
			x=i-nxt[i];y=i/x;
			if ((i%x)||(y==1))continue;
			for (int j=0;j<d[y].size();j++)
			{
				int k=i/d[y][j];
				ans=max(ans,a*k+b*d[y][j]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}