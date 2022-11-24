#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[500005],step[500005],top=0;
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int flag=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	top++;
	step[top]=1;
	for(int i=2;i<=n;i++) {
		if(i!=n) {
			if(a[i-1]!=a[i]&&a[i]!=a[i+1]&&flag==0) {
				ans++;
				flag=1;
			}else{
				flag=0;
			}
		}
		if(a[i]!=a[i-1]) {
			top++;
			step[top]=i;
		}
	}
	for(int i=1;i<=top;i++) {
		if(step[i]&&step[i+1]&&step[i+2]) {
			a[step[i+1]]=a[step[i]];
			i+=2;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) {
		printf("%d ",a[i]);
	}
	return 0;
}

