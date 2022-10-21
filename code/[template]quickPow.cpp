#include <bits/stdc++.h>
using namespace std;

long long qpow(long long a, long long n){
    long long ans = 1;
    while(n){
        if(n&1)
            ans*=a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main(){
    cout<<qpow(3,9);
}