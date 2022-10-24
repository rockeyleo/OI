#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
int s[M],g[M];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s;
        cin>>s;
        memset(g,0,sizeof(g));
        int st,ed;
        for(int j=1;j<=s;j++){
            int tmp;
            if(j==i)st = j;
            if(j==s)ed = j;
            cin>>tmp;
            g[tmp] = 1;
        }
        for(int k=st;k<=ed;k++){
            if(!g[k]){
                for(int i=1)
            }
        }
    }
}