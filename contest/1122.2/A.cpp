#include <bits/stdc++.h>
using namespace std;
const int M = 500010;
int val[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){
		ch = getchar();
	}
	while(ch>='0' and ch<='9'){
		ret = ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}

int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		val[i] = read();
	}
	for(int i=1;i<=n-1;i++){
		int f = read(), t = read();
	}
}
