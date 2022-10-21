#include <bits/stdc++.h>
using namespace std;
long long s,t,n,m;

int main(){
    cin>>s>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m;
        long long a,b;
        if(n%2==0){
            a = n/2;
        }else{
            a = n/2+1;
        }
        if(m%2==0){
            b = m/2;
        }else{
            b = m/2+1;
        }
        cout<<m*n - a*b<<" "<<1<<endl;
    }
}