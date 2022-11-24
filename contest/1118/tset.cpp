#include <bits/stdc++.h>
using namespace std;

int lowbit(int x){
	return x&(-x);
}

int cnt;
int main(){
	int hex = 16^14;
	while(hex>0){
		hex-=lowbit(hex);
		cnt++;
	}
//	cout<<cnt<<endl;
	cout<<pow(2,3)<<endl;
}
