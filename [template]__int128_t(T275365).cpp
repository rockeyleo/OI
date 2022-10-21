#include <bits/stdc++.h>
using namespace std;

__int128_t read(){
    int f=1;char ch=getchar();__int128 ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

void write(__int128_t x){
    __int128_t y=10,len=1;
    while(y<=x){y*=10;len++;}
    while(len--){y/=10;putchar(x/y+48);x%=y;}
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        __int128_t l = read();
        __int128_t r = read();
        __int128_t ch = r-l+1;
        if(l%2==1){
            if(ch%2==0){
                write(ch/2);
                printf("\n");
            }else{
                write(ch/2+1);
                printf("\n");
            }
        }else{
            write(ch/2);
            printf("\n");
        }
    }
    // int n;
    // cin>>n;
    // cout<<f(n)<<endl;
}