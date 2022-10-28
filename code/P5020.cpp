#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
int flag[M];
int a[M];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		memset(a,0,sizeof(a));
		memset(flag,-1,sizeof(flag));
		for(int j=1;j<=t;j++){
			cin>>a[j];
			flag[a[j]]=2;
		}
		sort(a+1,a+1+t,[](int a,int b){return a<b;});
		for(int q=1;q<=a[t];q++){
			if(flag[q]>0){
				for(int k=1;k<=t;k++){
					flag[q+a[k]] = 1;
				}
			}
		}
		int ans = 0;
		for(int j=1;j<=a[t];j++){
//			cout<<j<<" "<<flag[j]<<endl;
			if(flag[j]==2)ans++;
		}
		cout<<ans<<endl;
	}
}
