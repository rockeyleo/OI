#include <bits/stdc++.h>
using namespace std;
const int M = 25000;
int a[M];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		memset(a,0,sizeof(a));
		cin>>n;
		int ans = n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+1+n,[](int a,int b){return a>b;});
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]%a[k]==0 and a[j]!=0){
	 				cout<<a[j]<<" "<<a[k]<<endl;
	 				a[j]=0;
					ans--;
				}
			}
		}
		cout<<ans<<endl;
	}
}
