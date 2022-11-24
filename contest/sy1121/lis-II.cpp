#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int num[M];
int pre[M];
int ll[M],rr[M];
int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}

//clock_t st,ed;

int main(){
//	st = clock();
	freopen("lis1.in","r",stdin);
	freopen("lis.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		num[i] = read();
	}
	ll[1] = 1;
	for(int i=2;i<=n;i++){
		if(num[i-1]<num[i]){
			ll[i] = ll[i-1]+1;
		}else{
			ll[i] = 1;
		}
	}
	rr[n] = 1;
	for(int i=n-1;i>=1;i--){
		if(num[i]<num[i+1]){
			rr[i] = rr[i+1]+1;
		}else{
			rr[i] = 1;
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
//		cout<<ll[i]<<" "<<rr[i]<<endl;
		if(num[i-1]+1<num[i+1]){
			ans = max(ans,ll[i-1]+rr[i+1]+1);
		}else{
			ans = max({ans,ll[i-1],rr[i+1]});
		}
	}
	cout<<ans<<endl;
//	ed = clock();
//	cout<<(double)(ed-st)/CLOCKS_PER_SEC;
}
