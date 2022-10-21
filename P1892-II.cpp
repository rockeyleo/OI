#include <bits/stdc++.h>
using namespace std;
int fa[1001],rk[1001];
int n,m;

int find(int a){
    if(fa[a] == a)return a;
    return(fa[a] = find(fa[a]));
}

void unit(int a,int b){
    int p = find(a), q = find(b);
    if(p == q)return;
    if(rk[p] == rk[q]){
        fa[p] = q;
        rk[q]++;
    }else if(rk[q]>rk[p]){
        fa[p] = q;
    }else{
        fa[q] = p;
    }
}

int main(){
    for(int i=1;i<=2*n;i++){ //若使用并查集反集，则需要在[n,2n]区间内存储反集信息，初始化*2
        fa[i] = i;
    }
    memset(rk,0,sizeof(rk));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        char opt; int a,b;
        cin>>opt;
        switch(opt){
            case 'F':{
                cin>>a>>b;
                unit(a,b);
                break;
            }
            case 'E':{
                cin>>a>>b;
                unit(a+n,b);
                unit(a,b+n);
                break;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){ //这些反集元素只在合并时有用，统计时仍按n来统计
        if(fa[i] == i)ans++;
    }
    cout<<ans;
}