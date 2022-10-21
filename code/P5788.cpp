#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>>sk;
const int M = 3e6+10;
int ans[M],node[M];
pair<int,int>lst[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(register int i=1;i<=n;i++){
        cin>>lst[i].second;
        lst[i].first=i;
    }
    sk.push(lst[1]);
    for(register int i=2;i<=n;i++){
        while(sk.top().second<lst[i].second){
            ans[sk.top().first]=i;
            // cout<<mp[sk.top()]<<endl;
            sk.pop();
            if(sk.empty())break;
        }
        sk.push(lst[i]);

    }
    for(register int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}