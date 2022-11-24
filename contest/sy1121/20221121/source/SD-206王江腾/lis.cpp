#include<cstdio>
using namespace std;
const int MAXN=3e5+5;
int n,a[MAXN];
int len[MAXN];
int _len[MAXN];
inline int maxx(int a,int b){
	return a>b?a:b;
}
int res=0;
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)_len[i]=len[i]=1;
	for(int i=2;i<=n;i++)if(a[i]>a[i-1])len[i]=len[i-1]+1;
	for(int i=n-1;i>=1;i--)if(a[i]<a[i+1])_len[i]=_len[i+1]+1;
//	for(int i=1;i<=n;i++)printf("%d ",len[i]);printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",_len[i]);printf("\n");
	for(int i=1;i<=n;i++){
		res=maxx(res,_len[i+1]+1);
		res=maxx(res,len[i-1]+1);
		if(a[i-1]+2<=a[i+1])res=maxx(res,len[i-1]+1+_len[i+1]);
	}
	printf("%d\n",res);
	return 0;
} 
