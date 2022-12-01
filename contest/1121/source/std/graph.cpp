#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N1,N2,A,D;
ll val(ll v) {
    if(v<D) return -1;
    if(A-v<D) return -1;
    return N1*v + (A-v)*(N2-v);
}

ll calc(){
    if(N1<N2) swap(N1,N2);
    if(N2==A) return N1*N2;
    if(A<2*D) return -1;
    ll ret=-1;
    ret=max(ret,val(0));
    ret=max(ret,val(D));
    ret=max(ret,val(A-D));
    ret=max(ret,val(N1));
    ret=max(ret,val(N2));
    ret=max(ret,val((A+N2-N1)/2));
    ret=max(ret,val((A+N2-N1)/2+1));
    return ret;
}

int main(){
    cin >> N1 >> N2 >> A >> D;
    cout << calc() << endl;
    return 0;
}
