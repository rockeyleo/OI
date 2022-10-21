#include <bits/stdc++.h>
using namespace std;
int len[7000010];
queue<int> qu[4];
vector<int>ans;
int dt;
int n,m,q,u,v,t;
int main(){
    cin>>n>>m>>q>>u>>v>>t;
    double p = (double)u/v;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+n+1,[](int a,int b){return a>b;}); //请最起码不要把sort函数的前两项写错，，，
    for(int i=1;i<=n;i++)qu[1].push(len[i]);
    int res;
    for(int i=1;i<=m;i++){
        int flag;
        for(int i=1;i<=3;i++){
            if(!qu[i].empty()){res = qu[i].front();break;}
        }
        for(int i=1;i<=3;i++){
            if(!qu[i].empty() and qu[i].front()>=res){
                res = qu[i].front();
                flag = i;
            }
        }
        qu[flag].pop();
        res+=dt;
        long long base = floor((double)res*p);
        long long base2 = res-base;
        dt+=q;
        qu[2].push(base-dt);
        qu[3].push(base2-dt);
        if(i%t==0)printf("%lld ",res);
    }
    printf("\n");
    while(!qu[1].empty()){ans.push_back(qu[1].front());qu[1].pop();}
    while(!qu[2].empty()){ans.push_back(qu[2].front());qu[2].pop();}
    while(!qu[3].empty()){ans.push_back(qu[3].front());qu[3].pop();}
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b;});
    for(int i=0;i<=ans.size()-1;i++){
        if((i+1)%t==0)printf("%d ",ans[i]+dt);
    }
    return 0;
}
