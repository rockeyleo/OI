#include <bits/stdc++.h>
using namespace std;
const int M = 510;
int f[M][M],a[M];
pair<int,int>p[M];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        p[i].first = a[i];
        p[i].second = i==n?a[1]:a[i+1];
        p[i+n] = p[i];
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l+i-1<=n*2;l++){
            int r = l+i-1;
            for(int k=l;k<r;k++){
                f[l][r] = max(f[l][r],f[l][k]+f[k+1][r]+p[l].first*p[k+1].first*p[r].second);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,f[i][i+n-1]);
    }
    cout<<ans<<endl;
}