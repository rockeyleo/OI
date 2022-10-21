#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e;
    scanf("%d%*c%d%*c%d%*c%d%*c%d",&a,&b,&c,&d,&e);
    string tmp = to_string(a)+'.'+to_string(b)+'.'+to_string(c)+'.'+to_string(d)+':'+to_string(e);
    cout<<tmp;
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
}