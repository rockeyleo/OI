#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> e[100010];
ll deep[100010];
ll n,x,y,m;
void dfs(int x,int fa){
	for(int i=0;i<e[x].size();i++){
		ll to=e[x][i];
		deep[to]=deep[x]+1;
		if(fa!=to)dfs(to,x);
	}
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	deep[1]=1;
	dfs(1,0);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(abs(deep[x]-deep[y])&1){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
