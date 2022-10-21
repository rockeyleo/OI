#include <bits/stdc++.h>
using namespace std;
struct node{
    int pos,val;
};
deque<node>dq_max; deque<node>dq_min;
int num[1000000];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }

    for(int i=1;i<=n;i++){
        node tmp;
        tmp.val=num[i]; tmp.pos=i;
        if(!dq_min.empty() and dq_min.front().pos<i-k+1){
            dq_min.pop_front();
        }
        while(!dq_min.empty() and dq_min.back().val>=tmp.val){
            dq_min.pop_back();
        }
        dq_min.push_back(tmp);
        if(i>=k)cout<<dq_min.front().val<<" ";

    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        node tmp;
        tmp.val=num[i]; tmp.pos=i;
        if(!dq_max.empty() and dq_max.front().pos<i-k+1){
            dq_max.pop_front();
        }
        while(!dq_max.empty() and dq_max.back().val<=tmp.val){
            dq_max.pop_back();
        }
        dq_max.push_back(tmp);
       if(i>=k) cout<<dq_max.front().val<<" ";
    }
}