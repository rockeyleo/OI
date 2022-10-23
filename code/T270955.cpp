#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        n+=1;
        if(n%3==0)n/=3;
    }
    cout<<n<<endl;
}