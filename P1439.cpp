#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+5;
int rk[M],dp[M];
int a[M],b[M],b2[M];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        rk[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        b2[i] = rk[b[i]];
        // cout<<b2[i]<<" ";
    }
    vector<int>dp;
    dp.push_back(b2[1]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b2[j]>dp[cnt]){dp[++cnt]=b2[j];}
            else{
                
            }
        }
    }
    int ans = 1;
    for(int i=1;i<=n;i++){
        // cout<<dp[i]<<" ";
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}