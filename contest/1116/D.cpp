#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,x0,y0,xt,yt;
	cin>>n>>m>>x0>>y0>>xt>>yt;
	if(x0==1 and y0==1 and xt==m and yt == n){
		for(int j=1;j<=(n-1)/2;j++){
			for(int i=1;i<=m-1;i++){
				printf("R");
			}
			printf("D");
			for(int i=1;i<=m-1;i++){
				printf("L");
			}
			printf("D");
		}
		for(int i=1;i<=m-1;i++){
				printf("R");
			}
	}
	if(x0==1 and y0==1 and xt==1 and yt == 2){
		printf("R");
		for(int j=1;j<=(n)/2;j++){
			for(int i=1;i<=m-2;i++){
				printf("R");
			}
			printf("D");
			for(int i=1;i<=m-2;i++){
				printf("L");
			}
			if(j!=n/2)printf("D");
		}
		printf("L");
		for(int i=1;i<=n-2;i++){
			printf("U");
		}
	}
}
