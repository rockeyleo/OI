#include<cstdio>
#include<algorithm>
#include<iostream>
#define LL long double
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );
  while(c<'0' || c>'9') c=getchar( );
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  return sum;
}
int T;
LL s1,s2,tx,ty,n,a,b;
int main( )
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  int g;double x,y;
  T=read( );T--;
  scanf("%lf %lf",&x,&y);
  s1+=(x*y);s2+=(x*x);
  tx+=x;ty+=y;n++;
  while(T--)
    {
      scanf("%lf %lf",&x,&y);
      s1+=(x*y);s2+=(x*x);
      tx+=x;ty+=y;n++;
      a=(s1-tx/n*ty)/(s2-tx/n*tx);
      b=(ty-a*tx)/n;
      printf("%.4lf %.4lf\n",(double)a,(double)b);
    }
  return 0;
}


