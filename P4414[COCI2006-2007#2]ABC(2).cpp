#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans[4],n=1,a,b,c,t[4];
    string mod;
    cin>>t[1]>>t[2]>>t[3];
    sort(t+1,t+4);
    cin>>mod;
    for(auto i:mod){
        if(i=='A'){
            ans[n++]=t[1];
        }else if(i=='B'){
            ans[n++]=t[2];
        }else if(i=='C'){
            ans[n++]=t[3];
        }
    }
    for(int i=1;i<=3;i++){
        cout<<ans[i]<<' ';
    }
}