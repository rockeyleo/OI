#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=1;
long long a[300001];
bool flag;
int main(){
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<n;++i){
        if(n-i+1<=ans)break;
        flag=1;
        for(int j=i;j<=n;++j){
            if(j==n){
                ans=max(ans,j-i+1);
                break;
            }
            if(a[j+1]<=a[j]){
                if(flag){
                    if(a[j+1]-a[j-1]>=2){
                        flag=0;
                        continue;
                    }
                    else if(j+2<=n){
                        if(a[j+2]-a[j]>=2){
                            flag=0;
                            ++j;
                            continue;
                        }
                        else{
                            ans=max(ans,j-i+2);
                            break;
                        }
                    }
                    else{
                        ans=max(ans,j-i+2);
                        break;
                    }
                }
                else {
                    ans=max(ans,j-i+1);
                    break;
                }
            }
        }
        if(a[i]>=a[i+1]){
            for(int j=i+1;j<=n;++j){
                if(j==n){
                    ans=max(ans,j-i+1);
                    break;
                }
                if(a[j+1]<=a[j]){
                    ans=max(ans,j-i+1);
                    break;
                }
            }
        }
    }
    printf("%d",ans);
    return [](){return 0;}();
}