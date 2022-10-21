#include <iostream>
#include  <bits/stdc++.h>
using namespace std;
const int maxn=2e7+5;
list<pair<int,int>>player;
int main(){
    int n;
    cin>>n;
    int temp;
    // auto ittemp = player.begin();
    auto it=player.begin(),it2=player.begin()++;
    auto ptemp1 = *it, ptemp2 = *it2;
    for(int i=1;i<=pow(2,n);i++){
        cin>>temp;
        player.push_back(make_pair(temp,i));
    }

    for(int i=1;i<=pow(2,n);i+=2){
        ptemp1 = *it, ptemp2 = *it2;
        if(ptemp1.first>ptemp2.first){
            it++;it++;it2++;it2++;
            player.remove(ptemp2);
        }else{
            it++;it++;it2++;it2++;
            player.remove(ptemp1);
        }
    }

    it = player.begin();it2 = player.begin()++;
    ptemp1 = *it, ptemp2 = *it2;        
    if(ptemp1.first<ptemp2.first){
        cout<<ptemp1.second;
        return 0;
    }else{
        cout<<ptemp2.second;
        return 0;
    }
}
