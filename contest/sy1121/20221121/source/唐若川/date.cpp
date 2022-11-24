#include <bits/stdc++.h>
using namespace std;
int n,m,w[1005][1005];
int main()
{
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	memset(w,0x3f3f3f3f,sizeof(w));
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		w[u][v]=1;
		w[v][u]=1;
		w[i][i]=0;
	}
	w[n][n]=0;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	scanf("%d",&m);
	while(m--)
	{
		int ans=0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=n;i++) {
			if(w[a][i]==w[b][i]) {
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

