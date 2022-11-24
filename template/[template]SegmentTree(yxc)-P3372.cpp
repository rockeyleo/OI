#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int M  = 100005;
struct node{
    int l,r;
    LL sum,add;
}tr[M*4];
int w[M];
int n,m;

void pushup(int u){
    tr[u].sum = tr[u*2].sum+tr[u*2+1].sum;
}

void pushdown(int u){
    auto &root = tr[u], &left = tr[u*2], &right = tr[u*2+1];
    if(root.add){
        left.add += root.add, left.sum += (LL)(left.r - left.l +1)*root.add;
        right.add += root.add, right.sum+= (LL)(right.r - right.l +1)*root.add;
        root.add = 0;
    }
}

void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l,r,w[r],0};
    }else{
        tr[u] = {l,r};
        int mid = (l+r)/2;
        build(u*2,l,mid),build(u*2+1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l and tr[u].r<=r){
        tr[u].sum += (LL)(tr[u].r-tr[u].l +1)*d;
        tr[u].add += d;
    }else{
        pushdown(u);
        int mid = (tr[u].l+tr[u].r)/2;
        if(l <= mid)modify(u*2,l,r,d);
        if(r>mid)modify(u*2+1,l,r,d);
        pushup(u);
    }
}

LL query(int u,int l,int r){
    if(tr[u].l>= l and tr[u].r <= r)return tr[u].sum;
    pushdown(u);
    int mid = (tr[u].l + tr[u].r)/2;
    LL sum = 0;
    if(l<= mid)sum += query(u*2,l,r);
    if(r>mid)sum += query(u*2+1,l,r);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);
    int op;
    int l,r,d;
    while(m--){
        cin>>op>>l>>r;
        if(op == 1){
            cin>>d;
            modify(1,l,r,d);
        }else{
            cout<<query(1,l,r)<<endl;
        }
    }
}