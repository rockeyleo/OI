#include <bits/stdc++.h>
#define inf 20000007
using namespace std;
int con[5][5],a[57][57];
int n,m;
int countbit(int s){
    int st=s,ans=0;
    while (st>0){
        ans+=(st%2==1);
        st/=2;
    }
    return ans;
}
int deal(int p0,int p1,int q0,int q1){
    if (p0) p0=1;
    if (p1) p1=1;
    if (q0) q0=1;
    if (q1) q1=1;
//p means whether two blocks in the row are the same
//q means whether two blocks in the column are the same
//the aim of the function is just to calculate the possible answer of the blocks of size 2*2
    int cnt=0;
    for (int i=0;i<=1;i++)
        for (int j=0;j<=1;j++)
            cnt+=(con[i][j]==1);
    if (p0+p1+q0+q1>=3) return min(cnt,4-cnt);
//all the four blocks must be the same if the sum of p&q are not less than 3
    else if(p0+p1+q0+q1==2){
//there must be exact three blocks that are the same or two blocks in the two rows/columns
//then there will be four conditions
        if (p0&&p1) return ((con[0][0]!=con[0][1])+(con[1][0]!=con[1][1]));
        if (q0&&q1) return ((con[0][0]!=con[1][0])+(con[0][1]!=con[1][1]));
        int tot=0;
        if (p0&&q0) tot=cnt-(con[1][1]==1);
        if (p0&&q1) tot=cnt-(con[1][0]==1);
        if (p1&&q0) tot=cnt-(con[0][1]==1);
        if (p1&&q1) tot=cnt-(con[0][0]==1);
        return min(tot,3-tot);
    } else if (p0+p1+q0+q1==1){
//there will also be four conditions
        int tot=0;
        if (p0) tot+=(con[0][0]!=con[0][1]);
        if (p1) tot+=(con[1][0]!=con[1][1]);
        if (q0) tot+=(con[0][0]!=con[1][0]);
        if (q1) tot+=(con[0][1]!=con[1][1]);
        return tot;
    }
//then the answer must be 0
    else return 0;
}
int calc(int rowcnt,int st){
    int cost[57][5],f[57][57];
    for (int i=0;i<n/2;i++){
        for (int j=0;j<=2;j++) cost[i][j]=2*m;
//x means whether two blocks in the same row are the same
//y means whether two blocks in the same column are the same
        for (int x1=0;x1<=1;x1++)
            for (int x2=0;x2<=1;x2++){
                int now=0;
                for (int j=0;j<m/2;j++){
                    int y1=st&(1<<j),y2=st&(1<<(m-j-1));
                    con[0][0]=a[i][j];
                    con[0][1]=a[i][m-j-1];
                    con[1][0]=a[n-i-1][j];
                    con[1][1]=a[n-i-1][m-j-1];
                    now+=deal(x1,x2,y1,y2);
                }
                cost[i][x1+x2]=min(cost[i][x1+x2],now);
            }
    }
    for (int i=0;i<=n/2;i++)
        for (int j=0;j<=rowcnt;j++)
            f[i][j]=inf;
    f[0][0]=0;
    for (int i=1;i<=n/2;i++)
        for (int j=0;j<=rowcnt;j++)
            for (int k=0;k<=2&&k<=j;k++)
                f[i][j]=min(f[i][j],f[i-1][j-k]+cost[n/2-i][k]);
    return f[n/2][rowcnt];
}

int rowcnt, colcnt;
char tmp[55];
int main(){
    scanf("%d%d%d%d",&n,&m, &rowcnt, &colcnt);
    for (int i=0;i<n;i++){
        scanf("%s", tmp);
        for (int j=0;j<m;j++)
            a[i][j]=tmp[j]-'A';
    }
    int ans=inf;
    for (int st=0;st<(1<<m);st++)
        if (countbit(st)==colcnt) ans=min(ans,calc(rowcnt,st));
    cout<<ans<<endl;
    return 0;
}