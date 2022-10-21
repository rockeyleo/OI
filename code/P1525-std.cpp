#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,f[40001],x,y;
struct data
{
    int a,b,c;
} e[100001];
int gz(const data &a,const data &b)
{
    if(a.c>b.c)return 1;
    else return 0;
}
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
int main()
{
    freopen("P1525_2.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=m; i++)
        scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].c);
    for(int i=1; i<=n*2; i++)
        f[i]=i;
    sort(e+1,e+m+1,gz);
    for(int i=1; i<=m; i++)
    {
        x=find(e[i].a);
        y=find(e[i].b);
        if(x==y)
        {
            printf("%d\n",e[i].c);
            return 0;
        }
        f[y] = find(e[i].a + n);
        f[x] = find(e[i].b + n);
    }
    puts("0");
    return 0;
}//缩进坑爹
