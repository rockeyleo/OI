#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3e5+3;
int n,a[N];
int vis[N],cnt,cant;
inline void update(int p){
	if(a[p]>=a[p-1]&&a[p]>=a[p+1]){
		if(a[p+1]>a[p-1]+1){
			cnt++;
			vis[p]=1;
		}else{
			cant++;
			vis[p]=3;
		}
	}else if(a[p]<=a[p-1]){
		if(a[p]<=a[p+1]){
			if(vis[p-1]==1) return;
			if(a[p+1]>a[p-1]+1){
				cnt++;
				if(vis[p-1]==3) cant--;
				vis[p]=2;
			}else{
				cant++;
				vis[p]=4;
			}
		}else{
			cant++;
			vis[p]=5;
		}
	}
	return;
}
inline void reupdate(int p){
	if(a[p]>=a[p-1]&&a[p]>=a[p+1]){
		if(a[p+1]>a[p-1]+1){
			cnt--;
		}else{
			cant--;
		}
	}else if(a[p]<=a[p-1]){
		if(a[p]<=a[p+1]){
			if(vis[p-1]==1) return;
			if(a[p+1]>a[p-1]+1){
				cnt--;
				if(vis[p-1]==3) cant++;
			}else{
				cant--;
			}
		}else{
			cant--;
		}
	}
	return;
}
inline bool check(int len){
	if(len==1) return true;
	memset(vis,0,sizeof(vis));
	cnt=cant=0;
	for(int i=2;i<len-1;i++){
		if(len>2) update(i);
	}
	for(int r=len;r<=n;r++){
		int l=r-len+1;
		if(len>2) update(r-1);
		if(l>1&&len>2) reupdate(l);
		int tmp1=0,tmp2=0;
		if(len>2){
			if(a[l]>=a[l+1]&&vis[l+1]!=2){
				tmp1++;
				if(vis[l+1]==4) tmp2++;
			}
			if(a[r-1]>=a[r]&&vis[r-1]!=1){
				tmp1++;
				if(vis[r-1]==3) tmp2++;
			}
		}else{
			if(a[l]>=a[l+1]){
				tmp1++;
			}
		}
		if(cant-tmp2==0&&cnt+tmp1<=1) return true;
	}
	return false;
}
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
注意到若有长的子串满足题意，则一定可以找到比他短的子串满足
因此答案具有单调性
二分答案 

6
7 2 3 1 5 6

5
5 3 2 5 6

5
10 1 5 3 5

5
10 2 5 1 1

5
10 1 4 3 6

4
1 6 3 1

2
3 1

3
10 1 5

6
10 9 3 4 4 6
*/
