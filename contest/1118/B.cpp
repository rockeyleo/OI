#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
int del[M],num[M];
long long ans;
vector<int>nn;
int cnt;
int main(){
//	freopen("sample_seq03.in","r",stdin);
//	freopen("sample_seq03.out","w",stdout);
	int n;
	cin>>n;
	cnt = n;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<=n-1;i++){
		if(num[i]<0 and num[i+1]<0){
			del[i]=1;cnt--;
		}
	}
	for(int i=1;i<=n;i++){
		if(!del[i])nn.push_back(num[i]);
	}
	for(int i=0;i<cnt-1;i++){
		ans+=max(nn[i],nn[i+1]);
	}
	cout<<ans<<endl;
	cout<<cnt<<endl;
	for(int i:nn){
		printf("%d ",i);
	}
}
