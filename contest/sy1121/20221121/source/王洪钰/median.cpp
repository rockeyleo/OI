#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
const int maxn=500100;
ll a[maxn],b[maxn];
ll n,x;
bool cz(int x){
	for(int i=2;i<n;i++){
		if(a[i-1]==a[i+1]){
			b[i]=a[i-1];
		}else{
			b[i]=a[i];
		}
	}
	for(int i=2;i<n;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(re int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1],b[n]=a[n];
	for(re ll i=1;;i++){
		if(i>1000){
			cout<<-1;
			return 0;
		}
		if(cz(i)){
			cout<<i-1<<endl;
			for(int i=1;i<=n;i++){
				cout<<b[i]<<" ";
			}
			return 0;
		}else{
			for(int i=2;i<n;i++){
				a[i]=b[i];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
