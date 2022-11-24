#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int read()
{
	int num=0,fu=1;
	char cr=getchar();
	while(cr<'0' || cr>'9')
	{
		if(cr=='-')	fu=-1;
		cr=getchar();
	}
	while(cr>='0' && cr<='9')
	{
		num= (num<<1)+(num<<3)+cr-'0';
		cr=getchar();
	}
	return num*fu;
}


struct TREE{
	int mn,id;
}tr[N<<2];
struct BX{
	int a,c,w;
}bx[N];
int n,q;

void ps_up(int rt)
{
	int ls=(rt<<1);
	int rs=(rt<<1|1);
	if(tr[ls].mn < tr[rs].mn)
		tr[rt]=tr[ls];
	else tr[rt]= tr[rs];
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tr[rt]={bx[l].a, l};
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1, l,mid);
	build(rt<<1|1, mid+1,r);
	ps_up(rt);
}
TREE qry(int rt,int l,int r,int L,int R)
{
	if(l>=L && r<=R)
		return tr[rt];
	int mid=(l+r)>>1;
	TREE res1={1e10,0},res2={1e10,0};
//	TREE res1,res2;
//	res1.id=0;
//	res1.mn=1e10;
//	res2.id=0;
//	res2.mn=1e10;
	if(mid>=L) res1= qry(rt<<1, l,mid, L,R);
	if(mid+1<=R) res2= qry(rt<<1|1, mid+1,r, L,R);
	if(res1.mn < res2.mn) return res1;
	else return res2;
}
void chg(int rt,int l,int r,int X)
{
	if(l==r && r==X)
	{
		tr[rt]={bx[l].a, l};
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=X) chg(rt<<1, l,mid, X);
	if(mid+1 <=X) chg(rt<<1|1, mid+1,r, X);
	ps_up(rt);
}
int ans=0;
void Ans(int l,int r,int jq)
{
	TREE res= qry(1,1,n, l,r);
	int mid= res.id;
	int mn= res.mn;
	ans= ans+(mn-jq)*(bx[l].w +bx[r].w);
//	if(l==r) return;
	if(mid-1 >= l) Ans(l,mid-1, mn);
	if(mid+1 <= r) Ans(mid+1,r, mn);
}

signed main()
{
//	freopen("in.in","r",stdin);
	
	n=read(),q=read();
	for(int i=1; i<=n; i++)
	{
		bx[i].a=read();
		bx[i].c=read();
		bx[i].w=read();
	}
	build(1, 1,n);
	for(int i=1; i<=q; i++)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),v1=read(),v2=read();
			bx[x].a= v1;
			bx[x].w= v2;
			chg(1,1,n, x);
		}
		if(opt==2)
		{
			int l=read(),r=read(),v=read();
			for(int j=l; j<=r; j++)
				bx[j].c= v;
		}
		if(opt==3)
		{
			int l=read(),r=read();
			int ll=l;
			ans=0;
			for(int ll=l; ll<=r; )
			{
				int rr=ll;
				while(bx[rr+1].c ==bx[ll].c && rr+1<=r)					//±ß½ç 
					rr+=1;
				Ans(ll,rr,0);
				
				ll=rr+1;
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
