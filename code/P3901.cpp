
#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
int f[M][24];
int n,m,q;
int num[M],pre[M],tb[M];

int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

int l2g(int a){
    if(a==1)return 0;
    return (l2g(a/2)+1);
}

void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int find(int l,int r){
    int len = l2g(r-l+1);
    return max(f[l][len],f[r-(1<<(len))+1][len]);
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        num[i] = read();
        pre[i] = tb[num[i]];
        tb[num[i]] = i;
    }
    for(int i=1;i<=n;i++){
        f[i][0] = pre[i];
    }
    init();
    for(int i=1;i<=q;i++){
        int l,r;
        l = read(); r = read();
        int tmp = find(l,r);
        if(tmp<l){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}