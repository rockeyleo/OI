#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5+3;
int n,a[N],b[N];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag;
	for(int ans=1;ans<=n;ans++){
		flag=true;
		b[1]=a[1];
		b[n]=a[n];
		for(int i=2;i<n;i++){
			if(a[i]==1){
				if(a[i-1]==1||a[i+1]==1) b[i]=1;
				else{
					b[i]=0;
					flag=false;
				}
			}else{
				if(a[i-1]==0||a[i+1]==0) b[i]=0;
				else{
					b[i]=1;
					flag=false;
				}
			}
		}
		memcpy(a,b,sizeof(a));
		if(flag){
			printf("%d\n",ans-1);
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
			break;
		}
	}
	if(!flag){
		printf("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
