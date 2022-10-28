#include <bits/stdc++.h>
using namespace std;
int n,h,r;
struct hd{
	int x,y,z;
}hole[50001];
int cnt;
int in[50100],out[50010],cta;
int head[50100],nxt[50100],to[50010],tot;
int vis[50100]; bool flag;

queue<int>q;

void add(int x,int y,int z){
	hole[++cnt].x = x;
	hole[cnt].y = y;
	hole[cnt].z = z;
	if(z<=r)in[++cta]=cnt;
	if(z+r>=h){out[cnt]=1;}
}

void adde(int f,int t){
	to[++tot] = t;
	nxt[tot] = head[f];
	head[f] = tot;
}

double dist(hd a,hd b){
	int xa = a.x, xb = b.x, ya = a.y, yb = b.y, za = a.z, zb = b.z;
	return(sqrt(pow(xa-xb,2)+pow(ya-yb,2)+pow(za-zb,2)));
}

int dfs(int s){
//	cout<<s<<" "<<hole[s].z+r<<endl;
//	cout<<out[s]<<endl;
	if(vis[s])return false;
	vis[s] = 1;
	if(out[s]){
		return true;
	}
	bool flag = false;
	for(int i = head[s];i;i=nxt[i]){
		int tt = to[i];
		//cout<<s<<" "<<tt<<endl;
		if(dfs(tt)){
			flag = true;
		}
	}
	return flag;
}

void bfs(){
	while(!flag and !q.empty()){
		int now = q.front();q.pop();
		vis[now] = 1;
		for(int i=head[now];i;i=nxt[i]){
			int tt = to[i];
			if(vis[tt])continue;
			if(out[tt]){
				flag = 1;
				break;
			}
			q.push(tt);
		}
	}
	queue<int>empty;
	swap(empty,q);
}

int main(){
	//freopen("cheese.in","r",stdin);
	//freopen("cheese.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt = 0;
		cta = 0;
		tot = 0;
		memset(to,0,sizeof(to));
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		cin>>n>>h>>r;
		for(int j=1;j<=n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
		}
//		sort(hole+1,hole+1+cnt,[](hd a,hd b){return a.z<b.z;});
//		if(r*n*2<h or hole[1].z>r or hole[cnt].z+r<h){
//			cout<<"No"<<endl;continue;
//		}
		for(int j=1;j<=cnt;j++){
			for(int q=j+1;q<=cnt;q++){
//				if(j==q)continue;
				if(dist(hole[j],hole[q])<=(double)r*2){
					//cout<<dist(hole[j],hole[q])<<" "<<r*2<<" "<<endl;
					adde(j,q);
					adde(q,j);
				}
			}
		}
		flag = false;
		for(int j=1;j<=cta;j++){
			q.push(in[j]);
		}
		bfs();
		if(flag){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
