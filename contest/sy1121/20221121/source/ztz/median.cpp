#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1919810;

int a[N];
bool t[N]; 
int ans[N];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(int i=2;i<n;i++){
		if(a[i]!=a[i-1]&&a[i]!=a[i+1]) {
			if(t[i-1])continue;
			else ans++, t[i]=1;
		} 
	}
	cout<<ans<<endl;
	if(ans!=0){
		if(a[1]==1&&a[n]==1){
			for(int i=1;i<=n;i++) cout<<1<<' ';
		}else if(a[1]==0&&a[n]==1){
			int t0=0,t1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) t0++;
				if(a[i]==1) t1++;
			}
			for(int i=1;i<=t0;i++) cout<<0<<' ';
			for(int i=1;i<=t1;i++) cout<<1<<' ';
		}else if(a[1]==1&&a[n]==0){
			int t0=0,t1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) t0++;
				if(a[i]==1) t1++;
			}
			for(int i=1;i<=t1;i++) cout<<1<<' ';
			for(int i=1;i<=t0;i++) cout<<0<<' ';
		}else{
			for(int i=1;i<=n;i++) cout<<0<<' ';
		}
	}
}
