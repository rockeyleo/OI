#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 50010;
int head[N],nxt[M],to[M],cnt;
int dfn[N],low[N],tme;
bool instk[N];
int id[N],scc,Size[N];
int out[N];
stack<int> stk;

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

void tarjan(int u){
	dfn[u] = low[u] = ++tme;
	stk.push(u), instk[u] = true;
	for(int i = head[u];i;i=nxt[i]){
		int tt = to[i];
		if(!dfn[tt]){
			tarjan(tt);
			low[u] = min(low[u],low[tt]);
		}
		else if(instk[tt])low[u] = min(low[u],dfn[tt]);
	}
	if(dfn[u] == low[u]){
		scc++;
		int tmp;
		do{
			tmp = stk.top(); stk.pop();
			instk[tmp] = false;
			id[tmp] = scc;
			Size[scc]++;
		}while(tmp!=u);
	}
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int f,t;
		cin>>f>>t;
		add(f,t);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int now=1;now<=n;now++){
		for(int i = head[now];i;i = nxt[i]){
//			cout<<to[i]<<endl;
			int tt = to[i];
//			cout<<tt<<endl;
			int a = id[now], b = id[tt];
//			cout<<now<<" "<<id[now]<<" "<<tt<<" "<<id[tt]<<endl;
			if(a!=b){
				out[a]++;
//				cout<<out[id[now]]<<endl;
			}
		}
	}
//	cout<<scc<<endl;
	int outcnt = 0, ans = 0;
	for(int i=1;i<=scc;i++){
//		cout<<i<<" "<<out[i]<<endl;
		if(out[i]==0){
			outcnt++; ans = Size[i];
			if(outcnt>=2){
				cout<<"0"<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
