#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int a[M],tree[M];
int n,m;

int lowbit(int a){
	return a&(-a);
}

void add(int p,int v){
	for(int i=p;i<=n;i+=lowbit(i)){
		tree[i]+=v;
	}
}

int query(int p){
	int ans = 0;
	for(int i=p;i;i-=lowbit(i)){
		ans+=tree[i];
	}
	return ans;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		add(i,tmp);
	}
	for(int i=1;i<=m;i++){
		int tmp;
		cin>>tmp;
		if(tmp==1){
			int x,k;
			cin>>x>>k;
			add(x,k);
		}else{
			int x,y;
			cin>>x>>y;
			cout<<query(y)-query(x-1)<<endl;
		}
	}
}
