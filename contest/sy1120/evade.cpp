#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
int val[M];
int pos[M],gol[M];
int head[M],nxt[M],cnt,to[M];
int n,m;

void add(int f,int t,char v[]){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	reverse(v,v+strlen(v));
	int ret = 0;
	for(int i=0;i<=(int)strlen(v)-1;i++){
		ret = ret*10+v[i]-'0';
	}
	val[cnt] = ret;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d",&pos[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&gol[i]);
	}
	for(int i=1;i<=n-1;i++){
		int f,t;
		char v[101];
		scanf("%d%d%s",&f,&t,v);
		add(f,t,v);
	}
}
