#include <bits/stdc++.h>
const int M = 500101;
using namespace std;
int usd[M];
int sum1,sum2,n;
struct node{
	int pos,tu,yun;
}ball[M];
pair<int,int>tt[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret;
}

void dfs(int mod,int cnt,int val1,int val2){
	if(cnt == n){
		sum1 = max(sum1,val1);
		sum2 = max(sum2,val2);
		return;
	}
	if(mod){
		//baiyun
		for(int i=1;i<=n;i++){
			if(usd[i])continue;
			usd[i] = 1;
			dfs(0,cnt+1,val1+ball[i].yun,val2);
			usd[i] = 0;
		}
	}else{
		//baitu
		for(int i=1;i<=n;i++){
			int to = tt[i].first;
			if(usd[to])continue;
			usd[i] = 1;
			dfs(1,cnt+1,val1,val2+tt[i].second);
			usd[to] = 0;
		}

	}
}

int main(){
	string str;
	cin>>n>>str;
	for(int i=1;i<=n;i++){
		ball[i].pos = i;
		ball[i].yun = read();
	}
	for(int i=1;i<=n;i++){
		ball[i].tu = read();
		tt[i] = {i,ball[i].tu};
	}
	sort(ball+1,ball+1+n,[](node a,node b){return a.tu<b.tu;});
	stable_sort(ball+1,ball+1+n,[](node a,node b){return a.yun>b.yun;});
	sort(tt+1,tt+1+n,[](pair<int,int> a,pair<int,int> b){return a.second>b.second;});
	if(str == "baitu"){
		dfs(0,0,0,0);
	}else{
		dfs(1,0,0,0);
	}
	cout<<sum1<<" "<<sum2<<endl;
}
