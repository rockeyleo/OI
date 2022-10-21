#include <bits/stdc++.h>
using namespace std;
int f[1001][24];
int n,m;

int l2g(int a){
    if(a==1)return 0;
    return(l2g(a/2)+1);
}

int gcd(int a,int b){
    int x,y;
    if(a>b){
        x = a, y = b;
    }else{
        x = b, y= a;
    }
    return y==0?x:gcd(y,x%y);
}

int read(){
    int ret=0,f=1,ch = getchar();
    while(ch<'0' or ch>'9'){if(ch=='-'){f==-f;}ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j] = gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int find(int l,int r){
    int len = l2g(r-l+1);
    return gcd(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i][0] = read();
    }
    init();
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        printf("%d\n",find(l,r));
    }
}