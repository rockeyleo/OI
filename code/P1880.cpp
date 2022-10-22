#include <bits/stdc++.h>
using namespace std;
const int M = 505;
int pre[M],num[M],f[M][M],p[M][M];
int main(){
    int n;
    cin>>n;
    memset(p,0x3f,sizeof(p));
    for(int i=1;i<=n;i++){
        cin>>num[i];
        num[i+n] = num[i];
        f[i][i] = p[i][i] = f[i+n][i+n] = p[i+n][i+n] =  0;
    }
    for(int i=1;i<=n*2;i++){
        pre[i] = pre[i-1]+num[i];
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n*2;i++){
            int j = i+len-1;
            for(int k=i;k<j;k++){
                f[i][j] = max(f[i][j],f[i][k]+f[k+1][j]+(pre[j]-pre[i-1]));
                p[i][j] = min(p[i][j],p[i][k]+p[k+1][j]+(pre[j]-pre[i-1]));
            }
        }
    }
    int ans1 = 0x3f3f3f3f, ans2 = 0;
    for(int i=1;i<=n;i++){
        ans1 = min(ans1,p[i][i+n-1]);
        ans2 = max(ans2,f[i][i+n-1]);
    }
    cout<<ans1<<"\n"<<ans2<<endl;
}