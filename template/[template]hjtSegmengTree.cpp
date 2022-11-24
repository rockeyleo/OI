#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 10010;
vector<int> nums;
struct node{
	int cnt;
	int l,r;
}tr[N*4+N*17];
int root[M],idx;
int a[N];
int find(int x){
	return lower_bound(nums.begin(),nums.end(),x) - nums.begin();
}

int build(int l,int r){
	int p = ++idx;
	if(l==r) return p;
	int mid = l+r>>1;
	tr[p].l = build(l,mid), tr[p].r = build(mid+1,r);
	return p;
} 

int insert(int p, int l,int r,int x){
	int q = ++idx;
	tr[q] = tr[p];
	if(l=r){
		tr[q].cnt++;
		return q;
	}
	int mid = l+r>>1;
	if(x<=mid)tr[q].r = insert(tr[p].r,
} 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin<<a[i]
		nums.puss_back(a[i]);
	}
	sort(nums.begin(),nums.end());
	nums.erase(unique(nums.begin(),nums,end()));
	
	root[0] = build(0,nums.size()-1);
	
	for(int i=1;i<=n;i++){
		
	}
}
