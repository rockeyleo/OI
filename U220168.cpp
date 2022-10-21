#include <bits/stdc++.h>
using namespace std;
int cf[500100];
long long pre[500100];
int num[500100];
int dp[500100];
int maxn = 10000000;
int cnt;
int main(){
    int n,k,p;
    cin>>n>>k>>p;
    int mx = 0;
    for(int i=1;i<=n;i++){
        int l,r,v;
        cin>>l>>r>>v;
        mx = max(mx,r);
        cf[l]+=v;
        cf[r+1]-=v;
    }
    for(int i=1;i<=11;i++){
        num[i]=num[i-1]+cf[i];
    }
    for(int i=1;i<=mx;i++){
        if(num[i]>k){cnt++;num[i]=maxn;}
        pre[i]=num[i]+pre[i-1];
    }
    long long mm = 0;int al,ar;
    for(int i=1;i<=mx-p+1;i++){
        if(mm<(pre[i+p-1]-pre[i-1])){
            mm=(pre[i+p-1]-pre[i-1]);
            al = i, ar = i+p-1;
        }
    }
    // cout<<mm<<endl;
    // cout<<al<<" "<<ar<<endl;
    if(mm<maxn*cnt){
        cout<<"orz"<<endl;
    }else{
        cout<<al<<" "<<ar<<endl;
    }
}