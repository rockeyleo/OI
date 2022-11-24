#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
pair<int,int>pl[M];
int main(){
	freopen("11.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		int n;
		long long s,p;
		scanf("%d%lld%lld",&n,&s,&p);
		memset(pl,0,sizeof(pl));
		long long tot = 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&pl[i].first,&pl[i].second);
			tot += pl[i].first;
		}
		if(p==0){
			printf("%d\n",n);
		}else{
			sort(pl+1,pl+1+n,[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
			int cnt = 0, tmp = s;
			while(true){
				tmp-=pl[cnt+1].second;
				if(tmp<p){
					break;
				}
//				cout<<tmp<<endl;
				cnt++;
			}
			printf("%d\n",cnt);
		}
	}
}
