#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int a[500100];
signed main(){
	int n,m;
//	freopen("work.in","r",stdin);
//	freopen("work.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	rep(i,1,m){
		int ord;
		scanf("%lld",&ord);
		if(ord==1){
			int l,r;
			scanf("%lld%lld",&l,&r);
			for(int i = n;i>=r+1;i-=2){
				a[i]=a[i-(r-l+1)];
			}
//			memcpy(a+r+1,a+l,(n-r+1)*sizeof(a[0]));
		}else{
			int x;
			scanf("%lld",&x);
			printf("%lld\n",a[x]);
		}
	}
	return 0;
}
