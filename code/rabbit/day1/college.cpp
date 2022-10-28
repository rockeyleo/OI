#include <bits/stdc++.h>
using namespace std;
int p = 998244353;
int main(){
	int n;
	cin>>n;
	long long ans = 1;
	for(int i=1;i<=n;i++){
		ans = (ans*3)%p;
	}
	cout<<ans%p<<endl;
}
