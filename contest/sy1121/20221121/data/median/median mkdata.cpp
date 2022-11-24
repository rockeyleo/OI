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

inline int RD0(int R)
{
    return ((rand()<<15)|rand())%(R+1);
}

inline int RD1(int R)
{
    return ((rand()<<15)|rand())%R+1;
}

int n,a[N],m,loc[N];

int main()
{
    srand(time(0));
    int test,i,j;
for(test=1;test<=5;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=RD1(2)+8;
    m=RD1(n/2);
    for(i=1;i<=m;i++)
        loc[i]=RD1(n);

    sort(loc+1,loc+1+m);
    loc[0]=0,loc[m+1]=n;
    for(i=1;i<=m+1;i++)
        if(i&1)
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=RD1(2)*RD1(2)*RD1(2)%2;
        else
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=j&1;

    cout<<n<<endl;
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    cout<<endl;
}

for(test=6;test<=10;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=RD1(100)+900;
    m=RD1(100);
    for(i=1;i<=m;i++)
        loc[i]=RD1(n);

    sort(loc+1,loc+1+m);
    loc[0]=0,loc[m+1]=n;
    for(i=1;i<=m+1;i++)
        if(i&1)
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=RD1(2)*RD1(2)*RD1(2)%2;
        else
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=j&1;

    cout<<n<<endl;
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    cout<<endl;
}
//return 0;
for(test=11;test<=20;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=RD1(100000)+400000;
    m=RD1(100);
    for(i=1;i<=m;i++)
        loc[i]=RD1(n);

    sort(loc+1,loc+1+m);
    loc[0]=0,loc[m+1]=n;
    for(i=1;i<=m+1;i++)
        if(i&1)
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=RD1(2)*RD1(2)*RD1(2)%2;
        else
            for(j=loc[i-1]+1;j<=loc[i];j++)
                a[j]=j&1;

    cout<<n<<endl;
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    cout<<endl;
}
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
/*
int test;
for(test=1;test<=20;test++)
{

    char name1[20];
    char name2[20];
    make_inname(name1,test);
    make_outname(name2,test);
    freopen(name1,"r",stdin);
    freopen(name2,"w",stdout);

int test;
for(test=1;test<=20;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);
*/
