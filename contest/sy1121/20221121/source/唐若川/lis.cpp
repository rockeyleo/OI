#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[300005],top=0,sh[300005],n;
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]<=a[i-1]) {
			top++;
			sh[top]=i-1;
		}
	}
	top++;
	sh[top]=n;
	int maxnn=0;
	for(int i=1;i<top;i++) {
		if(a[sh[i]+2]-a[sh[i]]>=2) {
			maxnn=max(maxnn,sh[i+1]-sh[i-1]);
		}
	}
	printf("%d\n",maxnn);
	return 0;
}
/*
7 2 3 1 5 6
1 3 6
*/
