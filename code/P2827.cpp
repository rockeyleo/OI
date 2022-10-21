#include <bits/stdc++.h>
using namespace std;
int len[100001];
queue<int>qu;
queue<int>q2;
queue<int>q3;
vector<int> ans;
int qyl[100001];
int mm = -1145141919;
int main(){
    int n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+1+n,[](int a,int b){return a>b;});
    for(int i=1;i<=n;i++){
        qu.push(len[i]);
    }
    int t1,t2,t3;
    // cout<<q2.size();
    for(int i=1;i<=m;i++){
        t1=mm;t2=mm;t3=mm;
        if(!qu.empty())t1 = qu.front();qu.pop();
        if(!q2.empty())t2 = q2.front();q2.pop();
        if(!q3.empty())t3 = q3.front();q3.pop();
        int res = max(t1,t2);
        res = max(t2,t3);
        qyl[i] = res;
        int base = (res+m*q)/v;
        int base2 = (res+m*q)-base;
        q2.push(base-m*q);
        q3.push(base2-m*q);
    }
    // t1 = mm; t2=mm; t3=mm;
    // for(int i=1;i<=qu.size()+q2.size()+q3.size();i++){
    //     if(!qu.empty())t1 = qu.front();
    //     if(!q2.empty())t2 = q2.front();
    //     if(!q2.empty())t3 = q3.front();
    //     if(t1 >= t2 and t1 >= t3){
    //         ans.push_back(t1);
    //         qu.pop();
    //     }else if(t2 >= t1 and t2 >= t3){
    //         ans.push_back(t2);
    //         q2.pop();
    //     }else if(t3 >= t2 and t3 >= t1){
    //         ans.push_back(t3);
    //         q3.pop();
    //     }
    // }
    while(!qu.empty())ans.push_back(qu.front());qu.pop();
    while(!q2.empty())ans.push_back(q2.front());q2.pop();
    while(!q3.empty())ans.push_back(q3.front());q3.pop();
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b;});
    if(t>m){
        scanf("\n");
    }else{
        for(int i=t;i<=m;i+=t){
           scanf("%d ",qyl[i]);
        }
        scanf("\n");
    }
    for(auto a = ans.begin();a!=ans.end();a++){
        scanf("%d ",*a);
    }
}