#include <bits/stdc++.h>
using namespace std;
const int M = 100000;
int fa[3*M];

int find(int a){
    if(fa[a]==a)return a;
    return(fa[a]=find(fa[a]));
}

void uni(int a,int b){
    fa[find(a)] = find(b);
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=3*n;i++){
        fa[i]=i;
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        int opt,x,y;
        cin>>opt>>x>>y;
        switch(opt){
            case 1:{
                if(find(y)==find(x+n) or find(y)==find(x+2*n)){       //并查集维护的关系是双向的
                //一共就两种逻辑假话，猎物的猎物是天敌，天敌的天敌是猎物，再加上题目要求的其他情况
                    ans++;
                }else{
                    uni(x,y);
                    uni(x+n,y+n);
                    uni(x+2*n,y+2*n);
                }
            }
            case 2:{

            }
        }
    }
}