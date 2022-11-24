#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
int num[M];

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch = getchar();}
	return ret;
}
int n,q;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		num[i] = read();
	}
	while(q--){
		int opt = read();
		if(opt==2){
			int x =read();
			cout<<num[x]<<"\n";
		}else{
			int l = read(), r= read();
			for(int i=r+1;i>=n;i--){
				num[i] = num[i-(r-l+1)];
			}
		}
	}
}
