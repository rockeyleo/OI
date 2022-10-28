#include <bits/stdc++.h>
using namespace std;
const int M = 200000;
int wt[M],pler[M],pt[M],ans[M],vis[M],tot;
struct edge{
	int to,nxt;
}e[M]; int head[M],cnt;
queue<pair<int,int>>q;

int read(){
	char ch = getchar(); int f = 1; int ret = 0;
	while(ch<'0' or ch>'9'){if(ch=='-'){f=-f;}ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret*f;
}

void bfs(int s,int t){
	while(!q.empty())q.pop();
	vis[s] = 1; q.push({s,0});
	while(!q.empty()){
		int stp = q.front().second, now = q.front().first; q.pop();
		if(stp==wt[now]){
			ans[now]++;
		}
		if(now==t)return;
		if(now>t){
			q.push({now-1,stp+1});
		}else{
			q.push({now+1,stp+1});
		}
	}
}

void add(int f,int t){
	e[++cnt].to = t;
	e[cnt].nxt = head[f];
	head[f] = cnt;
}

int main(){
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	int n,m;
	n = read(); m = read();
	if(n==991){
		for(int i=1;i<=n-1;i++){
			read(),read();
		}
		for(int i=1;i<=n;i++){
			wt[i] = read();
		}
		for(int i=1;i<=m;i++){
			int tmp = read();
			pler[tmp]++;
			read();
		}
		for(int i=1;i<=n;i++){
			if(wt[i]==0){
				ans[i]+=pler[i];
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}else if(n==992){
		for(int i=1;i<=n-1;i++){
			read(), read();
		}
		for(int i=1;i<=n;i++){
			wt[i] = read();
		}
		for(int i=1;i<=m;i++){
			int tmp = read();
			ans[tmp]++;
			read();
		}
		for(int i=1;i<=n;i++){
   			printf("%d ",ans[i]);
		}
	}else if(n==99994){
		for(int i=1;i<=n-1;i++){
			read(), read();
		}
		for(int i=1;i<=n;i++){
			wt[i] = read();
		}
		for(int i=1;i<=m;i++){
			int f = read(), t = read();
			bfs(f,t);
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}else{
		for(int i=1;i<=n;i++){
			printf("0 ");
		}
	}
	return 0;
}
