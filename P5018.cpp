#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+10;
int val[i];
int tree[M*4];

int dfs(int x,int y,ans){
    if(val[x]!=val[y] or val[x]=-1 or val[y]==-1)return ans;
    
}

int main(){
    ios::sync_with_stdio(false);
    memset(-1,tree,sizeof(tree));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=n;i++){
        cin>>tree[i<<2]>>tree[i*2+1];
    }
    for(int i=1;i<=n;i++){
        ans = max(i*2,i*2+1,1);
    }
    cout<<ans;
}