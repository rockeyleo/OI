#include <bits/stdc++.h>
using namespace std;
deque<pair<int,int>>dq; //<pos,val>
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int tmp;
        scanf("%d",&tmp);
        // cin>>tmp;    //这个题用iostream还真就不行
        if(dq.empty()){
            // cout<<0<<endl;
            printf("%d\n",0);
        }
        if(!dq.empty() and dq.front().first<(i-m+1))dq.pop_front();
        while(!dq.empty() and dq.back().second>=tmp){    //千万注意危险内存访问！！！！！！！一定要判断非空！！！！！！
            dq.pop_back();
        }
        dq.push_back(make_pair(i,tmp));
        // printf("%d\n",dq.front().second);
        // cout<<dq.front().second<<"\n";
    }
}