#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tree[100001];
int n,m;

bool check(int mid){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=tree[i]/mid;
    }
    // cout<<sum<<endl;
    return(sum>=m);
}

int find(){
    int l=0,r=1e8+1,mid;
    while(l<r-1){
        mid = (l+r)/2;
        // cout<<mid<<endl;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tree[i];
    }
    cout<<find();
}