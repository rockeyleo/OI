#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int dis[M];
int to[M],head[M],val[M],nxt[M],vis[M],cnt;    //用于前向星存边
struct nd{
	int dis,name;    //表示到点[name]的距离为[dis]
	friend bool operator<(nd a,nd b){return a.dis>b.dis;}   //注意小根堆重载为大于号
}tmp;
priority_queue<nd>pq;
void add(int f,int t,int v){
	val[++cnt] = v;
	nxt[cnt] = head[f];
	head[f] = cnt;
	to[cnt] = t;
}
void dij(){
	while(!pq.empty()){
		int cur = pq.top().name; pq.pop();
		if(vis[cur])continue;
		vis[cur]=1;
		for(int i=head[cur];i;i=nxt[i]){
			int now = to[i];
			if(dis[now]>dis[cur]+val[i]){
				dis[now] = dis[cur]+val[i];
				tmp.name = now; tmp.dis = dis[now];
				pq.push(tmp);
			}
		}
	}
}
int main(){
	int n,m,s;    //s表示起点编号
	cin>>m>>n>>s;
	for(int i=1;i<=n;i++){
		int f,t,v;
		cin>>f>>t>>v;
		add(f,t,v);
	}
	memset(dis,0x3f,sizeof(dis));    //用一个最大值来初始化dis数组
	dis[s] = 0;
	tmp.name = s; tmp.dis = 0; pq.push(tmp);
	dij();
	for(int i=1;i<=m;i++){
		cout<<dis[i]<<" ";
	}
}