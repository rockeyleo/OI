#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define RG register
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
int gi() {
  char c;int w;bool q=true;
  while (((c=getchar())<'0'||'9'<c)&&c!='-');
  if (c=='-') q=false,w=0; else w=c-'0';
  while ('0'<=(c=getchar())&&c<='9') w=(w<<1)+(w<<3)+c-'0';
  return q?w:-w;
}
const int N=1e6+100;
int c[N],sa[N],x[N];
int pre[N],now[N],rk[N],s[N<<2],g,s1,s2;long long sum[N<<2],all,f1,f2;
inline bool cmp(const int &a,const int &b) { return c[a]>c[b]; }
inline void modify(RG int i,RG int l,RG int r,RG int k,RG int x) {
  if (x>0) s[i]++; else s[i]--; sum[i]+=x;
  if (l==r) return;
  int mid=(l+r)>>1;
  if (k<=mid) modify(i<<1,l,mid,k,x);
  else modify(i<<1|1,mid+1,r,k,x);
}
inline void find1(RG int i,RG int l,RG int r) {
  if (l==r) { if (s[i]&&(sum[i]+f1)<<1<=all) s1++,f1+=sum[i]; return; }
  RG int mid=(l+r)>>1;
  if ((sum[i<<1]+f1)<<1<=all) {
    s1+=s[i<<1],f1+=sum[i<<1];
    find1(i<<1|1,mid+1,r);
  }
  else find1(i<<1,l,mid);
}
inline void find2(RG int i,RG int l,RG int r) {
  if (l==r) { if (s[i]&&(sum[i]+f2)<<1<=all) s2++,f2+=sum[i]; return; }
  RG int mid=(l+r)>>1;
  if ((sum[i<<1|1]+f2)<<1<=all) {
    s2+=s[i<<1|1],f2+=sum[i<<1|1];
    find2(i<<1,l,mid);
  }
  else find2(i<<1|1,mid+1,r);
}
int main() {
   RG int n=gi(),i,len=0,l,r,mid,t,m=0;
   for (i=1;i<=n;i++) if ((c[i]=gi())>0) sa[++m]=i,x[++len]=c[i];
   sort(x+1,x+1+len);len=unique(x+1,x+1+len)-x-1;
   for (i=1;i<=n;i++) {
     t=c[i]>0?c[i]:-c[i];
     for (l=1,r=len;l!=r;t<=x[mid=(l+r)>>1]?r=mid:l=mid+1);
     c[i]=c[i]>0?l:-l;
   }
   for (i=1;i<=n;i++)
     if (c[i]>0) pre[i]=now[c[i]],now[c[i]]=i;
     else pre[i]=now[-c[i]],now[-c[i]]=pre[now[-c[i]]];
   sort(sa+1,sa+1+m,cmp);
   for (i=1;i<=m;i++) rk[sa[i]]=i;
   for (i=1;i<=n;i++) {
     if (c[i]>0) {
       g++;all+=x[c[i]];
       modify(1,1,m,rk[i],x[c[i]]);
     }
     else {
       g--;all-=x[-c[i]];
       modify(1,1,m,rk[pre[i]],-x[-c[i]]);
     }
     s1=s2=f1=f2=0;
     find1(1,1,m);
     find2(1,1,m);
     printf("%d ",(abs(f1-(all-f1))<=abs(f2-(all-f2))?s1:g-s2));
   }
}