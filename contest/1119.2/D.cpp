#include <bits/stdc++.h>
using namespace std;
const int M = 500010;
int f[M][28];
int n,q,k;
int l2g(int x){
	if(x==1)return 0;
	return(l2g(x/2)+1);
}

void init(){
	for(int i=1;i<=27;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[j][i] = max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
}

int query(int l,int r){
	int len = l2g(r-l+1);
	return max(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){
//	freopen("sample_d3.in","r",stdin);
//	freopen("sample_d3.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i][0]);
	}
//	for(int i=21;i<=35;i++){
//		cout<<i<<" "<<f[i][0]<<endl;
//	}
//	cout<<endl;
	init();
	while(q--){
		int s,t;
		int maxn = 0;
		scanf("%d%d",&s,&t);
		if(s==t){
			printf("Yes\n");
			continue;
		}else if(s<t){
			maxn = query(s+1,t);
		}else{
			maxn = query(t,s-1);
		}
//		cout<<s<<" "<<f[s][0]<<" "<<t<<" "<<maxn<<endl;
		if(maxn+f[s][0]<=k){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}
