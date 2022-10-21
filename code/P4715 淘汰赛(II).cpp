#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6+1;
int n;
int tree[MAX][8];     //（横坐标，纵坐标），从下到上，从左到右
int code[MAX][8];

void build(){
    for(int i=2;i<=n;i++){
        for(int j=1,q=1;q<=pow(2,n-i+1);j+=2,q++){
            if(tree[j][i-1]>tree[j+1][i-1]){
                tree[q][i]=tree[j][i-1];
                code[q][i]=code[j][i-1];
            }else{
                tree[q][i]=tree[j+1][i-1];
                code[q][i]=code[j+1][i-1];
            }
        }
    }
}

int main(){
    memset(tree,0,sizeof(tree));
    cin>>n;
    for(int i=1;i<=pow(2,n);i++){
        cin>>tree[i][1];
        code[i][1]=i;
    }
    build();
    if((tree[1][n]<tree[2][n])){
        cout<<code[1][n];
    }else{
        cout<<code[2][n];
    }
}