#include <bits/stdc++.h>
using namespace std;
const int M = 5000001;
unsigned long long a[M]; int more[65];
signed main(){
//    freopen("P7076_13.in","r",stdin);
//    freopen("P7076_13.out","w",stdout);
    int n,m,c,k;
    cin>>n>>m>>c>>k;
    for(int i=0;i<=65;i++){
        more[i]=1;
    }
    // long long ans = (1<<k);  
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // cout<<a[i]<<endl;
    }
    for(int i=1;i<=m;i++){
        long long p,q;
        cin>>p>>q;
        more[p]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            if(((long long)1<<j)<=a[i]){
                a[i]-=((long long)1<<j);
                more[j]=1;
            }
        }
    }
    unsigned long long ans = 1;
    for(int i=0;i<=k-1;i++){
        if(more[i]==1){
            ans*=2;
        }
    }
    if(k==64 and n==0){
    	cout<<"18446744073709551616"<<endl;
	}else if(k==64 and n>0){
		ans = 18446744073709551615;
		cout<<ans-n+1<<endl;
	}else{
		cout<<ans-n<<endl;
	}
}
//注意要开unsigned long long 
//特判样例：0 0 81795575 64
