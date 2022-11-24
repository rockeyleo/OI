#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int nxt[M], cnt, dis[M], head[M], to[M], val[M],
s, m, n, Q, vis[M];
int pre[M];
int up;
int tot;
vector<int>qq;
//int num[M];
int vla[M];
int tree[500100];
queue<int> q;
bool spfa(int s);

int lowbit(int x){
	return x&(-x);
}

void adq(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        tree[i]+=k;
    }
}

int query(int t){
	int ans = 0;
	for(int i=t;i;i-=lowbit(i)){
		ans+=tree[i];
	}
	return ans;
}

int getval(int f,int t){
	if(f<=n and t<=n)return 0;
	if(f>n and t>n)return 0;
	if(f<=n and t>n){
		return(query(f));	
	}
	if(f>n and t<=n){
		return(-query(t));
	}
}

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
//    val[cnt] = v;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cnt = 0;
		cin>>n>>Q;
		memset(val,0,sizeof(val));
		memset(tree,0,sizeof(tree));
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		memset(to,0,sizeof(to));
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
			adq(i,val[i]-val[i-1]);
		}
    	for(int i=1;i<n;i++){
    		add(i,i+1);
    		add(i+n,i+1+n);
		}
    	for(int i = 1; i <= n; i++){
    	    add(i,i+n);
    	    add(i+n,i);
    	}
    	while(Q--){
    		int opt;
    		scanf("%d",&opt);
    		if(opt){
    			qq.clear();
    			tot = 0;
    			spfa(1);
    			for(int i=n;i;i=pre[i]){
    				qq.push_back(i);
				}
				for(int i=0;i<=qq.size()-2;i++){
					if((qq[i]<=n and qq[i+1]>n)or(qq[i]>n and qq[i+1]<=n))tot++;
				}
    			printf("%d %d\n",-dis[n],tot);
			}else{
				int l,r,c;
				scanf("%d%d%d",&l,&r,&c);
				adq(l,c),adq(r+1,-c);
			}
		}	
	}
}

bool spfa(int s){
	tot = 0;
	memset(dis,0x3f,sizeof(dis));
//    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
	dis[s] = 0;
    q.push(s); vis[s] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop(); vis[now] = 0;
        for(int i = head[now]; i; i = nxt[i]){
        	val[i] = getval(now,to[i]);
//        	cout<<now<<"->"<<to[i]<<" "<<val[i]<<endl;
            if(dis[to[i]] > dis[now]+val[i]){
                dis[to[i]] = dis[now]+val[i];
                pre[to[i]] = now;
                if(!vis[to[i]]){
//                	if(val[i]>0){
////						cout<<now<<endl;
//						tot++;
//						up = now;
//					}
//					if(val[i]<0){
//						if(to[i]!=up){
////							cout<<to[i]<<endl;
//							tot++;
//						}else{
//							tot--;
//						}
//					}
//                    num[to[i]] = num[now]+1;
//                    if(num[to[i]] > n) return false;
                    q.push(to[i]);
                    vis[to[i]] = 1;
                }
            }
        }
    }   
    return true;
}
