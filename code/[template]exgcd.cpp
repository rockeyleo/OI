#include <bits/stdc++.h>
using namespace std;
int a,b,x,y;

void exgcd(int a,int b,int &x = x,int &y = y){
	if(b==0){
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a%b,x,y);
	int tmp = y;
	y = x-(a/b)*y;
	x = tmp;
//	return d;
}

int main(){
	cin>>a>>b;
	exgcd(a,b);
	cout<<x<<" "<<y<<endl;
}
