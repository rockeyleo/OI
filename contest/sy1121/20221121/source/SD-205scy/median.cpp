#include<cstdio>
#include<bitset>
#include<ctime>
using namespace std;
int n,cnt,cnt2,tmp;
bool a[500001],b[500001],flag=1;
bool *now,*lst;
// bitset<500001> a;
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    while(flag){
        flag=0;
        if(cnt2==20){
            cnt2=0;
            if(clock()>1900){
                printf("-1");
                return 0;
            }
        }
        if(cnt&1){
            now=a; lst=b; 
        }
        else{
            now=b; lst=a; 
        }
        now[1]=lst[1];
        now[n]=lst[n];
        tmp=lst[1]+lst[2];
        for(int i=2;i<n;++i){
            tmp=tmp+lst[i+1]-lst[i-2];
            if(tmp==0)now[i]=0;
            else if(tmp==1)now[i]=0;
            else if(tmp==2)now[i]=1;
            else now[i]=1;
            if(now[i]!=lst[i])flag=1;
        }
        ++cnt; ++cnt2;
    }
    printf("%d\n",cnt-1);
    for(int i=1;i<=n;++i)printf("%d ",now[i]);
    return 0;
}