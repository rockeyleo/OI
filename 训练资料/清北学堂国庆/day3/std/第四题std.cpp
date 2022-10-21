#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
const int N=3010;
long long f[N][N];
int a[N],b[N],pre[N];
int main() {
	int i,n,m,j,k,p;char c;long long Q;
	while ((c=getchar())<'1'||'9'<c);
	a[n=1]=c-'0';
	while ('1'<=(c=getchar())&&c<='9') a[++n]=c-'0';
	while ((c=getchar())<'1'||'9'<c);
	b[m=1]=c-'0';
	while ('1'<=(c=getchar())&&c<='9') b[++m]=c-'0';
	f[n+1][m+1]=1;
	cin>>Q;

	for (j=m;j;j--) f[n+1][j]=min(f[n+1][j+1]*9,Q+1);
	for (i=n;i;i--)
		for (j=m;j;j--)
			f[i][j]=min(f[i][j+1]*8+f[i+1][j+1],Q+1);
	for (i=1;i<=m;i++) pre[i]=pre[i-1]+(b[i]==a[pre[i-1]+1]);
	for (j=m;j;j--) {
		for (k=b[j]+1;k<=9;k++)
			if (Q<=f[pre[j-1]+(k==a[pre[j-1]+1])+1][j+1]) {
				for (i=1;i<j;i++) printf("%d",b[i]);printf("%d",k);
				p=pre[j-1]+(k==a[pre[j-1]+1]);
				for (++j;j<=m;j++,p+=k==a[p+1])
					for (k=1;k<=9;k++)
						if (Q<=f[p+(k==a[p+1])+1][j+1]) {
							printf("%d",k);
							break;
						}
						else Q-=f[p+(k==a[p+1])+1][j+1];
				return 0;
			}
			else Q-=f[pre[j-1]+(k==a[pre[j-1]+1])+1][j+1];
	}
}
