#include <bits/stdc++.h>
using namespace std;
const int mn = 1000000000;
int main(){
	long long a,b;
	cin>>a>>b;
	if(a==1 or b==1){
		cout<<a<<endl; return 0;
	}
	long long ans = a;
	for(int i=2;i<=b;i++){
		ans*=a;
		if(ans>mn){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
