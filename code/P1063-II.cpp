#include <bits/stdc++.h>
using namespace std;
const int M = 510;
int f[M][M],a[M];
pair<int,int>p[M];

int d(int l,int r){
    for(int i=l;i<r;i++){
        
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        p[i].first = a[i];
        p[i].second = i==n?a[1]:a[i+1];
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l+i-1<=n;l++){
            int r = l+i-1;
            for(int k=i;k<r;k++){
                f[l][r] = max(f[l][r],f[l][k]+f[k+1][r]+d(l,r));
            }
        }
    }
}