#include<bits/stdc++.h>
using namespace std;

int cmp(const int &a,const int &b){
	return a>b;
}

int n;
long long C,X;
vector <int> low;
vector <int> high;
long long solve(){
    cin >> n >> C >> X;
    low.clear(); high.clear();
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        low.push_back(l);
        high.push_back(r);
    }
    sort(low.begin(),low.end(),cmp);
    sort(high.begin(),high.end());
    int ans1=0,ans2=n;
    long long t=0;
    for (int i=0; i<n && t < X; i++){
        t+=low[i];
        if (t>=X) {
            ans1=i+1;
            break;
        }
    }
    if(t<X) ans1=n;
    t=0;
    for (int i=0; i<n; i++){
        t+=high[i];
        if (C-t>=X){
            ans2=n-i-1;
        }
    }
    return n - min(ans1,ans2);
}

int T;
int main(){
    scanf("%d", &T);
    while(T--){
        printf("%lld\n", solve());
    }
    return 0;
}




