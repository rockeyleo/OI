#include<cstdio>
using namespace std;
const int MAXN=5e5+5;
int n,a[MAXN];
int b[MAXN];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int res=0,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)b[i]=-1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			cnt++;
		}else{
			if(cnt){
				if(cnt>res)res=cnt;
				int r=i-1;
				int l=r-cnt;
				int len=r-l+1;
				if(len&1){
					for(int i=l;i<=r;i++)b[i]=a[l];
				}else{
					for(int i=l;i<=l+(len>>1);i++)b[i]=a[l];
					for(int i=r-(len>>1)+1;i<=r;i++)b[i]=a[r];
				}
			}
			cnt=0;
		}
	}
	if(cnt){
		if(cnt>res)res=cnt;
		int r=n;
		int l=r-cnt;
		int len=r-l+1;
//		printf("Update [%d,%d]\n",l,r);
		if(len&1){
			for(int i=l;i<=r;i++)b[i]=a[l];
		}else{
			for(int i=l;i<=l+(len>>1);i++)b[i]=a[l];
			for(int i=r-(len>>1)+1;i<=r;i++)b[i]=a[r];
		}
	}
	printf("%d\n",res/2);
	for(int i=1;i<=n;i++)printf("%d ",b[i]==-1?a[i]:b[i]);
	return 0;
} 
