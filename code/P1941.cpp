#include <bits/stdc++.h>
using namespace std;
int up[10001],down[10001],dp[10001][3001],flag[10001],hh[10001],ll[10001];
queue<int>q;
int main(){
	freopen("P1941_8.in","r",stdin);
	freopen("P1941_8.out.std","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=n-1;i++){
		cin>>up[i]>>down[i];
	}
	for(int i=1;i<=n;i++){
		ll[i]=0; hh[i]=m+1;
	}
	for(int i=1;i<=k;i++){
		int p;
		cin>>p;
		cin>>ll[p]>>hh[p];
		flag[p]=1;
	}
	for(int i=1;i<=n;i++){
		flag[i]+=flag[i-1];
	}
	for(int j=1;j<=m;j++){
		dp[0][j] = 0;
	}

	for(int x=1;x<=n;x++){
		for(int y=1+up[x-1];y<=m+up[x-1];y++){
			dp[x][y] = min(dp[x-1][y-up[x-1]]+1,dp[x][y-up[x-1]]+1);
		}
		for(int y=m+1;y<=m+up[x-1];y++){
			dp[x][m] = min(dp[x][m],dp[x][y]);
		}
		for(int y=1;y<=m-down[x-1];y++){
			dp[x][y] = min(dp[x][y],dp[x-1][y+down[x-1]]);
		}
		for(int j=1;j<=ll[x];j++){
			dp[x][j]=0x3f3f3f3f;
		}
		for(int j=hh[x];j<=m;j++){
			dp[x][j]=0x3f3f3f3f;
		}
		int cnt = 0;
		for(int b=1;b<=m;b++){
			//cout<<x<<" "<<b<<" "<<dp[x][b]<<endl;
		    if(dp[x][b]>=0x3f3f3f3f)cnt++;
		}
		//cout<<cnt<<endl;
		//if(cnt==m){cout<<"0\n"<<flag[x-1]<<endl;return 0;}
	}
	int ans = 0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		ans = min(ans,dp[n][i]);
	}
	//cout<<"1\n"<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
}


				//if(y<m){
					//if(y+down[x-1]<=m){dp[x][y] = min({dp[x][y],dp[x-1][y+down[x-1]],dp[x-1][y-q*up[x-1]]+q});}
					//else{dp[x][y] = min(dp[x][y],dp[x-1][y-q*up[x-1]]+q);}
				//}else{
					//dp[x][y] = min({dp[x][y],dp[x-1][m]+1,dp[x-1][y-q*up[x-1]]+q});
				//}
