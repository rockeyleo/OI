#include <bits/stdc++.h>
using namespace std;
int m1,m2,n;
int cnt1 = 0;int cnt2 = 0;
const int M = 5000010;

struct tp{
    int in; int out;
}hm[M],ab[M];

struct pln{
    int sum,time;
}pl1[M],pl2[M];

int rd(){
    char ch = getchar();int ret=0;
    while (ch<'0'||ch>'9') {ch=getchar();}
    while(ch>='0' and ch<='9'){ret = ret*10+ch-'0';ch=getchar();}
    return ret;
}

void read(tp *t,pln *pl,int m,int &cnt){
    for(int i=1;i<=m;i++){
        t[i].in = rd();
        t[i].out = rd();
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
    // for(int i=1;i<=cnt1;i++)cout<<pl[i].sum<<" ";
    // cout<<endl;
    for(int i=1;i<=cnt;i++){
        pl[i].sum += pl[i-1].sum;
    }
}

int ans = 0;
int main(){
    cin>>n>>m1>>m2;
    pl1[0].sum = 0;pl2[0].sum = 0;
    read(hm,pl1,m1,cnt1);
    read(ab,pl2,m2,cnt2);
    // cout<<cnt1<<" "<<cnt2<<endl;
    int ans =0;
    for(int i=0;i<=n;i++){      //i要从0开始，到n结束，以判断一方为0的情况
        ans = max(pl1[i].sum+pl2[n-i].sum,ans);
        cout<<ans<<endl;
    }
    cout<<ans;
}