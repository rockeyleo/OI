#include <bits/stdc++.h>
using namespace std;
int val[50010];
int tmp[50010];
int L,n,m;
bool check(int len){ //将长度小于len的长度全部删掉，看需要拿走几个石头
	memcpy(tmp+1,val+1,(n+1)*sizeof(val[0]));
//	cout<<"len="<<len<<endl;
	int cnt = 0;
	for(int i=1;i<=n+1;i++){
		if(tmp[i]-tmp[i-1]<len){
//			cout<<"val1-val2="<<val[i]-val[i-1]<<endl;
			tmp[i] = tmp[i-1];
			cnt++;
		}
	}
//	cout<<"cnt="<<cnt<<endl;
	if(cnt>m){
//		cout<<"NO"<<endl;
		return false;
	}else{
//		cout<<"YES"<<endl;
		return true;
	}
}
//最短跳跃距离的最大值
int main(){
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	val[n+1] = L;
	int l = 1,r = L;
	while(l<=r){
		int mid = (l+r)/2;
//		cout<<l<<" "<<r<<endl;
		if(check(mid)){  //mid为假设的最短距离
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout<<l-1<<endl;
}
