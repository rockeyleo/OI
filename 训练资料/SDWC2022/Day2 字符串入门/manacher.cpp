#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=50000010;char s[N],t[N];int r[N];
inline int manacher(char *s,int n,int p=0)
{
	rep(i,1,n)
	{
		if(i>p+r[p]) p=i;else r[i]=min(r[2*p-i],p+r[p]-i);
		while(i-r[i]>1&&i+r[i]<n&&s[i+r[i]+1]==s[i-r[i]-1]) r[i]++;
		if(i+r[i]>p+r[p]) p=i;
	}
	return 0;
}
int main()
{
	scanf("%s",s+1);int n=(int)strlen(s+1);
	rep(i,1,n) t[i*2-1]='*',t[i<<1]=s[i];
	int ans=0;t[n=2*n+1]='*',manacher(t,n);
	rep(i,1,n) ans=max(ans,r[i]);
	return !printf("%d\n",ans);
}
//566182279
