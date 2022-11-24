#include <bits/stdc++.h>
using namespace std;
const int M = 1000020;
int a[M],b[M];
int mp[M];
int vis[M];
vector<int>ans;
int cnt;
int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){
		ch = getchar();
	}
	while(ch>='0' and ch<='9'){
		ret = ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}

bool check(int a,int b){
//	cout<<a<<" "<<b<<" "<<mp[b]<<endl;
	if(mp[b] == a){
		return true;
	}else if(mp[b] == -1 and !vis[a]){
//		cout<<1111<<endl;
		vis[a] = 1;
		mp[b] = a;
		return true;
	}else{
		return false;
	}
}

int main(){
	clock_t st,ed;
	st = clock();
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	int t,u;
	cin>>t>>u;
	while(t--){
    	int n,m;
    	cin>>n>>m;
    	cnt = 0;
    	ans.clear();
    	memset(mp,-1,sizeof(mp));
    	memset(vis,0,sizeof(vis));
    	for(int i=1;i<=n;i++){
			a[i] = read();
		}
		for(int i=1;i<=m;i++){
			b[i] = read();
		}
//    	int j = 0;
//    	for(int i=2;i<=m;i++){
//	        while(j!=0 and b[j+1]!=b[i]){
//    	        j = nxt[j];
//        	}
//	        if(b[j+1]==b[i]){
//	            j++;
//	        }
//    	    nxt[i] = j;
//    	}
//	    j=0;
//    	for(int i=1;i<=n;i++){
//    		cout<<"i="<<i<<endl;
//        	while(j!=0 and !check(a[i],b[j+1])){
//        		cout<<"j="<<j<<endl;
//        		j = nxt[j];
//        		memset(mp,0,(u+1)*sizeof(mp[0]));
//			}
//        	if(check(a[i],b[j+1])){
//        		j++;
//        		cout<<"j="<<j<<endl;
//			}
//        	if(j==m){
//        		cout<<"done"<<endl;
//            	ans.push_back(i-m+1);
//            	cnt++;
//            	j = nxt[j];
//            	i = i-(m-j)+1;
//            	memset(mp,0,(u+1)*sizeof(mp[0]));
//        	}
//    	}
		int j = 1;
		for(int w=1;w<=n-m+1;w++){
			for(int i=w;i<=n;i++){
//				cout<<i<<" "<<j<<endl;
				if(!check(a[i],b[j])){
					memset(mp,-1,sizeof(mp));
					memset(vis,0,sizeof(vis));
					j=1;
					break;
				}else{
					j++;
//					cout<<j<<" "<<m<<endl;
					if(j>m){
						ans.push_back(i-m+1);
						cnt++;
						memset(mp,-1,sizeof(mp));
						memset(vis,0,sizeof(vis));
						j = 1;
						break;
					}
				}
			}
		}
    	printf("%d\n",cnt);
		for(int x:ans){
			printf("%d ",x);
		}
		printf("\n");
	}
	ed = clock();
//	cout<<(double)(ed-st)/CLOCKS_PER_SEC<<endl;
}
