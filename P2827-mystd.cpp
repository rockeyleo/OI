#include <bits/stdc++.h>
using namespace std;
int len[7000010];
queue<int> qu[4];
vector<int>ans;
int n,m,q,u,v,t,res,flag;
int main(){
    cin>>n>>m>>q>>u>>v>>t;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    double p = (double)u/v;         //如果您省略强制类型转换，将会得到15分的好成绩
    sort(len+1,len+n+1,[](int a,int b){return a>b;});       //如果您的sort右界忘记+1，将会得到40分的好成绩
    for(int i=1;i<=n;i++)qu[1].push(len[i]);
    for(int i=1;i<=m;i++){
        for(int i=1;i<=3;i++){
            if(!qu[i].empty()){res = qu[i].front();break;}      //不建议使用一个固定最小值来初始化res，当然更不能是0
        }
        for(int i=1;i<=3;i++){
            if(!qu[i].empty() and qu[i].front()>=res){
                res = qu[i].front();
                flag = i;
            }
        }
        qu[flag].pop();
        if(i%t==0)printf("%d ",res+(i-1)*q);
        int base = (res+(i-1)*q)*p;
        int base2 = (res+(i-1)*q)-base;
        qu[2].push(base-i*q);qu[3].push(base2-i*q);
    }
    printf("\n");
    while(!qu[1].empty()){ans.push_back(qu[1].front());qu[1].pop();}
    while(!qu[2].empty()){ans.push_back(qu[2].front());qu[2].pop();}
    while(!qu[3].empty()){ans.push_back(qu[3].front());qu[3].pop();}
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b;});
    for(int i=0;i<=ans.size()-1;i++){
        if((i+1)%t==0)printf("%d ",ans[i]+m*q);         //千万注意i是从0开始的，与t取模前要加+1（之所以非得0开始是因为ans是个vector，当然您也可以提前压一个数来解决这个问题）
    }
    return 0;
}