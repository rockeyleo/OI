#include <bits/stdc++.h>
using namespace std;

const int N = 20010, M = N*2;

int n,m;
int h[N],e[M],ne[M],idx;
int p[N];
int res[N];
int dist[N];
int vis[N];
vector<pair<int,int>>query[N];

void add(int f,int t,int v){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j = e[i];
		if(j==fa)continue;
		dist[j] = dist[u]+w[i];
		dfs(j,u);
	}
}

int find(int x){
	if(p[x] == x)return x;
	return(p[x] = find(p[x]));
}

void tarjan(int u){
	st[u] = 1;
	for(int i=h[u];~i;i=ne[i]){
		int j = e[i];
		if(!st[j]){
			tarjan(j);
			p[j] = u;
		}
	}
	for(auto item:query[u]){
		int y = item.first, id = item.second;
		if(st[y]==2){
			int anc = find(y);
			res[id] = dist[u]+dist[y]-dist[anc]*2;
		}
	}
	st[u] = 2;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int f,t,v;
		cin>>f>>t>>v;
		add(f,t,v);
		add(t,f,v);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(a!=b){
			query[a].push_back({b,i});
			query[b].push_back({a,i});
		}
	}
	for(int i=1;i<=n;i++)p[i] = i;
	dfs(1,-1);
	tarjan(1);
	for(int i=1;i<=m;i++){
		cout<<res[i]<<endl;
	}
} 
