#include <bits/stdc++.h>
using namespace std;
const int M = 50010;
struct node{
    int l,r,sum,lzy;
}tree[M*4];

int a[M],n,m;

void pushup(int u){
    tree[u].sum = tree[u*2]+tree[u*2+1];
}

void pushdown(int u){
    if(tree[u].lzy){
        int l = tree[u].l, r = tree[u].r, mid = tree[u].l+tree[u].r>>1;
        tree[u*2].lzy = tree[u*2+1].lzy = tree[u].lzy;
        tree[u*2].sum += tree[u].lzy*(mid-l+1), tree[u*2+1].sum += tree[u].lzy*(r-mid);
    }
    tree[u].lzy = 0;
}

void modify(int u,int a,int b,int d){
    
    auto auto &l = tree[u*2], &r = tree[u*2+1], &t = tree[u];
    
}

void build(int u=1,int l=1,int r=n){
    if(l==r){
        tree[u] = {l,r,a[l],0};
    }else{
        tree[u] = {l,r};
        int mid = l+r>>1;
        build(u*2,l,mid),build(u*2+1,mid+1,r);
        pushup(u);
    }
}

int query(int u,int a,int b){
    auto &l = tree[u*2], &r = tree[u*2+1], &t = tree[u];
    if(t.l>=a and t.r<=b)return t.sum;
    if(t.l>b or t.r<a)return 0;
    pushdown(u);
    return query(u*2,a,b)+query(u*2+1,a,b);
}

int main(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        cin>>op>>l>>r;
        if(op == 'C'){
            cin>>d;
            modify(1,l,r,d);
        }else{
            cout<<query(1,l,r)<<endl;
        }
    }
}