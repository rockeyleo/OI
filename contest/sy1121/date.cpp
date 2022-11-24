#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int son[M];
int fa[M][24];
int dep[M];
int head[M],nxt[M],to[M],cnt;
int vis[M];
int out[M];

int l2g(int x){
	if(x==1){
		return 0;
	}
	return (l2g(x/2)+1);
}

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	out[f]++;
//	printf("out[%d]=%d\n",f,out[f]);
}

int query(int a,int x){
	for(int i=0;(1<<i)<=x;i++){
		if((1<<i)&x)a = fa[a][i];
	}
	return a;
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=23;i;i--){
		if(dep[fa[a][i]]>dep[b])a = fa[a][i];
	}
	if(a==b)return a;
	for(int i=23;i;i--){
		if(fa[a][i]!=fa[b][i]){
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}

void dfs(int f,int now,int de){
	vis[now] = 1;
	fa[now][0] = f;
	dep[now] = de;
	int flag = 0;
	for(int i=1;i<=23;i++){
		fa[now][i] = fa[fa[now][i-1]][i-1];
	}
	for(int i=head[now];i;i=nxt[i]){
		int tt = to[i];
		if(vis[tt])continue;
		flag = 1;
		dfs(now,tt,de+1);
		son[now]+=son[tt];
	}
	if(out[now]==1)son[now]=1;
}

int main(){
	freopen("date1.in","r",stdin);
	freopen("date1.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int f = read(), t = read();
		add(f,t);
		add(t,f);
	}
	for(int i=1;i<=n;i++){
		son[i] = 1;
	}
	dfs(1,1,0);
//	cout<<"son[1]="<<son[1]<<endl;
//	for(int i=1;i<=n;i++){
//		printf("son[%d] = %d\n",i,son[i]);
//	}
	m = read();
	for(int i=1;i<=m;i++){
		int a = read(),b = read();
		cout<<"dep[a]="<<dep[a]<<" "<<"dep[b]="<<dep[b]<<endl;
		cout<<"lca(a,b)="<<lca(a,b)<<endl;
  		int len = (dep[a]+dep[b]-2*dep[lca(a,b)]);
		printf("len(a,b)=%d\n",len);
		int mid = len/2;
		if(len%2==1){
			printf("0\n");
			continue;
		}
		if(a == b){
			printf("%d\n",son[1]);
		}else if(dep[a]==dep[b]){
			printf("a=%d,b=%d\n",a,b);
			cout<<"query(a)="<<query(a,mid-1)<<endl;
			cout<<"query(b)="<<query(b,mid-1)<<endl;
			cout<<"son[query(a,mid-1)]="<<son[query(a,mid-1)]<<endl;
			cout<<"son[query(b,mid-1)]="<<son[query(b,mid-1)]<<endl;
			if(dep[a]<dep[b])swap(a,b);
			printf("%d\n",son[1]-son[query(a,mid-1)]-son[query(b,mid-1)]);
		}else{
			if(dep[a]<dep[b])swap(a,b);
			printf("%d\n",son[query(a,mid)]-son[query(a,mid-1)]);
		}
	}
}

/*
7
1 3
1 2
2 6
2 7
2 4
4 5
1
5 3
*/
