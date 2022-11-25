#include <bits/stdc++.h>
using namespace std;
const int M = 50000;
int head[M],nxt[M],cnt,to[M],val[M];
int vis[M];
int color[3];
int n,m;
bool tag;

void add(int f,int t,int v){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	val[cnt] = v;
}

void dfs(int now,int co,int mid){
	if(tag==false)return;
	color[now] = co;
	for(int i=head[now];i;i=nxt[i]){
		if(val[i]<=mid)continue;
		int tt = to[i];
		if(color[tt]==-1){
			dfs(tt,co^1,mid);
		}
		else if(color[tt]==co){
			tag = false;
			return;
		}
	}
}

int main(){
	memset(color,-1,sizeof(color));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t,v;
		cin>>f>>t>>v;
		add(f,t,v);
		add(t,f,v);
	}
	int l = 0, r = 1000000000;
	while(l<=r){
		memset(color,-1,sizeof(color));
		int mid = (l+r)/2;
		tag = true;
		dfs(1,1,mid);
		if(tag){
			r = mid-1;
		}else{
			l = mid+1;
		}
//		cout<<l<<" "<<r<<endl;
	}
	cout<<l<<endl;
}
