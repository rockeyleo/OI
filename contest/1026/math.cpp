#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	long long a,b,p,q,ans;
	cin>>a>>b;
	if(a>b){
		p = a/b;
		q = a%b;
		ans = a*p-b*q;
	}else{
		p = b/a;
		q = b%a;
		ans = b*p-a*q;
	}
	cout<<ans<<endl;
}
