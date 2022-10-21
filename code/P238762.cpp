#include <bits/stdc++.h>
using namespace std;
map <int,vector<int>> mp;

int read(){
    int f=1;char ch=getchar();int ret=0;
    while(ch<'0' or ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch>='0' and ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int u,v;
        u = read();
        v = read();
        mp[u].push_back(v);
    }
    for(int i=1;i<=q;i++){
        int x,k;
        x = read();
        k = read();
    }
}