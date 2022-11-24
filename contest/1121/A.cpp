#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
struct node{
	int first,second;
	__int128_t val;
}pl[M];
int val[M];
int main(){
//	freopen("11.in","r",stdin);
//	freopen("10.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		long long s,p;
		scanf("%d%lld%lld",&n,&s,&p);
		memset(pl,0,sizeof(pl));
		__int128_t tot = 0;
		__int128_t tot2 = 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&pl[i].first,&pl[i].second);
			tot += pl[i].second;
			tot2 += pl[i].first;
		}
		for(int i=1;i<=n;i++){
   			int val = s-(tot-pl[i].second);
//   			cout<<val<<endl;
			if(val>=0){
				pl[i].val = min(val,pl[i].first);
			}else{
				pl[i].val = pl[i].first;
			}
//			cout<<pl[i].val<<endl;
		}
		if(p==0){
			printf("%d\n",n);
		}else{
			sort(pl+1,pl+1+n,[](node a,node b){return a.val<b.val;});
			int cnt = 0;
			__int128_t tmp = tot2;
			while(true){
				tmp-=pl[cnt+1].val;
//				cout<<cnt+1<<" "<<pl[cnt+1].val<<" ";
//				cout<<tmp<<endl;
				if(tmp<p){
					break;
				}else if(cnt+1>n){
					cnt--;
					break;
				}
				cnt++;
			}
			printf("%d\n",cnt);
		}
	}
}
