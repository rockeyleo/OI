#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f(int x){
    if((int)(sqrt(x))*(int)(sqrt(x))==x)
      return true;
    else return false;
} 
signed main()
{
    int k;
    cin>>k;
    while(k--){
        int n,e,d;
        cin>>n>>e>>d;
        int t=n-e*d+2,b=n;
        int tmp=sqrt(t*t-4*n);
        if(!f(t*t-4*b)){
            cout<<"NO"<<endl;
            continue;
        }   
        if(abs(t-tmp)%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        else {
            int q=abs(t-tmp); 
            cout<<min((tmp+t)/2,q/2)<<" "<<max((tmp+t)/2,q/2)<<endl;
        }
    } 
    return 0;
}
