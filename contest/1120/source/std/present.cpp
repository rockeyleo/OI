#include<bits/stdc++.h>
using namespace std;

struct node {
    int a,o;
};vector<node> f;
bool cmp(node x,node y) {
    if (x.a==y.a) return x.o<y.o;
    return x.a<y.a;
}
vector<int> va, vb;
int main(){
    long long ans = 0;
    int x = -1;
    int n;
    scanf("%d", &n);
    for (int i=0, a, b; i<n ; i++ ) {
        scanf("%d%d",&a,&b);
        va.push_back(a);
        vb.push_back(b);
    }
    for (int i=0 ; i<n ; i++ ) {
        if (x==-1 || x>va[i]+vb[i]) x=va[i]+vb[i];
        f.push_back((node){va[i],vb[i]});
    }
    for (int i=1 ; i<=x ; i++ ) {
        long long big = 0 , sml = 0;
        for (int j=0 ; j<n ; j++ ) {
            if (f[j].a>=i) big += i;
            else big += f[j].a;
            
            if (f[j].o>=i) sml += 0;
            else sml += i-f[j].o;
        }
        ans += big-sml+1;
    }
    cout << ans <<endl;
    return 0;
}