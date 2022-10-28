#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	for(long long i=1;i<=1000000000;i++){
		if((a*i)%b==1){
			cout<<i<<endl;
			return 0;
		}
	}
}
