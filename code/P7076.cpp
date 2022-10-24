#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int M = 5000001;
int a[M],more[65];
vector<int>rule[65];int flag[65];
signed main(){
    // freopen("zoo3.in","r",stdin);
    // freopen("zoo3.out","w",stdout);
    int n,m,c,k;
    cin>>n>>m>>c>>k;
    for(int i=0;i<=65;i++){
        more[i]=1;
    }
    // long long ans = (1<<k);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        long long p,q;
        cin>>p>>q;
        flag[p]=1;
        more[p]=-1;
        // rule[p].push_back(q);
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            if((1<<j)<=a[i]){
                a[i]-=(1<<j);
                more[j]=1;
            }
        }
    }
    long long ans = 1;
    for(int i=0;i<=k-1;i++){
        // cout<<more[i]<<endl;
        // if(more[i]==-1)cout<<i<<endl;
        if(more[i]==1){
            ans*=2;
        }
    }
    // cout<<tmp;
    cout<<ans-n<<endl;
}