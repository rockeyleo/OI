#inlcude <bits/stdc++.h>
using namespace std;
const int M = 500010;
int head[M],nxt[M],to[M],cnt;
int mindep = 0x3f3f3f3f;
int vis[M];
struct node{
	int name,dep,fa;
};
queue q<node>;

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

void bfs(int s){
	q.push({s,0,-1});
	while(q.empty()){
		auto pll = q.top();q.push();
		int u = pll.name, dep = pll.dep, fa = pll.fa;
		vis[u] = 1;
		int flag = 0;
		for(int i=head[u];i;i=nxt[i]){
			int tt = to[i];
			if(tt==fa)continue;
			if(vis[tt]){
				flag = 1;
				mindep = min()
			} 
		}
		if(flag)return;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t	;
		scanf("%d,%d",&f,&t);
		add(f,t);
		add(t,f);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
}
