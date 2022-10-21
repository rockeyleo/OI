#include<bits/stdc++.h>
using namespace std;
struct node{
    int hei,wei;
};
stack<node>st;
int main(){
    int n,m,ans=0;
    while(cin>>m){
        cin>>n;
        for(int i=1;i<=m;i++){
            node tmp;
            tmp.wei=1;
            cin>>tmp.hei;
            while(!st.empty() and st.top().hei<tmp.hei){
                int tw = st.top().wei;
                ans = max(st.top().hei*st.top().wei,ans);
                st.pop();
                if(!st.empty())st.top().wei+=tw;
            }
            st.push(tmp);
        }
        cout<<ans<<endl;
    }
}