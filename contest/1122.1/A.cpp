#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int M = 500010;

struct orz{
	int x,y;
}node[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret;
}

long long dist(long long x,long long y,long long a,long long b){
	return(((x-a)%p*(x-a)%p)%p+((y-b)%p*(y-b)%p)%p)%p;
}

int n;

int main(){
//	freopen("a1.in","r",stdin);
//	freopen("a1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x = read(), y = read();
		node[i] = {x,y};
//		cout<<x<<" "<<y<<endl;
	}
	for(int i=1;i<=n;i++){
		long long ans = 0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int x = node[i].x, y = node[i].y, a = node[j].x, b = node[j].y;
			ans = (ans%p+dist(x,y,a,b))%p;
//   			cout<<x<<" "<<y<<" "<<a<<" "<<b<<" "<<dist(x,y,a,b)<<endl;
		}
		printf("%lld\n",ans);
//		cout<<endl;
	}
}
