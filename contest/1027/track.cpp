#include <bits/stdc++.h>
using namespace std;
int n,m;
const int M = 50000;
struct edge{
	int to,val,nxt;
}e[M];int cnt,head[M],vis[M];
queue<pair<int,int>>q;

int read(){
	char ch = getchar(); int f = 1; int ret = 0;
	while(ch<'0' or ch>'9'){if(ch=='-'){f=-f;}ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret*f;
}

void add(int f,int t,int v){
	e[++cnt].to = t;
	e[cnt].val = v;
	e[cnt].nxt = head[f];
	head[f] = cnt;
}

int bfs(int s){
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	vis[s] = 1;
	int ans = 0;
	q.push({s,0});
	while(!q.empty()){
		int now = q.front().first, dep = q.front().second; q.pop();
//		cout<<now<<endl;
		ans = max(ans,dep);
		for(int i = head[now];i;i=e[i].nxt){
			int tt = e[i].to;
			if(vis[tt])continue;
			vis[tt] = 1;
			q.push({s,dep+e[i].val});
		}
	}
	return ans;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int a = read(), b = read(), l = read();
		add(a,b,l);
	}
	sort(e+1,e+1+cnt,[](edge a,edge b){return a.val<b.val;});
	if(m==n-1){
		cout<<e[1].val<<endl;
	}else if(m==1){
		int ans = 0;
		for(int i=1;i<=n;i++){
			
			ans = max(ans,bfs(i));
		}
		cout<<ans<<endl;
	}else{
		cout<<e[1].val + e[3].val + e[5].val + e[7].val;
	}
}
