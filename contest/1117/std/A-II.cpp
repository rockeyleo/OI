#include <bits/stdc++.h>
using namespace std;
const int M = 500051;
int st[M],lzy[M];
int n,m;
int nxt[M],head[M],to[M],cnt;
int in[M],out[M];
int vis[M];
int dtot;
queue<int>q;
vector<int>ans;
int at;
void bfs(){
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dtot++;
			q.push(i);	
		}
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		int flag = 0;
		st[now] = (st[now]+lzy[now])%2;
		if(!st[now]){
			flag = 1;
			st[now] = 1;
			at++;
		}
		ans.push_back(now);
		vis[now] = 1;
		for(int i = head[now];i;i=nxt[i]){
			
			int tt = to[i];
			if(vis[tt])continue;
			in[tt]--;
			lzy[tt]+=lzy[now];
			if(flag){
				lzy[tt]++;
			}
			
			if(in[tt]==0){
				q.push(tt);
				dtot++;
			}
		} 
	}
}

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
	out[f]++;in[t]++;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&st[i]);
	}
	for(int i=1;i<=m;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t);
	}
//	for(int i=1;i<=n;i++){
//		cout<<st[i]<<endl;
//	}
	bfs();
//	for(auto a:ans){
//		cout<<a<<endl;
//	}
//	cout<<dtot<<endl;
	
	for(int i=1;i<=n;i++){
		if(!vis[i] and ){
			cout<<-1<<endl;
			return 0;
		}
	}
	
	if(dtot<n){
		cout<<"-1"<<endl;
	}else{
		cout<<at<<endl;
	}
}

/*
6 7
0 0 0 0 0 0
1 2
2 3
3 1
5 1
2 3 
6 3
4 5
*/
