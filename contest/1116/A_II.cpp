#include <bits/stdc++.h>
using namespace std;

#define int long long

int mp[500501];

signed main(){
	int p;
	int ans = -1;
	cin>>p;
	for(int i=0;i<p;i++){
		mp[(i*i)%p] = 1;
	}
	for(int i=0;i<p;i++){
		for(int a=0;a<p;a++){
			int b = (i-a*a+p)%p;
			if(mp[b]==1){
				ans = max(ans,a);
				break;
			}
		}
	}
	cout<<ans<<endl;
}
