#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int M = 10000000;
bool flag[M];

bool check(int i){
    string tmp = to_string(i);
    for(int j=0;j<tmp.length();j++){
        if(tmp[j]=='7'){
            flag[i]=1;
            // cout<<i<<endl;
            return true;
        }
    }
    return 0;
}

void init(){
    for(int i=1;i<=M;i++){
        if(flag[i])continue;
        if(!check(i))continue;
        if(flag[i]==1){
            for(int m=2;i*m<=M;m++){
                flag[m*i]=1;
            }
        }
    }
}

signed main(){
    int n;
    cin>>n;
    // cout<<1<<endl;
    init();
    for(int i=1;i<=n;i++){
        int q;
        cin>>q;
        if(flag[q]==1){
            cout<<-1<<endl;
        }else{
            int j = q+1;
            while(j<=M and flag[j]!=0)j++;
            cout<<j<<endl;
        }
    }
    return 0;
}