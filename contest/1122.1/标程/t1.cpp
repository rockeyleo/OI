#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=998244353;
typedef long long ll;
int x[N],y[N],n,s1,s2,s3,s4;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		(s1+=x[i])%=M;(s2+=y[i])%=M;
		s3=(s3+(ll)x[i]*x[i])%M;
		s4=(s4+(ll)y[i]*y[i])%M;
	}
	for (int i=1;i<=n;i++)printf("%lld\n",(((ll)x[i]*x[i]%M*n+(ll)y[i]*y[i]%M*n+s3+s4-(ll)s1*x[i]*2-(ll)s2*y[i]*2)%M+M)%M);
}
