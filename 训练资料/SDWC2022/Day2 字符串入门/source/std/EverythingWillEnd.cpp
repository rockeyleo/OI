#include<bits/stdc++.h>
using namespace std;
const int N=1000010;char t[N],s[N];int v[N],L[N],R[N];
int main()
{
	freopen("EverythingWillEnd.in","r",stdin),
	freopen("EverythingWillEnd.out","w",stdout);
	int n=0,m,ans=0;scanf("%s",t),m=(int)strlen(t);
	for(int i=0;i<m;i++) s[n++]='*',s[n++]=t[i];s[n++]='*';
	for(int mx=-1,i=0,p=0;i<n;i++)
	{
		if(mx>i) v[i]=min(mx-i+1,v[2*p-i]);else v[i]=1;
		for(;i+v[i]<n&&v[i]<=i&&s[i+v[i]]==s[i-v[i]];v[i]++);
		if(i+v[i]-1>mx) mx=i+v[i]-1,p=i;
		R[i-v[i]+1]=max(R[i-v[i]+1],v[i]-1);
		L[i+v[i]-1]=max(L[i+v[i]-1],v[i]-1);
	}
	for(int i=0;i<n;i+=2) R[i]=max(R[i],R[i-2]-2);
	for(int i=n-1;i>=0;i-=2) L[i]=max(L[i],L[i+2]-2);
	for(int i=0;i<n;i+=2) if(L[i]&&R[i]) ans=max(ans,L[i]+R[i]);
	return !printf("%d\n",ans);
}
