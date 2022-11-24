#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int head[M],to[M],nxt[M],cnt;
int scc,id[M],dfn[M],low[M],tme;
stack<int>stk; int instk[M];

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

int tarjan(int u){
	dfn[u] = low[u] = ++tme;
	instk[u] = 1; stk.push(u);
	for(int i=head[u];i;i=nxt[i]){
		int tt = to[i];
		if(!dfn[tt]){
			tarjan(tt);
			low[u] = min(low[u],low[tt]);
		}else if(instk[tt]){
			low[u] = min(low[u],dfn[tt]);
		}
	}
	if(dfn[u]==low[u]){
		scc++;
		int tmp;
		do{
			tmp = stk.top(); stk.pop();
			
		}while(tmp!=u);
	}
}

