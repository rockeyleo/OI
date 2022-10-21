#include <bits/stdc++.h>
using namespace std;
const int M = 10000;
int num[M];
int f[M][M];

int l2g(int a){
    if(a==1)return 0;
    return (l2g(a/2)+1);
}

int main(){
    int n=1,l,r,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    // int in;
    // while(cin>>in){
    //      num[n++]=in;
    // }
    for(int i=1;i<=n;i++){
        f[i][0]=num[i];
    }
    // cin>>l>>r;
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    cout<<0<<endl;
    for(int i=2;i<=n;i++){
        if(i-m<=0){
            l=1;r=i;
        }else{
            l=i-m;r=i-1;    //不包括a_i自己
        }
        int len = l2g(r-l+1);
        cout<<min(f[l][len],f[r-(1<<(len))+1][len])<<endl;
    }
}