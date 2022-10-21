#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int M = 10000001;
bool flag[M];
int nxt[M];

bool check(int x){
    string tmp = to_string(x);
    for(int i=0;i<tmp.length();i++){
        if(tmp[i]=='7'){
            return 1;
        }
    }
    return 0;
}

void init(){
    int lst = 1;
    for(int i=2;i<=M;i++){
        if(flag[i])continue;
        if(check(i)){
            flag[i]==1;
            for(int m=0;m<=M;m+=i){
                flag[m]=1;
            }
        }else{
            nxt[lst]=i;
            lst = i;
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
            cout<<nxt[q]<<endl;
        }
    }
    return 0;
}