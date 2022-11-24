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
#define N 500005
#define P 1000000007
#define Loc 6 /////////////////////////////////////////
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
		strcpy(name,"median1.in");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"median10.in");
		name[Loc]=x/10+48;
		name[Loc+1]=x%10+48;
	}
}

void make_outname(char *name,int x)
{
	if(x<10)
	{
		strcpy(name,"median1.out");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"median10.out");
		name[Loc]=x/10+48;
		name[Loc+1]=x%10+48;
	}
}
int a[N];
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

    int ans=0,i,n,cnt,l,r;
    //freopen("median.in","r",stdin);
    //freopen("median.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    cnt=0;
    a[0]=a[1];
    a[n+1]=a[n];
    n++;
    for(i=1;i<=n;i++)
    {
        //debug(cnt);
        if(a[i]!=a[i-1])
            cnt++;
        else
        {
            ans=max(ans,cnt/2);
            if(cnt>=2)
            {
                if(cnt%2==0)
                    for(r=i;r>=i-cnt;r--)
                        a[r]=a[i];
                else
                {
                    l=i-cnt-2;
                    r=i;
                    for(;r>l;r--,l++)
                        a[r]=a[i],a[l]=a[i-cnt-2];
                }
            }
            cnt=0;
        }
    }
    //ans=max(ans,cnt/2);
    cout<<ans<<endl;
    for(i=1;i<=n-1;i++)
        printf("%d ",a[i]);

}
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))
