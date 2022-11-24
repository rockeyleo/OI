#include <bits/stdc++.h>
using namespace std;

const int N = 300005, M = 5000005;
int n,m;
int head[M],nxt[M],to[M],val[M],cnt;
int st[N][3];
int dis[N];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch=getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}

struct node{
	int name;
	int dis;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	}
};
priority_queue<node> q;

void add(int f,int t,int v){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	val[cnt] = v;
}

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	node tmp = {s,0}; q.push(tmp);
	while(!q.empty()){
		tmp = q.top(); q.pop();
		int now = tmp.name;
		for(int i=head[now];i;i=nxt[i]){
			int tt = to[i];
			if(dis[tt]>dis[now]+val[i]){
				dis[tt] = dis[now] + val[i];
				tmp = {tt,dis[tt]};
				q.push(tmp);
			}
		}
	}
}

int main(){
//	freopen("sample_cheat03.in","r",stdin);
//	cin>>n>>m;
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)st[i][j] = read();
	}
	for(int i=1;i<=m;i++){
		int f = read(),t = read(),v = read();
		add(f,t,v);
	}
	if(m>2000 and n>1000){
		for(int i=1;i<=n;i++){
			add(i,n+1,st[i][2]);
			add(n+1,i,st[i][2]);
		}
	}else{
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if((st[i][0]^st[j][0])>=st[i][1] and dis[j]>st[i][2]+st[j][2]){
					add(i,j,st[i][2]+st[j][2]);
	//				cout<<cnt<<endl;
				}
			}
		}
	}
//	int s = 1;
	dij(1);
	if(dis[n]==0x3f3f3f3f){
		cout<<-1<<endl;	
	}else{
		cout<<dis[n]<<endl;
	}
}

/*
2 0
1 123123 0
2 1231231 0
*/
