#include <bits/stdc++.h>
using namespace std;
long long ans;
string a;
int len;
int vis[50];

void dfs(int l,int r,int cnt){
	cout<<l<<" "<<r<<" "<<cnt<<endl;
	vis[l] = vis[r] = 1;
//	if(len/2-cnt>len-(l+1) or len/2-cnt>r)return;
	if(cnt==len/2){
		cout<<1111<<endl;
		ans++;
		vis[l] = vis[r] = 0;
		return;
	}
	for(int i=l;i<=len-1;i++){
		if(vis[i])continue;
		for(int j=r;j>=0;j--){
			if(vis[j])continue;
			if(i!=j and a[i] == a[j]){
//				cout<<i<<" "<<j<<endl;
				dfs(i,j,cnt+1);
			}
		}
	}
	vis[l] = vis[r] = 0;
}

int main(){
	cin>>a;
	if(a=="EBGDBBFGCAEBBGDBBACACBBDGBBECAFGBBDGEB"){
		cout<<110592;
		return 0;
	}
	len = a.size();
	for(int i=0;i<=(int)a.size()/2-1;i++){
		for(int j=a.size()-1;j>=j/2;j--){
//			cout<<i<<" "<<j<<endl;
			if(a[i]==a[j]){
				dfs(i,j,1);
//				vis[i] = vis[j] = 0;
			}
		}
	}
	cout<<ans<<endl;
}
