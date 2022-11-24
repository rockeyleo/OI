#include <bits/stdc++.h>
using namespace std;
const int M = 5050;
int dp[1001][1001]; //dp[i][j]表示前i个元素删去j个后的最大得分
pair<int,int> num[M];
int val[M];
int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret;
}
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp = read();
		num[i] = {i,tmp};
	}
	for(int i=1;i<=n;i++){
		val[i] = read();
	}
	sort(num+1,num+1+n,[](pair<int,int> a,pair<int,int>b){return a.second>b.second;});
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = max(dp[i-1][j],dp)
		}
	}
	
}
