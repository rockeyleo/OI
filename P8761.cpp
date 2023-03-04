#include <bits/stdc++.h>
using namespace std;
int main(){
    string tmp;
    cin>>tmp;
    for(int i=0;i<=tmp.size()-1;i++){
        if(tmp[i]>='a' and tmp[i]<='z'){
            tmp[i]-=32;
        }
    }
    cout<<tmp<<endl;
}