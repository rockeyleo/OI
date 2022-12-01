#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,S=100;
int n,tot,m,q,a[N],l[N],r[N],f[N],b[N],fa;
vector<int>v[N];
ll ans[N],c[N];
struct Ask{
	int l1,r1,l2,r2,from;
}A[N];
struct Tree{
	int l,r,num1,max1,max2,flag;
	ll num;
}T[N*4];
int cmp(Ask x,Ask y){
	return x.l1<y.l1;
}
int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
void change(int x){
	c[(x-1)/S+1]-=b[x];
	b[x]=sqrt(b[x]);
	c[(x-1)/S+1]+=b[x];
}
void insert(int l,int r){
	for (int i=find(l);i<=r;i=find(i+1)){
		change(i);
		if (b[i]==1)f[i]=i+1;
	}
}
ll get(int x,int y){
	int l=(x-1)/S+1,r=(y-1)/S+1;
	ll ans=0;
	if (l==r){
		for (int i=x;i<=y;i++)ans+=b[i];
	}
	else {
		for (int i=x;i<=l*S;i++)ans+=b[i];
		for (int i=l+1;i<r;i++)ans+=c[i];
		for (int i=(r-1)*S+1;i<=y;i++)ans+=b[i];
	}
	return ans;
}
void solve(vector<int> v){
	reverse(v.begin(),v.end());
	memset(c,0,sizeof c);
	for (int i=1;i<=n;i++)b[i]=a[i],c[(i-1)/S+1]+=b[i],f[i]=i;
	f[n+1]=n+1;
	for (int i=A[v[0]].l1;i<=A[v[0]].r1;i++)insert(l[i],r[i]);
	ans[A[v[0]].from]=get(A[v[0]].l2,A[v[0]].r2);
	for (int i=1;i<(int)v.size();i++){
		for (int j=A[v[i]].l1;j<A[v[i-1]].l1;j++)insert(l[j],r[j]);
		for (int j=A[v[i-1]].r1+1;j<=A[v[i]].r1;j++)insert(l[j],r[j]);
		ans[A[v[i]].from]=get(A[v[i]].l2,A[v[i]].r2);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=q;i++)scanf("%d%d%d%d",&A[i].l1,&A[i].r1,&A[i].l2,&A[i].r2),A[i].from=i;
	sort(A+1,A+q+1,cmp);
	for (int i=1;i<=q;i++){
		if (!tot||A[v[tot].back()].r1<A[i].r1)v[++tot].push_back(i);
		else {
			int l=1,r=tot;
			while (l<r){
				int mid=(l+r)/2;
				if (A[v[mid].back()].r1>=A[i].r1)r=mid;
				else l=mid+1;
			}
			v[l].push_back(i);
		}
	}
	for (int i=1;i<=tot;i++)solve(v[i]);
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}


