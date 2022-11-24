#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+3;
int n,q;
struct Edge{
	int next;
	int to;
}edge[N<<1];
int head[N],num_edge=0;
inline void add_edge(int from,int top){
	edge[++num_edge]=(Edge){head[from],top};
	head[from]=num_edge;
}
int lg[N];
struct node{
	int dep,siz;
	int st[23];
}tree[N];
void dfs(int p,int fa){
	tree[p].dep=tree[fa].dep=1; 
	tree[p].st[0]=fa;
	tree[p].siz=1;
	for(int i=1;i<=lg[tree[p].dep];i++){
		tree[p].st[i]=tree[tree[p].st[i-1]].st[i-1];
	}
	for(int i=head[p];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa) continue;
		dfs(v,p);
		tree[p].siz+=tree[v].siz;
	}
	return;
}
inline int lca(int x,int y){
	if(tree[x].dep<tree[y].dep){
		swap(x,y);
	}
	while(tree[x].dep>tree[y].dep){
		x=tree[x].st[lg[tree[x].dep-tree[y].dep]];
	}
	if(x==y) return x;
	for(int i=lg[tree[x].dep]+1;i>=0;i--){
		if(tree[x].st[i]!=tree[y].st[i]){
			x=tree[x].st[i];
			y=tree[y].st[i];
		}
	}
	return tree[x].st[0];
}
inline int findlen(int x,int l){
	while(lg[l]){
		x=tree[x].st[lg[l]];
		l-=(1<<lg[l]);
	}
	x=tree[x].st[0];
	return tree[x].siz;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	for(int i=2;i<=n;i++){
		lg[i]=lg[i>>1]+1;
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--){
		int x,y,z,len;
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		len=tree[x].dep+tree[y].dep-(tree[z].dep<<1);
		int ans=n;
		if(tree[x].dep>=tree[y].dep){
			ans-=findlen(x,(len>>1)-1);
			ans-=findlen(y,tree[y].dep-tree[z].dep-1);
			ans-=(tree[x].dep-tree[z].dep-(len>>1)+1);
		}else{
			ans-=findlen(y,(len>>1)-1);
			ans-=findlen(x,tree[x].dep-tree[z].dep-1);
			ans-=(tree[y].dep-tree[z].dep-(len>>1)+1);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
