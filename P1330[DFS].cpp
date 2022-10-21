#include <bits/stdc++.h>
using namespace std;
int m,n;

struct node{
    int to,from;
}edge[50010];

bool dfs(int ){

}
int main(){
    int cnt;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int f,t;
        cin>>f>>t;
        edge[++cnt].from  = f;
        edge[cnt].to = t;
        edge[++cnt].from = t;
        edge[cnt].to = f; 
    }
}