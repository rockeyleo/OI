#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
struct nd{
    int cnt=0;
    int edge[3];
}node[M];
int val[M];
long long sum;
long long maxn =0;
int main(){
    ios::sync_with_stdio(false);
    freopen("link.in","r",stdin);
    freopen("link.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        node[u].edge[++node[u].cnt]=v;
        node[v].edge[++node[v].cnt]=u;
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=node[i].cnt;j++){
            int to = node[i].edge[j];
            for(int k=1;k<=node[to].cnt;k++){
                int t2= node[to].edge[k];
                if(t2!=i){
                    // cout<<i<<" "<<t2<<endl;
                    maxn = max(maxn,(long long)val[i]*val[t2]);
                    sum += (val[i]*val[t2])%10007;
                }
            }
        }
    }
    cout<<maxn<<" "<<sum%10007;
}