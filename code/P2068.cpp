#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int M = 500001;
long long tree[M];
int n,w;

int lowbit(int x){
    return(x&(-x));
}

long long query(int x){
    long long ans = 0;
    for(int i=x;i;i-=lowbit(x)){
        ans += tree[i];
    }
    return ans;
}

void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(x)){
        tree[i]+=k;
    }
}

signed main(){
	freopen("P2068_1.in","r",stdin);
	freopen("P2068_1.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=w;i++){
		char opt;
		cin>>opt;
		if(opt == 'x'){
			int a,b;
			cin>>a>>b;
			add(a,b);
		}else{
			int a,b;
			cin>>a>>b;
			cout<<(query(b)-query(a-1))<<endl;
		}
	}
}
