#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1000010;char S[N],T[N],s[N];int nxt[N],a[N],t,n;
inline int KMP(char *s,int n,int f=0)
{
	rep(i,2,n)
	{
		while(f&&s[i]!=s[f+1]) f=nxt[f];
		if(s[i]==s[f+1]) ++f;nxt[i]=f;
	}
	return 0;
}
int main()
{
	freopen("TheRemaining.in","r",stdin),
	freopen("TheRemaining.out","w",stdout);
	scanf("%s%s",S+1,T+1),n=(int)strlen(T+1),KMP(T,n);
	for(int i=1,f;S[i];i++)
	{
		s[++t]=S[i],f=a[t-1];
		while(f&&T[f+1]!=s[t]) f=nxt[f];
		if(T[f+1]==s[t]) ++f;a[t]=f;
		if(a[t]==n) t-=n;
	}
	return s[t+1]=0,!printf("%s\n",s+1);
}
