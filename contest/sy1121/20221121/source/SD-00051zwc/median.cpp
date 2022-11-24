#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[2][N];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a[0]+i);
	int ans=0,cnt=0;
	int pre=0,now=1;
	while(1){
		if(cnt%50==0){
			if((double)clock()/CLOCKS_PER_SEC>1.5){
				puts("-1");
				return 0;
			}
		}
		a[now][1]=a[pre][1],a[now][n]=a[pre][n];
		for(int i=2;i<n;i++)a[now][i]=(a[pre][i-1]==a[pre][i+1]?a[pre][i-1]:a[pre][i]);
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[pre][i]!=a[now][i]){
				flag=0;
				break;
			}
		}
		if(flag)break;
		ans++,cnt++;
		pre^=1,now^=1;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",a[pre][i]);
	puts("");
	return 0;
}
