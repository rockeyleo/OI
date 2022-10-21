#include <bits/stdc++.h>
using namespace std;
int lmt[30001];
int cf[30001];
int s[100001];
int f[30001][25]; 
int n,m;
int l2g(int a){
    if(a==1)return 0;
    return((l2g(a/2)+1));
}

int cx(int l){
    int r = min(l+8-1,n);
    int len=l2g(r-l+1);
    return(min(f[l][len],f[r-(1<<len)+1][len]));
}

int main(){
    cin>>n>>m;
    int ans;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        lmt[i] = tmp;
        // cf[i] = lmt[i]-lmt[i-1];
        // cout<<cf[i]<<" ";
    }
    
    // cout<<endl;
    for(int i=1;i<=m;i++){
        int tmp;
        cin>>tmp;
        s[tmp]++;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<cf[i]<<" ";
    // }
    for(int i=1;i<=n;i++){
        cf[i]+=s[i];cf[min(i+8-1,n+1)]-=s[i];
        cout<<cf[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        cf[i] = lmt[i] + cf[i];
        // cout<<cf[i]<<" ";
        cf[i] = cf[i] - lmt[i];
        // cout<<cf[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        f[i][0]=cf[i];
    }
    for(int j=1;j<=25;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i]){
            // cout<<cx(i)<<" "<<s[i]<<endl;
            ans += min(cx(i),s[i]);
        }
    }
    cout<<ans-m;
}