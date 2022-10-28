#include <bits/stdc++.h>
using namespace std;
long long a,b,x,y;

void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t = y;
	y = x-(a/b)*y;
	x = t;
	return;
}

int main(){
	cin>>a>>b;
	exgcd(a,b,x,y);
	cout<<(x+b)%b<<endl;
}

// a mod b = a-(a/b)*b
