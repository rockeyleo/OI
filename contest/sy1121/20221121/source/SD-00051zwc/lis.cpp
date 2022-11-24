#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,a[N],f[N];
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=INT_MIN;
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=i;j<=n;j++)f[j]=a[j];
		for(int j=i+1;j<=n;j++){
			if(f[j]<=f[j-1]){
				if(flag)break;
				flag=1;
				f[j]=f[j-1]+1;
			}
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
