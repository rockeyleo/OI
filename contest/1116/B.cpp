#include <bits/stdc++.h>
using namespace std;
const int M = 6060;
int head[M],nxt[M],cnt,to[M];
int ans = 0;
int vis[M];
stack<int>stk;
bool instk[M];
int mindep = 0x3f3f3f3f;
vector<pair<int,int>>vec;
void dfs(int now,int fa,int dep){
//	cout<<now<<endl;
	stk.push(now);
	if(dep>mindep)return;
	if(vis[now]){
//		cout<<"!"<<now<<endl;
		ans++;
	 	mindep = min(mindep,dep);
//	 	cout<<stk.top()<<endl;stk.pop();
//	 	do{
//	 		instk[stk.top()]=0;
//	 		cout<<stk.top()<<endl;stk.pop();
//		}while(stk.top() != now);
//		cout<<endl;
	 	return;
	 }
	 vis[now] = 1;instk[now]=1;
	 for(int i=head[now];i;i=nxt[i]){
	 	int tt = to[i];
	 	if(tt==fa)continue;
	 	dfs(tt,now,dep+1);
	 }
}

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t),add(t,f);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i,-1,0);
	}
	cout<<ans;
}
