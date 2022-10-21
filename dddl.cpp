#include <bits/stdc++.h>
using namespace std;
struct node{
    int pos,val;
};
deque<node>dq;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        node tmp;
        cin>>tmp.val;
        tmp.pos = i;
        if(!dq.empty() and i-m+1>dq.front().pos){
            dq.pop_front();
        }
        while(!dq.empty() and dq.back().val<tmp.val){
            dq.pop_back();
        }
        dq.push_back(tmp);
        cout<<dq.front().val<<endl;
    }
}