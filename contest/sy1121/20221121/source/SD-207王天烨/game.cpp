#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;
const int N=1e5+3;
constexpr int INF=0x3f3f3f3f;
int n;
int maxans=0,minans=INF;
struct Edge{
	int next;
	int to;
}edge[N];
int head[N],num_edge=0;
inline void add_edge(int from,int top){
	edge[++num_edge]=(Edge){head[from],top};
	head[from]=num_edge;
}
int son[N],m;
vector<int>lea;
void dfs1(int p){
	for(int i=head[p];i;i=edge[i].next){
		int v=edge[i].to;
		son[p]++;
		dfs1(v);
	}
	if(!son[p]) lea.push_back(p);
	return;
}
int val[N];
struct node{
	int val;
	int num;
}maxx[N],minn[N];
bool vis[N];
inline void initt(){
	for(int i=1;i<=n;i++){
		maxx[i].val=0;
		minn[i].val=INF;
		maxx[i].num=minn[i].num=0;
	}
}
int dfs2(int p,bool type){
	if(!son[p]){
		return val[p];
	}
	int res=type?0:INF;
	for(int i=head[p];i;i=edge[i].next){
		int v=edge[i].to;
		if(type){
			res=max(res,dfs2(v,false));
		}else{
			res=min(res,dfs2(v,true));
		}
	}
	return res;
}
void flu(int p){
	if(p>m){
		initt();
		int res=dfs2(1,true);
		maxans=max(maxans,res);
		minans=min(minans,res);
		return;
	}
	for(int i=1;i<=m;i++){
		if(vis[i]) continue;
		vis[i]=true;
		val[lea[p-1]]=i;
		flu(p+1);
		vis[i]=false;
	}
	return;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	dfs1(1);
	m=lea.size();
	flu(1);
	printf("%d %d\n",maxans,minans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
