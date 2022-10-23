#include <bits/stdc++.h>
using namespace std;
int a[500001];
vector<pair<int,int>>v1;
vector<pair<int,double>>v2;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x0,y,v;
    cin>>x0>>y>>v;
        double xt = (double)x0+v*sqrt((2*y)/9.8);
        v1.push_back({i,x0});
        v2.push_back({i,xt});
    }
    sort(v1.begin(),v1.end(),[](pair<int,double>a,pair<int,double>b){return a.second>b.second;})
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}