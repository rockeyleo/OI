#include <bits/stdc++.h>
using namespace std;
int a,b;

int sgn(int x){
    if(x>0)return 1;
    if(x<0)return -1;
    return -1;
}

int abs(int x){
    if(x<0)return -x;
    return x;
}

int main(){
    cin>>a>>b;
    cout<<abs(a)*sgn(b);
}