#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
int bs[M],cnt;
int num[M];
int maxp;

void add(int k,int i){
	if(num[k]==0){
		num[k]=1;
		bs[i]=1;
	}else{
		int p = k;
		while(num[p]!=0){
			num[p]=0;
			p++;
		}
		num[p] = 1, maxp = max(maxp,p);
		bs[i] = p-k+1;
	}
}
//clock_t start,ed;
int main(){
//	freopen("sample_bin3.in","r",stdin);
//	freopen("sample_bin3.out","w",stdout);
//	start = clock();
	string tmp;
	int n,m;
	cin>>n;
	cin>>tmp;
	maxp = n;
	for(int i=n-1;i>=0;i--){
		num[cnt++] = tmp[i]-'0';  //注意下标全从零开始
//		cout<<num[cnt]<<endl;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		add(k,i);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",bs[i]);
	}
	for(int i=maxp;i>=0;i--){
		printf("%d",num[i]);
	}
//	cout<<endl;
//	ed = clock();
//	cout<<(double)(ed-start)/CLOCKS_PER_SEC<<"s"<<endl;
}
