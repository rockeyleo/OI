#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1919810;
ll a[N],bg[N],ed[N];
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout); 
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ll cnt=1;
	bg[1]=1;
	for(ll i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			continue;
		}else {
			ed[cnt]=i-1;
			bg[++cnt]=i;
		}
	}
	ed[cnt]=n;
	//for(ll i=1;i<=cnt;i++) cout<<bg[i]<<' '<<ed[i]<<endl;
	//now consider how we link two len
	//can link only if
	//a[bg[1]+1]-a[ed[0]]>1
	//or 
	//a[bg[1]]-a[ed[0]-1]>1
	//else no matter how we can't link it
	//and most importantly
	//a single one can link two side if and only if on the middle and can do it
	//which means it is included
	ll link_max = -1;
	for(ll i=2;i<=cnt;i++){
		if(ed[i-1]-bg[i-1]==0){
			link_max = max(link_max,ed[i]-bg[i]+1+1);//a single layer
		}
		if((a[bg[i]+1]-a[ed[i-1]]>1)||a[bg[i]]-a[ed[i-1]-1]>1){
			link_max = max(link_max,ed[i]-bg[i]+1+ed[i-1]-bg[i-1]+1); 
		}
	}
	cout<<link_max;
} 
