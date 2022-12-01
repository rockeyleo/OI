#include <bits/stdc++.h>
using namespace std;
const int M = 500100;
int num[M];
int p1[M],p2[M];
int n;
int check(){
    int cnt1=0,cnt2=0;
    if(p1[1]!=num[1])cnt1++;
    if(p2[1]!=num[1])cnt2++;
    for(int i=2;i<=n;i++){
        if(p1[i]!=num[i] and p1[i-1]==num[i-1]){
            cnt1++;
        }
    }
    for(int i=2;i<=n;i++){
        if(p2[i]!=num[i] and p2[i-1]==num[i-1]){
            cnt2++;
        }
    }
    // cout<<cnt1<<" "<<cnt2<<endl;
    return max(cnt1,cnt2);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(i%2==0){
            p1[i]=1;
        }else{
            p2[i]=1;
        }
    }
    cout<<check();
}