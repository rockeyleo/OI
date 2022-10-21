#include <bits/stdc++.h>
using namespace std;
int n,m;
int fa[1001];
int cnt;
int rk[1001];
const int M = 10002;
int node[M],head[M],to[M],nxt[M];
int ans[1001];
void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f]  ;
    head[f] = cnt;
}

int find(int a){
    if(fa[a] == a){
        return a;
    }else{
        return (fa[a] = find(fa[a]));
    }
}   

void uin(int a,int b){
    int p = find(a);
    int q = find(b);
    // cout<<p<<":"<<q<<endl;
    // cout<<p<<q<<endl;
    if(p == q)return;
    if(rk[p]>rk[q]){
        fa[q] = p;
        ans[p] += ans[q];
    }else if(rk[p]==rk[q]){
        fa[p] = q;
        rk[q]++;
        ans[q] += ans[p];
    }else{
        fa[p] = q;
        ans[q] += ans[p];
    }
    // cout<<fa[a]<<" "<<fa[b]<<endl;
}

int main(){
    // freopen("P1892_1.in","r",stdin);
    int cc;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i] = i;
        ans[i] = 1;
    }
    for(int i=1;i<=m;i++){
        char opt; int a,b;
        cin>>opt;
        switch(opt){
            case 'F':{
                scanf("%d",&a);
                scanf("%d",&b);
                uin(a,b);
                break;
            }
            case 'E':{
                scanf("%d",&a);
                scanf("%d",&b);
                add(a,b);add(b,a);
                cc++;
                break;
            }
        }
    }
    // cout<<cc<<endl;
    for(int i=1;i<=n;i++){
        for(int now = head[i];now;now = nxt[now]){
            // cout<<i<<"->"<<to[now]<<endl;
            if(nxt[now]){
                // cout<<1<<endl;
                uin(to[now],to[nxt[now]]);
            }
        }
    }
    int out = 0;
    for(int i=1;i<=n;i++){
        // cout<<i<<":"<<fa[i]<<endl;  
        if(fa[i] == i){
            out++;
            // out = max(out,ans[i]);
        }
    }
    cout<<out;
}