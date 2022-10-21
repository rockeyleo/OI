#include <bits/stdc++.h>
using namespace std;
int main(){
    long long l,r,x;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l>>r>>x;
        if(l/x == r/x){cout<<l/x<<endl;}
        else cout<<1<<endl;
    }
    return 0;
}