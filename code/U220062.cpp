#include <bits/stdc++.h>
using namespace std;
int md = 998244353;
int main(){
    int n,p;
    cin>>n>>p;
    unsigned long long ans = 0;
    for(int i=1;i<=n;i++){
        ans+=((n/i)*(i%p));
    }
    // cout<<ans<<endl;
    ans = ans%md;
    cout<<ans<<endl;
}