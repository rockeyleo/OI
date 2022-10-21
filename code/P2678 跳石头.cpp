#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int stone[50001];
int len[50001];

void len(int len[]){
    len[1]=stone[2];
    for(int i=2;i<=n;i++){
        len[i]=stone[i+1]-stone[i-1];
    }
}

int main(){
    int l,n,m;
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>stone[i];
    }
    com(len);
    sort(len+1,len+1+len.length(),cmp);
}