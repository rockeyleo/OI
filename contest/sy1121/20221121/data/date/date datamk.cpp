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
#define N 100005
#define P 1000000007
#define Loc 4 /////////////////////////////////////////
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
		strcpy(name,"date1.in");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"date10.in");
		name[Loc]=x/10+48;
		name[Loc+1]=x%10+48;
	}
}

void make_outname(char *name,int x)
{
	if(x<10)
	{
		strcpy(name,"date1.out");
		name[Loc]=x+48;
	}
	else if(x<100)
	{
		strcpy(name,"date10.out");
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

int p[N];

int main()
{
    srand(time(0));
    int test,n,m,i,j;
for(test=1;test<=5;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=90+RD1(10),m=90+RD1(10);

    cout<<n<<endl;
    for(i=2;i<=n;i++)
        printf("%d %d\n",i,RD1(i-1));

    cout<<m<<endl;
    for(i=1;i<=m;i++)
        printf("%d %d\n",RD1(n),RD1(n));
}

for(test=6;test<=10;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=900+RD1(100),m=900+RD1(100);

    cout<<n<<endl;
    for(i=2;i<=n;i++)
        printf("%d %d\n",i,RD1(i-1));

    cout<<m<<endl;
    for(i=1;i<=m;i++)
        printf("%d %d\n",RD1(n),RD1(n));
}

for(test=11;test<=14;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=90000+RD1(10000),m=90000+RD1(10000);

    cout<<n<<endl;
    for(i=1;i<=n;i++)
        p[i]=i;

    random_shuffle(p+1,p+1+n);
    for(i=1;i<=n;i++)
        printf("%d %d\n",p[i],p[i+1]);

    cout<<m<<endl;
    for(i=1;i<=m;i++)
        printf("%d %d\n",RD1(n),RD1(n));
}

for(test=15;test<=17;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=90000+RD1(10000),m=90000+RD1(10000);

    cout<<n<<endl;
    for(i=2;i<=n;i++)
        printf("%d %d\n",i,RD1(i-1));

    cout<<m<<endl;
    for(i=1;i<=m;i++)
        printf("%d %d\n",RD1(n),RD1(n));
}

for(test=18;test<=20;test++)
{

    char name1[20];
    make_inname(name1,test);
    freopen(name1,"w",stdout);

    n=90000+RD1(10000),m=90000+RD1(10000);

    set<int> s;
    cout<<n<<endl;
    for(i=n;i>n-10;i--)
        s.insert(i);
    for(i=n-10;i;i--)
    {
        do
        {
            j=RD1(s.size());
            set<int>::iterator it;
            for(it=s.begin();--j;it++)
                ;
            printf("%d %d\n",i,(*it));
            s.erase(it);
        }while(s.size()&&RD1(i)<=s.size());
        s.insert(i);
    }

    cout<<m<<endl;
    for(i=1;i<=m;i++)
        printf("%d %d\n",RD1(n),RD1(n));
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
