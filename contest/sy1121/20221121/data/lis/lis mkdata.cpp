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

inline int RD0(int R)
{
    return ((rand()<<15)|rand())%(R+1);
}

inline int RD1(int R)
{
    return ((rand()<<15)|rand())%R+1;
}

int a[N];

int main()
{
    int n,i,k1,k2,m;
    srand(time(0));
    int test;
    for(test=1;test<=6;test++)
    {
        char name1[20];
        make_inname(name1,test);
        freopen(name1,"w",stdout);

        n=900+RD1(100);
        k1=RD1(n),k2=RD1(n);
        if(k1>k2)
            swap(k1,k2);

        cout<<n<<endl;
        for(i=1;i<=k1;i++)
            printf("1 ");
        for(i=k1;i<=k2;i++)
            printf("%d ",i);
        for(i=k2;i<=n;i++)
            printf("1 ");
        cout<<endl;
    }
    for(test=7;test<=14;test++)
    {
        char name1[20];
        make_inname(name1,test);
        freopen(name1,"w",stdout);

        n=900+RD1(100);
        for(i=1;i<=n;i++)
            a[i]=i;

        m=(test-7)*10;

        for(i=1;i<=m;i++)
            a[RD1(n)]=RD1(n);

        cout<<n<<endl;
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        cout<<endl;
    }
    for(test=15;test<=20;test++)
    {
        char name1[20];
        make_inname(name1,test);
        freopen(name1,"w",stdout);

        n=290000+RD1(10000);
        for(i=1;i<=n;i++)
            a[i]=i;

        m=(test-15)*100;

        for(i=1;i<=m;i++)
            a[RD1(n)]=RD1(n);

        cout<<n<<endl;
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        cout<<endl;
    }
    return 0;
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
