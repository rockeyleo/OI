#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
int n;
struct EDGE{
	int to,nxt;
}e[MAXN<<1];
int tot=0,head[MAXN]={0};
void AE(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
int m=0,maxdep=0,dep[MAXN]={0},fa[MAXN]={0},depcnt[MAXN]={0};//该深度上的叶子 
//dep&1==1 : D -> max
//dep&1==0 : V -> min
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	if(dep[x]>maxdep)maxdep=dep[x];
	if(!head[x]){
		depcnt[dep[x]]++;
		m++;
		return;
	}
	for(int i=head[x];i;i=e[i].nxt)dfs(e[i].to);
}
int igmin,igmax;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		AE(x,y);//directed
		fa[y]=x;
	}
	//solve D
	dfs(1);
	int cost=0,flag=0;
	for(int i=2;i<=maxdep;i++){
		if(i&1){//V node
			cost+=depcnt[i];
		}else{//D node
			if(depcnt[i]){
				printf("%d ",m-cost);
				flag=1;
				break;
			}
		}
	}
	if(!flag)printf("1 ");
	//solve V
	cost=0,flag=0;
	for(int i=2;i<=maxdep;i++){
		if(i&1){//V node
			if(depcnt[i]){
				printf("%d\n",cost+1);
				flag=1;
				break;
			}
		}else{//D node
			cost+=depcnt[i];
		}
	}
	if(!flag)printf("%d\n",m);
	return 0;
} 
