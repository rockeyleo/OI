#include <bits/stdc++.h>
using namespace std;
int up[10001],down[10001],dp[10001][2001],flag[10001];

int read(){
	char ch = getchar(); int ret=0; int f=1;
	while(ch<'0' or ch>'9'){if(ch=='-'){f=-1;}ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch=getchar();}
	return ret*f;
}

int main(){
	freopen("P1941_8.in","r",stdin);
	freopen("P1941_8.out.std","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=n-1;i++){
		up[i] = read(); down[i] = read();
		//scanf("%d %d",&up[i],&down[i]);
		//cin>>up[i]>>down[i];
	}
	for(int i=1;i<=k;i++){
		int p,l,h;
		p = read(); l = read(); h = read();
		//scanf("%d %d %d",&p,&l,&h);
		//cin>>p>>l>>h;
		flag[p]=1;
		for(int j=1;j<=l;j++){
			dp[p][j] = -1;
		}
		for(int j=h;j<=m;j++){
			dp[p][j] = -1;
		}
	}
	for(int i=1;i<=n;i++){
		flag[i]+=flag[i-1];
	}
	for(int j=1;j<=m;j++){
		dp[0][j] = 0;
	}
	for(int x=0;x<n;x++){
		for(int y=1;y<=m;y++){
			if(dp[x][y]==-1){
                dp[x][y] = 0x3f3f3f3f;
			    continue;
			}
			if(y+up[x]>m and dp[x+1][m]!=-1)dp[x+1][m]=min(dp[x+1][m],dp[x][y]+1);
			for(int q=1;y+q*up[x]<=m;q++){
				if(dp[x+1][y+q*up[x]]!=-1)dp[x+1][y+q*up[x]] = min(dp[x+1][y+q*up[x]],dp[x][y]+q);
				if(dp[x+1][m]!=-1 and y+(q+1)*up[x]>m)dp[x+1][m] = min(dp[x+1][m],dp[x][y]+q+1);
			}
			if(dp[x+1][y-down[x]]!=-1)dp[x+1][y-down[x]] = min(dp[x+1][y-down[x]],dp[x][y]);
		}
		int cnt = 0;
		for(int b=1;b<=m;b++){
		    if(dp[x+1][b]==-1 or dp[x+1][b]==0x3f3f3f3f)cnt++;
		}
		//if(cnt==m){cout<<"0\n"<<flag[x]<<endl;return 0;}
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
//dp[x+1][y+


				//if(y<m){
					//if(y+down[x-1]<=m){dp[x][y] = min({dp[x][y],dp[x-1][y+down[x-1]],dp[x-1][y-q*up[x-1]]+q});}
					//else{dp[x][y] = min(dp[x][y],dp[x-1][y-q*up[x-1]]+q);}
				//}else{
					//dp[x][y] = min({dp[x][y],dp[x-1][m]+1,dp[x-1][y-q*up[x-1]]+q});
				//}
