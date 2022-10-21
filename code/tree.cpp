#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;

int num[M];
#define ll long long
ll tree[4*M],lzy[4*M];

void pushup(int u){
    tree[u] = tree[u*2]+tree[u*2+1];
}

void tag(int u,int l,int r,ll v){
    lzy[u]+=v;
    tree[u]+=(r-l+1)*v;
}

void pushdown(int u,int l,int r){
    int m = (l+r/2);
    tag(u*2,l,m,lzy[u]);
    tag(u*2+1,m+1,r,lzy[u]);
    lzy[u] = 0;
}

int build(int l,int r,int u){
    lzy[u] = 0;
    if(l == r){
        tree[u] = num[l];
        return 0;
    }
    int m = (l+r)/2;
    build(l,m,u*2);
    build(m+1,r,u*2+1);
    pushup(u);
}

ll query(int L,int R,int l,int r,int u){
    if(l>R and r<L)return 0;
    if(l<=L and r>=R){
        return(tree[u]);
    }
    int mid = (L+R)/2;
    pushdown(u,L,R);
    return(query(L,mid,l,r,u*2)+query(mid+1,R,l,r,u*2+1));
}

void update(int u,int L,int R,int l,int r,ll v){
    if(l<=L and r>=R){
        tag(u,L,R,v);
        return;
    }
    if(l>R or r<L)return;
    int mid = (L+R)/2;
    pushdown(u,L,R);
    update(u*2,L,mid,l,r,v);
    update(u*2+1,mid+1,R,l,r,v);
    pushup(u);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        int x,y,k;
        switch(op){
            case 1:
                
                cin>>x>>y>>k;
                break;
            case 2:
                // int x,y;
                cin>>x>>y;
                printf("%d",query(1,n,x,y,1));
                break;
        }
    }
}