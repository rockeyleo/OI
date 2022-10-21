#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m;
double ans,sum,tt;
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n=read(),m=read(),ans=1e18;
	for(re int i=0;i<m&&i<30;++i){
		re int dlt=min(n,1<<i);
		sum+=1.0*dlt*(i+1),tt+=dlt,n-=dlt;
		int tmp=min(m-(i+2)+1,n);re double tsm=sum,ttt=tt;
		ttt+=tmp;
		tsm+=1.0*(1.0*(i+2)+(i+2+tmp-1))*tmp/2;
		ans=min(ans,tsm/ttt);
	}printf("%.6lf",ans);
}

