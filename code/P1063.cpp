#include <bits/stdc++.h>
using namespace std;
const int M = 303;
int num[M],f[M][M];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        num[i+n] = num[i];
    }
    for(int l=2;l<=n+1;l++){
        for(int i=1;i+l-1<=n*2;i++){
            int j = i+l-1;
            for(int k = i+1;k<j;k++){
                f[i][j] = max(f[i][j],f[i][k]+f[k][j]+num[i]*num[k]*num[j]);
                // cout<<f[i][k]+f[k+1][j]+num[i]*num[k]*num[j]<<endl;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,f[i][i+n]);
    }
    cout<<ans<<endl;
}