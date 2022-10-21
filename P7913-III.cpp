#include <bits/stdc++.h>
using namespace std;
int m1,m2,n;
int cnt1 = 0;int cnt2 = 0;
const int M = 500001;

struct tp{
    int in; int out;
}hm[M],ab[M];

struct pln{
    int sum,time;
}pl1[M],pl2[M];

void read(tp *t,pln *pl,int m,int &cnt){
    for(int i=1;i<=m;i++){
        cin>>t[i].in>>t[i].out;
    }
    sort(t+1,t+1+m,[](tp a,tp b){return a.in<b.in;});
    for(int i=1;i<=m;i++){
        int flag = 0;
        for(int j=1;j<=cnt;j++){
            if(pl[j].time<t[i].in){
                pl[j].sum++;
                pl[j].time = t[i].out;
                flag = i;
                break;
            }
        }
        if(flag==0){
            pl[++cnt].time = t[i].out;
            pl[cnt].sum++;
        }
    }
}

int ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m1>>m2;
    read(hm,pl1,m1,cnt1);
    read(ab,pl2,m2,cnt2);

    int t=1;int t1=1;int t2=1;
    for(;t<=n and t1<=cnt1 and t2<=cnt2;t++){
        if(pl1[t1].sum>pl2[t2].sum){
            ans+=pl1[t1++].sum;
            // cout<<ans<<endl;
        }else{
            ans+=pl2[t2++].sum;
            // cout<<ans<<endl;
        }
    }
    for(;t<=n and t1<=cnt1;t1++,t++)ans+=pl1[t1].sum;
    for(;t<=n and t2<=cnt2;t2++,t++)ans+=pl2[t2].sum;
    cout<<ans;
}