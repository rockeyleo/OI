#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500100],tree[500100];
int lb(int x){
	return x&(-x);
}

void add(int x,int k){
	for(int i=x;i<=n;i+=lb(i)){
		tree[i]+=k;
	}
}

int query(int x){
	int ans = 0;
	for(int i=x;i;i-=lb(i)){
		ans+=tree[i];
	}
	return ans;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		add(i,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y,k;
			cin>>x>>y>>k;
			add(x,k); add(y+1,-k);
		}else{
			int x;
			cin>>x;
			cout<<query(x)<<endl;
		}
	}
}
