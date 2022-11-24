#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
int head[M],nxt[M],to[M],cnt;
int tme,dfn[M],low[M];
int id[M],sz[M],scc,out[M];
int instk[M];
stack<int>stk;

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

void tarjan(int now){
//	cout<<now<<endl;
	dfn[now] = low[now] = ++tme;
	instk[now]=1;
	stk.push(now);
	for(int i = head[now];i;i=nxt[i]){
		int tt = to[i];
		if(!dfn[tt]){
			tarjan(tt);
			low[now] = min(dfn[now],low[tt]);
		}else if(instk[tt]){
			low[now] = min(dfn[now],dfn[tt]);
		}
	}
	if(dfn[now]==low[now]){
//		cout<<now<<endl;
		scc++;
		int tmp;
		do{
			tmp = stk.top();stk.pop();
			id[tmp] = scc;
			instk[tmp] = 0;
			sz[scc]++;
		}while(tmp!=now);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t;
		cin>>f>>t;
		add(f,t);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int now = 1;now<=n;now++){
		for(int i=head[now];i;i=nxt[i]){
			int tt = to[i];
			if(id[now]!=id[tt]){
				out[id[now]]++;
			}
		}
	}
	int ans = 0;
	int flag = 0;
	for(int i=1;i<=scc;i++){
		if(out[i]==0){
			if(flag==0){
				flag = 1;
				ans = sz[i];
			}else{
				ans = 0;
			}
		}
	}
	cout<<ans<<endl;
}
