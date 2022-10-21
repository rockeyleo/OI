#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int fa[40002];
struct node{
    int f,t,v;
}edge[100001];


int find(int a){
    if(fa[a] == a)return a;
    return(fa[a] = find(fa[a]));
}

int main(){
    // freopen("P1525_2.in","r",stdin);
    cin>>n>>m;
    for(int i= 1;i<=n*2;i++){
        fa[i] = i;
    }
    for(int i=1;i<=m;i++){
        cin>>edge[i].f>>edge[i].t>>edge[i].v;
    }
    sort(edge+1,edge+m+1,[](node a,node b){return (a.v>b.v);});
    for(int i=1;i<=m;i++){
        if(find(edge[i].f) == find(edge[i].t)){
            cout<<edge[i].v<<endl;
            return 0;
        }
        fa[find(edge[i].t+n)] = find(edge[i].f);
        fa[find(edge[i].f+n)] = find(edge[i].t);
    }
    cout<<0<<endl;
}