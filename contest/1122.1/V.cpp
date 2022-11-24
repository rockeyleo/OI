#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
const int M = 5050;
int num[M];
int mmu[M];
//int mp[600001];
__gnu_pbds::gp_hash_table<int,int>mp;
//unordered_map<int,int> mp;
//int pre[M];
//int pre1[M];
//int pre2[M];
int ans[M];
int val[M];
unsigned long long prime=1313629191111;
const int mod = 998244353;
int len;
clock_t st,ed;

unsigned long long hh(){
	unsigned long long ans = 0;
	for (int i=1;i<=len;i++)
       	ans=(ans*131+num[i])%mod+prime;
	return ans;
}

int read(){
	int ret = 0; char ch = getchar();
	while(ch<'0' or ch>'9'){ch = getchar();}
	while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
	return ret;
}

void del(int x){
	memcpy(num+x,num+x+1,(len-x)*sizeof(num[0]));
	memcpy(val+x,val+x+1,(len-x)*sizeof(val[0]));
	len--;
}

void back(int x,int k,int q){
	memcpy(num+x+1,num+x,(len-x+1)*sizeof(num[0]));
	memcpy(val+x+1,val+x,(len-x+1)*sizeof(val[0]));
	num[x] = k;
	val[x] = q;
	len++;
}

//void getpre(int len){
//	for(int i=1;i<=len;i++){
//		pre[i] = pre[i-1]+num[i];
//	}
//	pre1[1] = num[1]; pre[2] = num[2];
//	for(int i=3;i<=len;i++){
//		if(i%2==0){
//			pre2[i] = pre2[i-2]+num[i];
//			pre1[i] = pre1[i-1];
//		}else{
//			pre1[i] = pre1[i-2]+num[i];
//			pre2[i] = pre2[i-1];
//		}
//	}
//}

pair<int,int> mx(pair<int,int>a,pair<int,int>b){
	return a.first>b.first?a:b;
}

int getans(){
	memcpy(mmu+1,num+1,(len)*sizeof(num[0]));
	sort(mmu+1,mmu+len+1,[](int a,int b){return a>b;});
	int ans = 0;
	for(int i=1;i<=len;i+=2){
		ans += mmu[i];
//		cout<<i<<" "<<mmu[i]<<endl;
	}
	return ans;
}

void dfs(int dl,int tar,int pp=0){
	ed = clock();
//	cout<<(ed-st)/CLOCKS_PER_SEC<<endl;
	if((double)(ed-st)/CLOCKS_PER_SEC>2){
		return;
	}
	int h = hh();
//	cout<<h<<endl;
	if(mp[h]==1){
//		cout<<1111<<endl;
		return;
	}
	mp[h]=1;
//	for(int i=1;i<=len;i++){
//		cout<<num[i]<<" ";
//	}
//	cout<<endl;
//	cout<<getans()<<" "<<pp<<endl;
	if(dl == tar){
		ans[tar] = max(ans[tar],getans()-pp);
//		mp[h]=0;
		return;
	}
	if(getans()-pp>ans[dl]){
//		cout<<1111<<endl;
		return;
	}
	for(int i=1;i<=len;i++){
		int tmp = num[i];
		int kk = val[i];
//		cout<<"val["<<i<<"]="<<kk<<endl;
		del(i);
		dfs(dl+1,tar,pp+kk);
		back(i,tmp,kk);
	}
//	mp[h]=0;
}

int n;
int a[M],b[M];

int main(){
//	freopen("b0.in","r",stdin);
//	freopen("b0.out","w",stdout);
	cin>>n;
	st = clock();
	len = n;
	for(int i=1;i<=n;i++){
		num[i] = read();
		ans[i] = -0x3f3f3f3f;
	}
	ans[n] = 0;
	for(int i=1;i<=n;i++){
		val[i] = read();
		ans[len] -= val[i];
	}
//	getpre(len);
	ans[0] = getans();
	
	cout<<ans[0]<<endl;
	for(int i=1;i<=n-1;i++){
		mp.clear();
		dfs(0,i);
		printf("%d\n",ans[i]);
//		cout<<endl;
	}
	cout<<ans[n]<<endl;
}
