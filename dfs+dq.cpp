#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int nxt[1001],ans,fst;

int dfs(int n,int cnt){
    if(nxt[n]==0)return cnt;
    ans = max(ans,dfs(nxt[n],++cnt));
    return 0;
}

int main(){
    int n;
    int t1;
    cin>>n;
    cin>>t1;
    s.push(t1);
    for(int i=1;i<=n-1;i++){
        int tmp,flag=1;;
        cin>>tmp;
        while(!s.empty() and s.top()>=tmp){
            nxt[s.top()] = tmp;
            s.pop();
            flag=0;
        }
        if(flag)fst++;
        s.push(tmp);
    }
    for(int i=1;i<=n;i++){
        dfs(i,1);
    }
    cout<<fst;
}