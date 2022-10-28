#include<bits/stdc++.h>
using namespace std;
const int maxn=11451,maxm=1140,INF=0x3f3f3f3f;
int n,m,k,st,ans=INF,cnt;
int up[maxn],down[maxn];
int f[maxn][maxm];
bool fl;
int red() {
    int as = 0; int fl = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') fl = -1; ch = getchar();}
    while(isdigit(ch)) {as = as * 10 + ch - '0'; ch = getchar();}
    return as * fl;
}
struct edge{
    int p,h,l;
}e[maxn];
bool cmp(edge a,edge b){
    return a.p<b.p;
}

void init(){
    n=red();m=red();k=red();
    for(int i=0;i<=n-1;i++){    //????up||down
        up[i]=red();
        down[i]=red();
    }
    for(int i=1;i<=k;i++){
        e[i].p=red();
        e[i].l=red();
        e[i].h=red();
    }
    sort(e+1,e+k+1,cmp);        //???????
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=INF;        //??INF??
    st=1;                       //1?????
}

void dp(){
    for(int i=1;i<=n;i++){
        if(i==e[st].p&&k!=0){       //?????
            fl=false;               //???????
            for(int h=e[st].l+1;h<=e[st].h-1;h++){
                if(h>up[i-1]){
                    f[i][h]=min(f[i-1][h-up[i-1]]+1,f[i][h]);       //??
                    if(h+up[i-1]<e[st].h-1){                        //??
                        f[i][h+up[i-1]]=min(f[i][h]+1,f[i][h+up[i-1]]);
                    }
                    if(h+up[i-1]>m) f[i][m]=min(f[i][h]+1,f[i][m]); //???????
                }
                if(h<=m-down[i-1]){
                    f[i][h]=min(f[i-1][h+down[i-1]],f[i][h]);       //??
                }
                if(f[i][h]!=INF&&f[i][h]>=0){                       //?????????????
                    fl=true;
                }
            }
            if(fl==false){                  //??????
                break;
            }
            else cnt++;                     //??
            st++;                           //???????
        }
        else{
            for(int h=1;h<=m;h++){
                if(h>up[i-1]){
                    f[i][h]=min(f[i-1][h-up[i-1]]+1,f[i][h]);       //??
                    f[i][h+up[i-1]]=min(f[i][h]+1,f[i][h+up[i-1]]); //??
                    if(h+up[i-1]>m) f[i][m]=min(f[i][h]+1,f[i][m]); //????
                }
                if(h<=m-down[i-1]){
                    f[i][h]=min(f[i-1][h+down[i-1]],f[i][h]);       //??
                }
                for(int k=0;k<=up[i-1];k++){
                    f[i][m]=min(f[i][m],f[i-1][m-k]+1);             //???
                }
            }
        }
    }
}

void out(){
    for(int i=1;i<=m;i++)
        ans=min(f[n][i],ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
    //if(fl==false&&k!=0){
        //printf("0\n");
        //printf("%d\n",cnt);
    //}
    //else{
        //printf("1\n");
        //printf("%d\n",ans);
    //}
}

int main() {
	freopen("P1941_8.in","r",stdin);
	freopen("P1941_8.out","w",stdout);
    init();
    dp();
    out();
    return 0;
}
