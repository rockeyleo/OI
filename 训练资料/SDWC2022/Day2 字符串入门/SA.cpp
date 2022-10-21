//UOJ #35 后缀排序，大家板子可以交这个题 
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" " 
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn() 
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
const int N=100010;
int t1[N<<1],t2[N<<1],cnt[N],a[N<<1],sa[N],rk[N],h[N];char s[N];
//sa[i]表示排名为i的后缀的左端点下标，rk[i]表示以i为左端点的后缀的排名 
inline int cmp(int *a,int x,int y,int l) { return a[x]==a[y]&&a[x+l]==a[y+l]; } 
inline int getSA(char *s,int n,int m)//m是字符集大小，默认从1开始。s下标从1开始。 
{
	int *x=t1,*y=t2;
	memset(t1,0,sizeof(int)*(2*n+1));//这份板子需要访问两倍的空间，有些数组需要开两倍，多组数据清零的时候也要记得清两倍。 
	memset(t2,0,sizeof(int)*(2*n+1));
	memset(a,0,sizeof(int)*(2*n+1));
	rep(i,1,m) cnt[i]=0;			//rep(i,a,b) 就是 for(int i=a;i<=b;i++) 
	rep(i,1,n) cnt[x[i]=a[i]=s[i]-'a'+1]++;
	rep(i,1,m) cnt[i]+=cnt[i-1];
	for(int i=n;i;i--) sa[cnt[x[i]]--]=i;
	for(int j=1,p=0;p<=n;j<<=1,m=p)
	{
		p=0;rep(i,n-j+1,n) y[++p]=i;
		rep(i,1,n) if(sa[i]>j) y[++p]=sa[i]-j;
		rep(i,1,m) cnt[i]=0;
		rep(i,1,n) cnt[x[y[i]]]++;
		rep(i,1,m) cnt[i]+=cnt[i-1];
		for(int i=n;i;i--) sa[cnt[x[y[i]]]--]=y[i];
		swap(x,y),p=1;
		rep(i,1,n) x[sa[i]]=(cmp(y,sa[i],sa[i-1],j)?p-1:p++);
	}
	rep(i,1,n) rk[sa[i]]=i;
	for(int i=1,p=0,j;i<=n;h[rk[i++]]=p) //求 h[i]=LCP(suffix(sa[i-1]),suffix(sa[i])).
		for((p?p--:0),j=sa[rk[i]-1];max(i,j)+p<=n&&a[i+p]==a[j+p];p++);
	return 0;
}
int main()       
{
	scanf("%s",s+1);int n=(int)strlen(s+1);getSA(s,n,30);
	rep(i,1,n) printf("%d ",sa[i]);printf("\n");
	rep(i,2,n) printf("%d ",h[i]);return !printf("\n");
}
/*
text data:

sample input:
ababa

sample output:
5 3 1 4 2
1 3 0 2

*/
