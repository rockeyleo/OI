#include <bits/stdc++.h>
using namespace std;
int main(){
    int num[4];
    string a;

    for(int i=1;i<=3;i++){
        cin>>num[i];
    }

    for(int i=1;i<=3;i++){
        char tmp;
        cin>>tmp;
        a+=tmp;
    }
    sort(num+1,num+4);
    for(auto i:a){
        if(i=='A'){
            cout<<num[1]<<" ";
        }else if(i=='B'){
            cout<<num[2]<<" ";
        }else if(i=='C'){
            cout<<num[3]<<" ";
        }
    }
}