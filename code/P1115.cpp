#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d,tmp,ans=-10101010;
    cin>>d;
    tmp = d;
    for(int i=2;i<=n;i++){
        cin>>tmp;
        d = max(tmp,tmp+d);
        ans = max(ans,d);
    }
    cout<<ans;
}