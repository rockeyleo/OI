#include <bits/stdc++.h>
using namespace std;
int M = 1e6+3;
int v[M];
int tree[M*4];

int dfs(int a,int dep){
    
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&v[n]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        tree[i*2]=v[a],tree[i*2+1]=v[b];
    }
    int ans = dfs(1,1);
}