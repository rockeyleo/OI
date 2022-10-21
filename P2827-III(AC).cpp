#include <bits/stdc++.h>
using namespace std;
int len[7000010];
long long cut[7000010];
queue<int> qu[4];
vector<int>ans;
int n,m,q,u,v,t;
const int mm = -2147483647;
int main(){
    cin>>n>>m>>q>>u>>v>>t;
    double p = (double)u/v;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+n+1,[](int a,int b){return a>b;});
    for(int i=1;i<=n;i++)qu[1].push(len[i]);
    for(int i=1;i<=m;i++){
        int res = mm;
        int flag;
        for(int i=1;i<=3;i++){
            if(!qu[i].empty() and qu[i].front()>=res){
                res = qu[i].front();
                flag = i;
            }
        }
        qu[flag].pop();
        cut[i] = res+(i-1)*q;
        long long base = floor((double)(res+(i-1)*q)*p);
        long long base2 = (res+(i-1)*q)-base;
        qu[2].push(base-i*q);
        qu[3].push(base2-i*q);
    }
    while(!qu[1].empty()){ans.push_back(qu[1].front());qu[1].pop();}
    while(!qu[2].empty()){ans.push_back(qu[2].front());qu[2].pop();}
    while(!qu[3].empty()){ans.push_back(qu[3].front());qu[3].pop();}
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