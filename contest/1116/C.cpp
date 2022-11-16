#include <bits/stdc++.h>
using namespace std;
const int M = 500010;
int ans[M];
int main(){
	int n,m,T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int f,t,l,r;
			scanf("%d%d%d%d",&f,&t,&l,&r);
			if(l==r){
				ans[i] = l;
			}
		}
		cout<<"Yes"<<endl;
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
}
