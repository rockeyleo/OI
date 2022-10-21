#include <bits/stdc++.h>
using namespace std;
int p[500100];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int f,t;
        cin>>f>>t;
        p[f]++; p[t]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(p[i]%2==1){
            ans ++;
        }
    }
    if(ans==0){
        cout<<1<<endl;
    }else{
        cout<<ans/2<<endl;
    }
}