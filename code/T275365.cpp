#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        unsigned long long ans = 0;
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;j++){
            // cout<<tb[j]<<" ";
            ans+=tb[j]-'0';
        }
        cout<<ans<<endl;
    }
}