#include <bits/stdc++.h>
using namespace std;
const int M = 5000010;
int n;
int son[M];
struct dd{
	int ls,rs;
}node[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}

void init(int now = 1,int fa = 1){
	if(node[now].ls == 0 and node[now].rs == 0){
		son[i] = 1;
		return;
	}
	if(node[now].ls!=-1)dfs(node[now].ls,now);
	if(node[now].ts!=-1)dfs(node[now].rs,now);
	son[now] = son[node[now].ls]+son[node[now].rs]
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		node[i].ls = read();
		node[i].rs = read();
	}
	init();
 	dfs(node[i].ls,node[i].rs,1);
}
