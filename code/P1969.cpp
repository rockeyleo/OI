#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
int a[M],c[M];
int main(){
	int n;
	cin>>n;
	int ans = 1;
	int minn = 0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn = min(a[i],minn);
	}

	for(int i=1;i<=n-1;i++){
		if(a[i+1]-a[i]>0){
			ans+=a[i+1]-a[i];
		}
	}
	ans+=minn;
	cout<<ans<<endl;
}
