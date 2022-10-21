#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[1000002],fa1[1000002],fa2[1000002],tim,W,q,sum;
inline int root1(re int x){return x==fa1[x]?x:fa1[x]=root1(fa1[x]);}
inline int root2(re int x){return x==fa2[x]?x:fa2[x]=root2(fa2[x]);}
inline void Merge(re int x){fa1[root1(x)]=root1(x-1),fa2[root2(x-1)]=root2(x);}
struct node{
	int l,r;
	bool operator <(const node A)const{return r-l>A.r-A.l;}
};
priority_queue<node>Q;
struct Node{int x,y,z;bool operator <(const Node A)const{return x==A.x?y<A.y:x<A.x;};};
vector<Node>T;
inline void ck(re int x){
	re int l=root1(x),r=root2(x);
	if(a[l]>a[l-1]&&a[r]>a[r+1])Q.push((node){l,r});
}
inline int Abs(re int x){return x>0?x:-x;}
signed main(){
	n=read(),q=read();int ss=0;
	for(re int i=1;i<=n;++i)a[i]=read(),ss+=a[i],fa1[i]=fa2[i]=i;fa1[n+1]=fa2[n+1]=n+1;
	for(re int i=0;i<=n;++i)sum+=Abs(a[i+1]-a[i]);
	a[0]=a[n+1]=-1e18;
	for(re int i=2;i<=n;++i)if(a[i]==a[i-1])Merge(i);
	for(re int i=1;i<=n;++i)if(root1(i)==i)ck(i);
	while(!Q.empty()){
		re node tmp=Q.top();Q.pop();
		if(tmp.l==1&&tmp.r==n){T.push_back((Node){tim,W,n});break;}
		else{
			T.push_back((Node){tim,W,tmp.r-tmp.l+1});
			re int dlt=max(a[tmp.l-1],a[tmp.r+1]);
			tim+=(a[tmp.l]-dlt)*(tmp.r-tmp.l+1),W+=a[tmp.l]-dlt;
			a[tmp.l]=a[tmp.r]=dlt;
			if(a[tmp.l]==a[tmp.l-1])Merge(tmp.l);
			if(a[tmp.r]==a[tmp.r+1])Merge(tmp.r+1);
			ck(tmp.l);
		}
	}
	while(q--){
		re int x=read(),pos=upper_bound(T.begin(),T.end(),(Node){x,1000000000000000000ll,0})-T.begin()-1;
		printf("%lld\n",max(0ll,sum-2*(T[pos].y+(x-T[pos].x)/T[pos].z)));
	}
}

