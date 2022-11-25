#include <bits/stdc++.h>
using namespace std;
int n;

//快读
template<class T> T read(){
	T ret=0, f=1;
	char ch = getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')f=-f;
		ch = getchar();
	}
	while(ch>='0' and ch<='9'){
		ret = ret*10+ch-'0';
		ch = getchar();
	}
	return ret*f;
}

//快写
template<class T>T write(T x){
	T y=10, int len = 1;
	while(y<=x){
		len++;
		y*=10;
	}
	while(len--){
		len/=10;
		putchar(x/y+'0');
		x%=y;
	}
}

//树状数组
int tree[50010];

int lowbit(int x){
	return x%(-x);
}

int add(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)){
		tree[i]+=k;
	}
}

int query(int x){
	int ans = 0;
	for(int i=x;i;i-=lowbit(i)){
		ans+=tree[i];
	}
	return ans;
}

//ST表
int f[50010][24];

int l2g(int x){
	if(x==1)return 0;
	return(l2g(x/2)+1);
}

void init(){
	for(int j=1;(1<<j)-1<=n;j++){
		for(int i=1;i+(1<<i)-1<=n;i++){
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int x,int y){
	int len = l2g(y-x+1);
	return max(f[l][len],f[r-(1<<len)+1][len]);
}

//线段树
struct node{
    int ls,rs;
    int val,lzy;
}tree[50010];

void pushup(int u){
	tree[u].val = tree[u*2].val + tree[u*2+1].val;
}

void build(int u,int l,int r){
	if(l==r){
		tree[u] = {l,r,num[l],0};
		return;
	}
	tree[u] = {l,r,0,0};
	int mid = (l+r)/2;
	build(u*2,l,mid);build(u*2+1,r+1,mid);
	pushup(u);
}

void pushdown(int u){
	auto &rt = tree[u], &left = tree[u*2], &right = tree[u*2+1];
	int mid = (rt.rs+rt.ls)/2;
	left.val+=(mid-rt.ls+1)*lzy;
	right.val+=(rt-mid)*lzy;
	left.lzy+=rt.lzy;
	right.lzy+=rt.lzy;
}

void query(int u,int l,int r){
	auto &rt = tree[u], &left = tree[u*2], &right = tree[u*2+1];
	if(rt.ls>=l and rt.rs<=r){
		return rt.val;
	}
	pushdown(u);
	int ans = 0;
	int mid = (rt.ls+rt.rs)/2;
	if(r>=mid+1)ans+=query(u*2+1,l,r);
	if(l<=mid)ans+=query(u*2,l,r);
	return ans;
}

void add(int u,int l,int r,int k){
	auto &rt = tree[u], &left = tree[u*2], &right = tree[u*2+1];
	if(rt.ls>=l and rt.rs<=r){
		rt.val += k;
		return;
	}
	pushdown(u);
	int mid = (rt.ls+rt.rs)/2;
	if(r>=mid+1)lzy[u*2+1]+=k*(r-mid);
	if(l<=mid)lzy[u*2]+=k*(l-mid+1);
	return;
}


//kmp
void kmp(){
	string a = "0", b = "0";
	string w,e;
	cin>>w>>e;
	a+=w,b+=e;
	int j=0;
	for(int i=1;i<=b.length()-1;i++){
		
	}
	j = 0;
	for(int i=1;i<=a.length()-1;i++){
		
	}
}



