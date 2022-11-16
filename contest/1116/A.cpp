#include <bits/stdc++.h>
using namespace std;
int main(){
	int p;
	cin>>p;
	int ans = 1;
	for(int i=1;i*i<=p;i++){
		ans = i;
	}
	cout<<ans<<endl;
}
