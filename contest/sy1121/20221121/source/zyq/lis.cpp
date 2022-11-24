#include<bits/stdc++.h>
using namespace std;
const int maxn = 103, INF = 0x7f7f7f7f;
int a[maxn], f[maxn];
int n,ans = -INF;
int main()
{
	freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
    {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j]+1);
    for(int i=1; i<=n; i++) 
        ans = max(ans, f[i]);
    for(int i=1; i<=n; i++) {
    	for(int j=1;j<=n;j++){
    		if(a[i]>a[i+1]&&a[i+1]==f[j]){
    			a[i]=a[i+1]-1;
				ans++;
				printf("%d\n", ans);
				return 0;	
			}
		}
	}
    printf("%d\n", ans);
    return 0;
}
