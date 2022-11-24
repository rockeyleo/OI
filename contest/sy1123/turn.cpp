#include<bits/stdc++.h>
#define MAXN 3000000
#define LL long long
using namespace std;
char s[MAXN+5];
int n,a[30];
LL ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=(LL)n*(LL)(n+1)/2ll;
	for (int i=1;i<=n;i++)
		a[s[i]-'a'+1]++;
	for (int i=1;i<=26;i++)
		ans-=(LL)a[i]*(LL)(a[i]+1)/2ll;
	cout<<ans+1<<endl;
	return 0;
}