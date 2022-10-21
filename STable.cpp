#include <bits/stdc++.h>
using namespace std;
int f[3000000][22];
int n,m,l,r;

int l2g(int n){
    if(n==1)return 0;
    return(l2g(n/2)+1);
}

void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int len = r-l+1;
    int s = l2g(len);
    return min(f[l][s],f[r-(1<<s)+1][s]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i][0];
    }
    init();
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r);
    }
}