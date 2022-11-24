#include<bits/stdc++.h>
using namespace std;
const int M = 500010;
int num[M];
long long pre[M],p1[M],p2[M];
int cnt1,cnt2;
int n,q;

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sort(num+1,num+1+n);
	p1[1] = num[1]; pre[1] = num[1];
	for(int i=2;i<=n;i++){
		pre[i] = num[i]+pre[i-1];
		if(i%2==1){
			p1[i] = p1[i-2]+num[i];
		}else{
			p2[i] = p2[i-2]+num[i];
		}
	}
	
	while(Q--){
		int x;
		scanf("%d",&x);
		int mm = num[n/2+1];
		if(x<mm){
			printf("%d",pre[n]-pre[mm-1]);
		}else if(x==num[n]){
			if(x%num[n]==1){
				printf("")
			}else{
				
			}
		}
	}
}
