#include <bits/stdc++.h>
using namespace std;
const int M = 1000001;
int head[M];
int nxt[M];
int to[M];
int cnt;
int val[M];

void add(int from,int t){
    to[++cnt]=t;
    nxt[cnt]=head[from];
    head[from]=cnt;
}

int main(){
    int n;
    cin>>n;
    long long maxn = 0;
    for(int i=1;i<=n-1;i++){ 
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long sum = 0;int m1=0,m2=0;
        for(int now = head[i];now;now=nxt[now]){
            int t = to[now];
            if(val[t]>=m1){
                m2 = m1;
                m1 = val[t];
            }else{
                m2 = max(m2,val[t]);
            }
            sum += val[t];
        }
        for(int now = head[i];now;now=nxt[now]){
            int t = to[now];
            ans = (ans+val[t]*(sum-val[t]))%10007;
        }
        maxn = max(maxn,(long long)m1*m2);
    }
    cout<<maxn<<" "<<ans%10007<<endl;
}