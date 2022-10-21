#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;const int N=1000010;
char s[N],t[N];int nxt[N],pos[N];
inline int getnxt(char *s,int m,int *nxt)//nxt[i]就是前缀i的Lborder长度。 
{
	nxt[1]=0;
	rep(i,2,m)
	{
		int &j=nxt[i];j=nxt[i-1];
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
	}
	return 0;
}
inline int KMP(char *t,int n,char *s,int m,int *nxt,int *pos)
{
	int k=0;
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&s[j+1]!=t[i]) j=nxt[j];
		if(j<m&&s[j+1]==t[i]) j++;
		if(j==m) pos[++k]=i-m+1,j=nxt[j];
	}
	return k;
}
int main()
{
	scanf("%s",t+1);int n=(int)strlen(t+1);
	scanf("%s",s+1);int m=(int)strlen(s+1);
	getnxt(s,m,nxt);int k=KMP(t,n,s,m,nxt,pos);
	rep(i,1,k) printf("%d\n",pos[i]);
	rep(i,1,m) printf("%d ",nxt[i]);
	return !printf("\n");
}
