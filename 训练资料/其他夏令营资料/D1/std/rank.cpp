#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,k,dv;
long long a[maxn][6],ans[maxn];
long long K[maxn],B[maxn];
struct Node {
	long long t;int v;Node(){}
	Node(int _t,int _v):t(_t),v(_v){}
};
inline int cmp(const Node &a,const Node &b) {return a.t<b.t;}
vector<Node> V;
int main() {
	freopen("rank1.in","r",stdin);
	freopen("rank1.ans","w",stdout);
	scanf("%d%d",&n,&k);dv=1;
	for(int i=2;i<=k;i++) dv=dv*i/__gcd(dv,i);
	for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) ans[j]=0;
		for(int ff=0;ff<dv;ff++) {
			for(int j=1;j<=n;j++) for(int l=0;l<=k;l++) {
				if(l==0) {K[j]=0;B[j]=a[j][0];continue;}
				K[j]+=dv/l*a[j][l];B[j]+=(ff/l)*a[j][l];
			}
			int rk=1;V.clear();
			for(int j=1;j<=n;j++) if(i!=j) {
				if(B[j]>B[i]) {
					rk++;
					if(K[j]<K[i]) {
						V.push_back(Node((B[j]-B[i]+K[i]-K[j]-1)/(K[i]-K[j]),-1));
					}
				}
				else if(K[j]>K[i]) {
					V.push_back(Node((B[i]-B[j]+1+K[j]-K[i]-1)/(K[j]-K[i]),1));
				}
			}
			int lst=0;
			sort(V.begin(),V.end(),cmp);
			for(auto x:V) {
				if(ans[rk]!=-1) ans[rk]+=x.t-lst;
				lst=x.t;rk+=x.v;
			}
			ans[rk]=-1;
		}
		for(int j=1;j<=n;j++) printf("%lld%c",ans[j],j==n?'\n':' ');
	}
	return 0;
}
/*
2 1
100 0
0 1
101 -1
-1 100

3 3
17 96 1 58
36 59 33 29
84 68 20 94
-1 6 1
0 1 -1
8 -1 0

*/
