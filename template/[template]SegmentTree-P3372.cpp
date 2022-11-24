#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+3;
#define ll long long
ll num[M],lzy[M*4],tree[M*4]; //num表示原数列，tree表示维护的数据
//如果按照堆的形式存储数据，则编号U的左子节点是2*U，右子节点则为2*U-1，可以直接利用这个性质来维护结构
/*二叉树并不一定是完全的，所以虽然数量上只有2n-1个节点，
但是标号可能一直到4n-1，因此空间要开四倍。空间利用率看来还不够优秀*/
void mushup(int u){
    tree[u] = tree[2*u]+tree[2*u+1];    //区间和维护，可以替换成一切满足结合律的操作
}//用于更新维护的数据，参数是父节点
void build(int l,int r,int u){
    lzy[u]=0;
    if(l == r){
        tree[u] = num[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,u*2);
    build(mid+1,r,u*2+1);
    mushup(u);      //使用mushup使叶节点建立好以后立刻向次级节点回溯，直接构建出正确的初始状态
}

void tag(int u,int l,int r,ll v){
    lzy[u]+=v;      //lzy本质上记录的是子树的修改，所以本层的区间和就直接改掉了
    tree[u]+=(r-l+1)*v;     //pushdown之前子树上的值没有被更新，现在被激活了，需要更新数据
}

void pushdown(int u,int l,int r){   //pushdown只下传一层，参数为父节点，且没有边界判断
    int m = (l+r)/2;
    tag(u*2,l,m,lzy[u]);
    tag(u*2+1,m+1,r,lzy[u]);
    lzy[u] = 0;     //数组不清空，爆零两行泪
}

ll query(int u,int L,int R,int l,int r){   //[l,r]表示查询的区间，[L,R]表示线段树节点代表的区间
    if(l<=L and r>=R)return tree[u];
    int mid = (L+R)/2;
    if(l>R or r<L)return 0;
    pushdown(u,L,R);
    return(query(u*2,L,mid,l,r)+query(u*2+1,mid+1,R,l,r));  //U的值和线段树区间严格对应
    /*这一步等价于在上一层提前判断分块的时候有没有越过中点，如没有就只查询中点的一边的写法：
        if(l<=mid)query(u,L,M,l,r);
        if(r>mid)query(u*2+1,M+1,R,l,r);
    */
}

void update(int u,int L,int R,int l,int r,ll v){
    if(l<=L and r>=R){
        // lzy[u]+=v;
        // tree[u]+=(r-l+1)*v;
        // lzy[u]=0;    //数组不清空，爆零两行泪
        tag(u,L,R,v);
        return;
        //不难发现tag最多会在叶子结点的上一层出现，不会越界
    }
    if(l>R or r<L)return; 
    // cout<<u<<endl;
    int mid = (L+R)/2;
    pushdown(u,L,R);
    update(u*2,L,mid,l,r,v);
    update(u*2+1,mid+1,R,l,r,v);
    mushup(u);
    /*这个时候u的子树是都新的，但是u的值因为没有完全属于选中的[l,r]区间而没有被更新，但又因为部分子树作为[l,r]子集
    而更新，导致u上的值受到影响，所以需要在自下而上更新一下u的数据*/
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        // cin>>num[i];
        scanf("%lld",&num[i]);
    }xiu gai |
    build(1,n,1);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                int x,y; ll k;
                // cin>>x>>y>>k;
                scanf("%d%d%lld",&x,&y,&k);
                update(1,1,n,x,y,k);
                break;
            }
            case 2:{
                int x,y;
                // cin>>x>>y;
                scanf("%d%d",&x,&y);
//                 cout<<query(1,1,n,x,y)<<endl;
                printf("%lld\n",query(1,1,n,x,y));
                break;
            }
        }
    }
}