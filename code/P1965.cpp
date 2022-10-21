#include <bits/stdc++.h>
using namespace std;
int n,m,k,x;
int main(){
	//freopen("circle.in","r",stdin);
	//freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	int flag = 0;
	long long tmp = m;
	int p = k%10; 
	for(int i=1;i<=k/10;i++){
		tmp = (tmp%n * 10000000000%n)%n;
	}
	for(int i=1;i<=p;i++){
		tmp = (tmp%n * 10%n)%n;
	}
	long long t1 = (tmp + x%n)%n;
	cout<<t1<<endl;
}