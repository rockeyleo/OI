#include <bits/stdc++.h>
using namespace std;

struct str{
    int in,out;
    friend bool operator <(str a,str b){
        return a.in>b.in;
    }
};
// stack<str>q;
priority_queue<str>pq1;
priority_queue<str>pq2;
int res[100001];
int pre1[100001],pre2[100001];
int cnt=0;
int cc(){
    while(!(pq1.empty() and pq2.empty())){
        int last=0,re=0;
        while(!pq1.empty()){
            str tmp = pq1.top();
            pq1.pop();
            if(last == 0){
                last = tmp.out;
                re++;
            }else if(last<=tmp.in){
                re++;
                last = tmp.out;
            }else{
                pq2.push(tmp);
            }
        }
        res[++cnt] = re;
        // cout<<cnt<<endl;
        re = 0; last = 0;
        if(pq1.empty() and pq2.empty())break;
        while(!pq2.empty()){
            str tmp = pq2.top();
            pq2.pop();
            if(last == 0){
                last = tmp.out;
                re++;
            }else if(last<=tmp.in){
                re++;
                last = tmp.out;
            }else{
                pq1.push(tmp);
            }
        }
        res[++cnt] = re;
        // cout<<cnt<<endl;
        re = 0; last = 0;
    }
    return cnt;
}

int main(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++){
        int in,out;
        scanf("%d",&in);scanf("%d",&out);
        str tmp;
        tmp.in = in;
        tmp.out = out;
        pq1.push(tmp);
    }
    int x=1,j=cc()+1;
    for(int i=1;i<=m2;i++){
        int in,out;
        scanf("%d",&in);scanf("%d",&out);
        str tmp;
        tmp.in = in;
        tmp.out = out;
        pq1.push(tmp);
    }
    cc();
    // sort(res+1,res+1+m1+m2,[](int a,int b){return a>b;});
    int ans = 0;
    int cot=0;
    // cout<<i<<" "<<j<<endl;
    cout<<res[j]<<endl;
    // for(int i=1;i<=cnt;i++){
    //     cout<<res[i]<<endl;
    // }
    for(int i=1;i<=n;i++){
        pre1[i] = pre1[i-1]+res[x++];
        pre2[i] = pre2[i-1]+res[j++];
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,pre1[i]+pre2[n-i]);
        cout<<ans<<endl;
    }
    for(int i=1;i<=cnt;i++){
        cout<<res[i]<<endl;
    }
    cout<<ans<<endl;
}