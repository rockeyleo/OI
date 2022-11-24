#include <bits/stdc++.h>
using namespace std;
const int M = 5056;
long long cnt;
int n,m;
struct sst{
	int ld,air;
}state[M];
long long mnn = (1ll<<62);
int maxn;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		state[i] = {a,b};
		long long tot = a+b;
		mnn = min(tot,mnn);
	}
	if(mnn == 0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int mi = min(state[i].ld,state[i].air);
		if(mi > maxn){
			maxn = mi;
			if(maxn>=mnn){
				for(int i=1;i<=mnn;i++){
					cnt+=i+1;
				}
				break;
			}
		}
	}
	cout<<cnt<<endl;
}
