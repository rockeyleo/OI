#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=500005;
int a[Maxn],b[Maxn],n;
LL basis[41];
void Ins(LL x){
	for (int i=39;i>=0;i--){
		if (x>>i&1){
			if (basis[i]==-1){
				basis[i]=x;
				return;
			}
			x^=basis[i];
		}
	}
}
LL ans=0;
void dfs(LL lvl,LL X){
	if (lvl==-1){
		LL A=X>>20,B=X&((1ll<<20)-1);
		ans=max(ans,A*B);
		return;
	}
	if (lvl>=20){
		dfs(lvl-1,X);
		if (basis[lvl]!=-1){
			dfs(lvl-1,X^basis[lvl]);
		}
		return;
	}
	
	if (basis[lvl]==-1){
		dfs(lvl-1,X);
	}
	else{
		if (X>>lvl&1){
			dfs(lvl-1,X);
		}
		else{
			dfs(lvl-1,X^basis[lvl]);
		}
	}
}
void mian(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	for (int i=1;i<=n;i++){
		b[i]=read();
	}
	for (int i=0;i<40;i++) basis[i]=-1;
	for (int i=1;i<=n;i++){
		LL tmp=(((LL)a[i])<<20)+(LL)b[i];
		
		Ins(tmp);
	}
	ans=0;
	dfs(39,0);
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	//int T=1;
	while (T--){
		mian();
	}
} 
