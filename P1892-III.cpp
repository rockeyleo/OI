#include <bits/stdc++.h>
using namespace std;
int n,m;
int fa[2002]; //因为有反集，fa要开两倍
// int cnt;
// int rk[1001];
// const int M = 10002;
// int node[M],head[M],to[M],nxt[M];
// int ans[1001];

int find(int a){
    if(fa[a] == a){
        return a;
    }else{
        return (fa[a] = find(fa[a]));
    }
}   

// void uin(int a,int b){
//     int p = find(a);
//     int q = find(b);
//     // cout<<p<<":"<<q<<endl;
//     // cout<<p<<q<<endl;
//     if(p == q)return;
//     if(rk[p]>rk[q]){
//         fa[q] = p;
//         // ans[p] += ans[q];
//     }else if(rk[p]==rk[q]){
//         fa[p] = q;
//         rk[q]++;
//         // ans[q] += ans[p];
//     }else{
//         fa[p] = q;
//         // ans[q] += ans[p];
//     }
//     // cout<<fa[a]<<" "<<fa[b]<<endl;
//     if(a<b){
//         fa[b] = a;
//     }else{
//         fa[a] = b;
//     }
// }

int main(){
    // freopen("P1892_1.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n*2;i++){
        fa[i] = i;
        // ans[i] = 1;
    }
    for(int i=1;i<=m;i++){
        char opt; int a,b;
        cin>>opt;
        switch(opt){
            case 'F':{
                // cin>>a>>b;
                scanf("%d",&a);
                scanf("%d",&b);
                fa[find(a)] = find(b);
                // uin(a,b);
                break;
            }
            case 'E':{
                // cin>>a>>b;
                // add(a,b);add(b,a);
                // uin(a+n,b);
                // uin(a,b+n);
                // cc++;
                scanf("%d",&a);
                scanf("%d",&b);
                fa[find(b+n)] = a;
                fa[find(a+n)] = b;
                break;
            }
        }
    }
    int out = 0;
    for(int i=1;i<=n;i++){
        // cout<<i<<":"<<fa[i]<<endl;
        if(fa[i] == i){
            // cout<<i<<endl;
            out++;
            // out = max(out,ans[i]);
        }
    }
    cout<<out;
}