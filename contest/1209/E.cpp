#include <bits/stdc++.h>
using namespace std;
deque<int>dq;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        dq.push_back(tmp);
    }
    while(true){
        int t = dq.back();
        dq.pop_back();
        dq.push_front(t);
        for(auto i = dq.begin();i!=dq.end();i++){
            cout<<*i<<" ";
        }
        cout<<endl;
        if(dq.back()==n)break;
    }
}