#include <bits/stdc++.h>
using namespace std;
int len[7000010];
long long cut[7000010];
queue<int> q1;
queue<int> q2;
queue<int> q3;
vector<int>ans;
int n,m,q,u,v,t;
const int mm = -1145141919;
int main(){
    cin>>n>>m>>q>>u>>v>>t;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+n+1,[](int a,int b){return a>b;});
    for(int i=1;i<=n;i++)q1.push(len[i]);
    for(int i=1;i<=m;i++){
        int t1=mm,t2=mm,t3=mm;
        if(!q1.empty())t1=q1.front();
        if(!q2.empty())t2=q2.front();
        if(!q3.empty())t3=q3.front();
        int res;
        if(t1>=t2 and t1>=t3 and t1!=mm){q1.pop();res=t1;cout<<"1 "<<res<<endl;}
        else if(t2>=t1 and t2>=t3 and t2!=mm){q2.pop();res=t2;cout<<"2 "<<res<<endl;}
        else if(t3>=t1 and t3>=t2 and t3!=mm){q3.pop();res=t3;cout<<"3 "<<res<<endl;}
        cut[i] = res+(i-1)*q;
        long long base = (long long)(res+(i-1)*q)/v;
        long long base2 = (long long)(res+(i-1)*q)-base;
        q2.push(base-i*q);
        q3.push(base2-i*q);
    }
    while(!q1.empty()){ans.push_back(q1.front());q1.pop();}
    while(!q2.empty()){ans.push_back(q2.front());q2.pop();}
    while(!q3.empty()){ans.push_back(q3.front());q3.pop();}
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b;});
    if(t>m){
        printf("\n");
    }else{
        for(int i=t;i<=m;i+=t){
           printf("%lld ",cut[i]);
        }
        printf("\n");
    }
    if(t>m+n){
        printf("%d\n",ans[t]+m*q);
    }else{
        for(int i=t-1;i<=n+m-1;i+=t){
            printf("%d ",ans[i]+m*q);
        }
    }
    return 0;
}