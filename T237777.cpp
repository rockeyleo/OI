#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans=0;
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        string usr;
        cin>>usr;
        string chat;
        cin>>chat;
        if(chat=="/oh"){
            ans+=a;
        }else if(chat=="/hsh"){
            ans+=b;
        }
    }
    cout<<ans;
}