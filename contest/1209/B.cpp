#include <bits/stdc++.h>
using namespace std;
int main(){
    string tmp;
    cin>>tmp;
    long long a = tmp[0]-'0', b = tmp[1]-'0', c = tmp[2]-'0';
    cout<<(a+b+c)<<endl;
    cout<<(long long)(a+b+c)*(a+b+c)<<endl;
    cout<<(long long)(a+b+c)*(a+b+c)*(a+b+c)<<endl;
}