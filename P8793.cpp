#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string tot;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        if(tmp[0]=='o' and tot[tot.size()-1]=='w'){
            tot+=tmp;
        }else{
            tmp+=tot;
            tot = tmp;
        }
    }
    // string tmp;
    // cin>>tmp;
    // int cnt = 0;
    // for(int i=1;i<=tmp.size()-2;i++){
    //     if(tmp[i]=='w' and tmp[i-1]=='o' and tmp[i+1]=='o'){
    //         cnt++;
    //     }
    // }
}