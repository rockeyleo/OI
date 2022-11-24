#include <cctype>
#include <cstdio>
constexpr int N=5e5+1;
char c;
int i,j,n,a[2][N];
inline void qscan(int &x){
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
}
inline bool check(){
	for(j=2;j<n;++j)if(a[0][j]!=a[1][j])return true;
	return false;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	qscan(n);
	for(i=1;i<=n;++i)qscan(a[0][i]),a[1][i]=a[0][i]^1;
	a[1][1]=a[0][1],a[1][n]=a[0][n];
	for(i=0;check();++i)
		for(j=2;j<n;++j)
			a[i&1^1][j]=(a[i&1][j-1]+a[i&1][j]+a[i&1][j+1]>=2);
	printf("%d\n",i-1);
	for(j=1;j<=n;++j)printf("%d ",a[i&1][j]);
}
