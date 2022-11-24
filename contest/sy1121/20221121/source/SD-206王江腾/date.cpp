#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
const int MAXLOG=18;//0-17
int n,m,log_2[MAXN]={0},st[MAXLOG][MAXN]={0};
struct EDGE{
	int to,nxt;
}e[MAXN<<1];
int tot=0,head[MAXN]={0};
void AE(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
struct TREE{
	int fa,dep,son,size,top;
}t[MAXN];
void dfs1(int x){
	t[x].dep=t[t[x].fa].dep+1;
	int maxson=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==t[x].fa)continue;
		t[y].fa=x;
		dfs1(y);
		t[x].size+=t[y].size;
		if(t[y].size>t[maxson].size)maxson=y;
	}
	t[x].son=maxson;
	t[x].size++;
}
void dfs2(int x,int top){
	t[x].top=top;
	if(!t[x].son)return;
	dfs2(t[x].son,top);
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==t[x].fa||y==t[x].son)continue;
		dfs2(y,y);
	}
}
void initST(){
	for(int i=1;i<=n;i++)st[0][i]=t[i].fa;
	for(int i=1;i<=log_2[n];i++){
		for(int j=1;j<=n;j++)st[i][j]=st[i-1][st[i-1][j]];
	}
}
int getLCA(int x,int y){
	while(t[x].top!=t[y].top){
		if(t[t[x].top].dep>t[t[y].top].dep){
			x=t[t[x].top].fa;
		}else{
			y=t[t[y].top].fa; 
		}
	}
	return t[x].dep<t[y].dep?x:y; 
}
int getKA(int x,int k){
	while(k){
		x=st[log_2[k]][x];
		k-=(1<<log_2[k]);
	}
	return x;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	for(int i=2;i<MAXN;i++)log_2[i]=log_2[i>>1]+1;
	scanf("%d",&n);
	int x,y; 
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		AE(x,y);
		AE(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	initST();
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if((t[x].dep-t[y].dep)%2!=0){
			printf("0\n");continue;
		}
		if(x==y){
			printf("%d\n",n);continue;
		}
		int lca=getLCA(x,y);
		if(t[x].dep==t[y].dep){//LCA is the target
			int dis=t[x].dep-t[lca].dep;
			int _x=getKA(x,dis-1),_y=getKA(y,dis-1);
			printf("%d\n",t[1].size-t[_x].size-t[_y].size);
		}else{//target on the path lca->low
			int dis=t[x].dep+t[y].dep-2*t[lca].dep;//must be odd and positive
			int low=t[x].dep>t[y].dep?x:y;
			int _mid=getKA(low,(dis>>1)-1);
			printf("%d\n",t[t[_mid].fa].size-t[_mid].size);
		}
	}
	return 0;
}
