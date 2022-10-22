#include <bits/stdc++.h>
const int M = 500;
int pre[M],f[M][M],num[M];
using namespace std;
int main(){
    int n;
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>num[i];
        pre[i] = pre[i-1]+num[i];
        f[i][i] = 0;
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j = l+i-1;
            for(int k=i;k<j;k++){
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+pre[j]-pre[i-1]);
            }
        }
    }
    cout<<f[1][n];
}