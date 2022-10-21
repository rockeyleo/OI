#include <bits/stdc++.h>
using namespace std;
const int M = 1001;
int num[M];
pair<int,int> pp[M];
queue<pair<int,int>>q;
// struct node{
//     int val,dis;
//     friend bool operator<(node a,node b){
//         return(a.dis>b.dis);
//     }
// };
// priority_queue<node>q;
int main(){
    ios::sync_with_stdio(false);
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        pp[i]={i,num[i]};
        // node tmp;tmp.val=num[i];tmp.dis=i;
        // q.push_back(dis);
    }
    sort(pp+1,pp+1+n,[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
    for(int i=1;i<=n;i++){
        q.push(pp[i]);
    }
    int ans=0;
    int l=1,r=n;
    while(q.size()>1){
        auto now = q.front();
        q.pop();
        int a=now.first,b=a-1,c=a+1;
        while(num[b]==-1){
            // cout<<b<<endl;
            if(b<l)b=n;
            b--;
        }
        while(num[c]==-1){
            if(c>r)c=1;
            c++;
        }
        // if(a==l)l++;
        // if(a==r)r--;
        // cout<<a<<endl;
        cout<<b<<" "<<a<<" "<<c<<endl;
        ans+=(num[a]*num[b]*num[c]);
        cout<<ans<<endl;
        num[a]=-1;
    }
    cout<<ans;
}