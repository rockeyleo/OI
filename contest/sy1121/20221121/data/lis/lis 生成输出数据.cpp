#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 300005
#define P 1000000007
#define Loc 3 /////////////////////////////////////////
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char name[25];
void make_inname(char *name,int x)
{
	if(x<10)
	{
		strcpy(name,"lis1.in");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"lis10.in");
		name[Loc]=x/10+48;
		name[Loc+1]=x%10+48;
	}
}

void make_outname(char *name,int x)
{
	if(x<10)
	{
		strcpy(name,"lis1.out");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"lis10.out");
		name[Loc]=x/10+48;
		name[Loc+1]=x%10+48;
	}
}


int a[300005],l[300005],r[300005];
int main()
{
    int test;
for(test=1;test<=20;test++)
{

    char name1[20];
    char name2[20];
    make_inname(name1,test);
    make_outname(name2,test);
    freopen(name1,"r",stdin);
    freopen(name2,"w",stdout);
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(a,0,sizeof(a));

    int n,i,cou=0,ans=0;

    cin>>n;
    a[0]=0;
    a[n+1]=0;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            cou++;
            l[i]=cou;
        }
        else
            cou=1,l[i]=cou;
    }
    cou=0;
    for(i=n;i>=1;i--)
    {
        if(a[i]<a[i+1])
        {
            cou++;
            r[i]=cou;
        }
        else
            cou=1,r[i]=cou;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i-1]+1<a[i+1])
            ans=max(ans,l[i-1]+1+r[i+1]);
        else
        {
            ans=max(ans,l[i-1]+1);
            ans=max(ans,r[i+1]+1);
        }
    }
    cout<<ans<<endl;

}
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
