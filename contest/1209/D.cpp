#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    int i = 1;
    while(true){
        if(sum+i<=n){
            sum+=i;
            cout<<i++<<endl;
        }else{
            break;
        }
    }
}