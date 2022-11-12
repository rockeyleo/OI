#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r;
	cin>>n>>l>>r;
	if(l/n==r/n)cout<<r%n<<endl;
	else cout<<n-1<<endl;
}
