#include <bits/stdc++.h>
using namespace std;
const int M = 500000;
int f[M][24];
int n,m;

int l2g(int a){
    if(a==1)return 0;
    return (l2g(a/2)+1);
}

void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int find(int l,int r){
    int len = l2g(r-l+1);
    return min(f[l][len],f[r-(1<<(len))+1][len]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i][0];
    }
    init();
    for(int i=2;i<=n;i++){
        int l,r;
        cin>>l>>r;
        cout<<find(l,r);
    }
}
