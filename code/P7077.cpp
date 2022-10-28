#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
const int p = 998244353;

struct f{
    int mode;
    int pos,val,tms,c;
    vector<int>g;
}fun[M];
int a[M],f[M];

int main(){
    int n,m,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>fun[i].mode; 
        switch(fun[i].mode){
            case 1:{
                int p,v;
                cin>>p>>v;
                fun[i].pos=p; fun[i].val=v;
            }
            case 2:{
                int v;
                cin>>v;
                fun[i].tms=v;
            }
            case 3:{
                int c; 
                cin>>c;
                for(int k=1;k<=c;k++){
                    int tmp;
                    fun[i].g.push_back(tmp);
                }
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>f[i];
    }
}