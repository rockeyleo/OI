#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
int top[M],vis[M];
int ht,et,tot; bool flag;

queue<int>q;

struct hh{
	long long x,y,z;
}hole[M];

struct edge{
	int nxt = 0,to;
}e[M]; int head[M];

void bfs(){
	while(!q.empty()){
		int now = q.front(); q.pop();
//		cout<<now<<endl;
		if(top[now]){
//			cout<<now<<endl;
			flag = 1;
			return;
		}
		for(int i=head[now];i;i=e[i].nxt){
			int tt = e[i].to;
			if(!vis[tt]){
				vis[tt] = 1;
				q.push(tt);
			}
			
		}
	}
	return;
}

long long pp(int a){
	return (long long)a*(long long)a;
}

long long dist(hh a,hh b){
	int xa = a.x, xb = b.x, ya = a.y, yb = b.y, za = a.z, zb = b.z;
	return(pp(xa-xb)+pp(ya-yb)+pp(za-zb));
}

void add(int f,int t){
	e[++et].to = t;
	e[et].nxt = head[f];
	head[f] = et;
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("cheese52.in","r",stdin);
	freopen("cheese5.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ht = 0; et = 0; tot = 0; flag = false;
		while(!q.empty())q.pop();
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		memset(top,0,sizeof(top));
		int n,h,r;
		cin>>n>>h>>r;
		for(int i=1;i<=n;i++){
			long long x,y,z;
			cin>>x>>y>>z;
			hole[++ht].x=x; hole[ht].y=y, hole[ht].z=z;
			if(hole[ht].z<=r){
				vis[ht]=1;
				q.push(ht);
			}
			if(hole[ht].z+r>=h){
				top[ht] = 1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dist(hole[i],hole[j])<=pp(2*r)){
//					cout<<i<<" "<<j<<endl;
					add(i,j);
					add(j,i);
				}
			}
		}
		bfs();
		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
