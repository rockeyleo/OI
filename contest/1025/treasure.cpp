#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M = 1000100;
struct node{
	int f,t,val;
}edge[M];
int head[M],to[M],val[M],nxt[M],cnt2,point[50],vis[50];
int cnt;
int fa[50];
queue<int>q;

void add2(int f,int t,int v){
	edge[++cnt2].f = f;
	edge[cnt2].t = t;
	edge[cnt2].val = v;
}

void bfs(int a){
	cnt2 = 0;
	memset(vis,0,sizeof(vis));
	memset(point,0,sizeof(vis));
	q.push(a);
	point[a]=1; vis[a] = 1;
	while(!q.empty()){
		int now = q.front();q.pop();
		for(int i=head[now];i;i=nxt[i]){
			int tt = to[i];
			if(!vis[tt]){
				vis[tt] = 1;
				point[tt]=point[now]+1;
//				cout<<tt<<" "<<point[tt]<<endl;
				q.push(tt);
				add2(now,tt,val[i]*point[now]);
				add2(tt,now,val[i]*point[tt]);
//				cout<<now<<" "<<tt<<" "<<val[i]<<" "<<point[now]<<endl;
//				cout<<tt<<" "<<now<<" "<<val[i]<<" "<<point[tt]<<endl;
			}
		}
	}
}

void add(int f,int t,int v){
	val[++cnt] = v;
	to[cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

int find(int a){
	if(fa[a] == a)return a;
	return(fa[a] = find(fa[a]));
}

int krus(){
	int an = 0;
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	sort(edge+1,edge+1+m,[](node a,node b){return a.val<b.val;});
	for(int i=1;i<=cnt2;i++){
		int f = find(edge[i].f);
		int t = find(edge[i].t);
		for(int i=1;i<=m;i++){
//   			cout<<edge[i].f<<" "<<edge[i].t<<" "<<edge[i].val<<endl;
		}
		if(f!=t){

			an += edge[i].val;
			fa[f]=t;
		}
	}
//	cout<<an<<endl;
	return an;
}

int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t,v;
		cin>>f>>t>>v;
		add(f,t,v);
		add(t,f,v);
	}
	int ans = 0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		bfs(i);
//		cout<<endl;
		ans = min(ans,krus());
	}
	cout<<ans<<endl;
}
