#include<bits/stdc++.h>
using namespace std;
constexpr int N=100000,mod=998244353;
inline void reduce(int &x){if(x>=mod) x-=mod;}
long long qpow(long long a,long long b){
	long long m=1;
	while(b){
		if(b&1) m=m*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return m;
}
int a[N+10],b1[N+10],b2[N+10],c1[N+10],c2[N+10];
map<int,int> t[N+10];
int f[N+10][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==2){
		int i,t=0,a,b,c;
		for(i=1;i<=m;++i) cin>>a>>b>>c,t^=c;
		if(m==4&&t) cout<<0<<'\n';
		else m=min(m,3),cout<<(1<<3-m)<<'\n';
		return 0;
	}
	int i,cnt=0;
	for(i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(abs(u-v)>=3){
			if(t[v][u]){
				if(t[v][u]!=w+1){
					cout<<0<<'\n';
					return 0;
				}
				--cnt;
			}
			t[u][v]=w+1;
			++cnt;
		}
		else{
			if(u==v) a[u]=w+1;
			else if(v==u-1) b1[v]=w+1;
			else if(v==u-2) b2[v]=w+1;
			else if(v==u+1) c1[u]=w+1;
			else c2[u]=w+1;
		}
	}
	cnt=(n-2ll)*(n-3)/2%(mod-1)-cnt;
	for(i=1;i<=n-2;++i){
		if(b2[i]&&c2[i]){
			int t=b2[i]-1^c2[i]-1;
			++t;
			if(a[i+1]&&a[i+1]!=t){
				cout<<"0\n";
				return 0;
			}
			a[i+1]=t;
		}
		else if(!b2[i]&&!c2[i]) ++cnt;
	}
	for(i=1;i<n;++i){
		if(b1[i]<c1[i]) swap(b1[i],c1[i]);
		if(b1[i]&&c1[i]) c1[i]=(c1[i]-1^b1[i]-1)+1;
		if(!b1[i]) ++cnt;
	}
	int ans=qpow(2,cnt);
	if(a[1]) f[1][a[1]-1]=1;
	else f[1][0]=f[1][1]=1;
	for(i=2;i<=n;++i){
		int j,k;
		for(j=0;j<2;++j){
			for(k=0;k<2;++k){
				if(a[i]&&a[i]-1!=k) continue;
				if(c1[i-1]&&c1[i-1]-1!=(j^k)) continue;
				reduce(f[i][k]+=f[i-1][j]);
			}
		}
	}
	cout<<(long long)ans*(f[n][0]+f[n][1])%mod<<'\n';
	return 0;
}

