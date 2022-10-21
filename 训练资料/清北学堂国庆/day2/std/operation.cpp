#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
char rbuf[20000002];
int pt=-1;
inline int read(){
	re int t=0,f=0;re char v=rbuf[++pt];
	while(v<'0')f|=(v=='-'),v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return f?-t:t;
}
const int M=998244353;
int n,m,a[400002],num[400002],cnt,L[400002],R[400002],X[400002],W[400002],f[400002],sz[1600002],b[400002],head[1600002];
struct edge{int to,next;}e[14400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
ll S[1600002],sum[400002],inf=(4e18)+1,ans,inf1=(2e18)+1;
struct node{
	int x;ll dis;
	bool operator <(const node A)const{return dis>A.dis;}
}h[400002];
inline void gmn(re ll&x,re ll y){y<x&&(x=y);}
priority_queue<node>Q;
inline void Ins(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		add(p,z),++num[z];
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)Ins(p<<1,l,mid,x,y,z);
	if(y>mid)Ins(p<<1|1,mid+1,r,x,y,z);
}
inline void ck(re int x,re ll y){y=min(y,inf1);if(y<h[x].dis)h[x].dis=y,Q.push(h[x]);}
inline void cg(re int p,re int l,re int r,re int x,re ll y){
	++sz[p],S[p]+=y,S[p]=min(S[p],inf1);
	assert(sz[p]<=r-l+1);
	if(sz[p]==r-l+1){
		for(re int i=head[p];i;i=e[i].next){
			re int z=e[i].to;sum[z]+=S[p];
			if(!(--num[z]))ck(X[z],sum[z]+W[z]);
		}
	}
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
}
int main(){
	fread(rbuf,1,20000000,stdin),n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read(),h[i]=(node){i,inf};
	for(re int i=1;i<=m;++i){
		X[i]=read(),L[i]=read(),R[i]=read(),W[i]=read();
		Ins(1,1,n,L[i],R[i],i);
	}
	for(re int i=1;i<=n;++i){
		re int x=read();b[i]=x;
		if(x>=0)h[i].dis=x;
	}
	for(re int i=1;i<=n;++i)if(h[i].dis!=inf)Q.push(h[i]);
	while(!Q.empty()){
		re node x=Q.top();Q.pop();
		if(x.dis!=h[x.x].dis)continue;
		cg(1,1,n,x.x,x.dis);
	}
	for(re int i=1;i<=n;++i)if(a[i]&&h[i].dis>=inf1)return puts("-1"),0;
	for(re int i=1;i<=n;++i)ans+=h[i].dis*a[i];
	printf("%lld",ans);
}

