#include <bits/stdc++.h>
using namespace std;
long long num[5001];

int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

// long long read(){
//     int f=1;char ch=getchar();long long ret=0;
//     while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
//     while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
//     return ret*f;
// }
//如果数字很大，那么快读也要加long long

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        num[i] = read();
    }
    for(int i=1;i<=n;i++)printf("%lld\n",num[i]);
}