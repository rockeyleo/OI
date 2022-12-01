#include <bits/stdc++.h>
#define Maxn 2507
#define Maxm 5507
#define inf 200000007
const int MX=10;
using namespace std;
char S[Maxm];
char T[Maxm];
int n;
int d[Maxn];
int f[Maxn][Maxm][2];
bool vis[Maxn][Maxm][2];

int solve(int pos, int x, int dir)
{
//pos means which number it is dealing with now
//x means the addition of the interval
//dir means the interval is to add or to minus
    if (vis[pos][x][dir]) return f[pos][x][dir];
    vis[pos][x][dir]=true;
    if (pos==n)
    {
        f[pos][x][dir]=0;
        return f[pos][x][dir];
    }
    f[pos][x][dir]=inf;
    for (int newdir=0;newdir<=1;newdir++)
    {
        for (int y=max(x-MX+1,0);y<=min(x+MX-1,5500);y++)
        {
            if (newdir==0&&((d[pos]-y%MX+MX)%MX!=0)) continue;
            if (newdir==1&&((d[pos]+y)%MX!=0)) continue;
            int z = (newdir!=dir) ? y:max(y-x,0);
            f[pos][x][dir]=min(f[pos][x][dir],z+solve(pos+1,y,newdir));
        }
    }
    return f[pos][x][dir];
};

int main(){
    scanf("%s%s", S, T);
    n = strlen(S);
    for (int i=0;i<n;i++) d[i]=(S[i]-T[i]+MX)%MX;
    memset(vis,false,sizeof(vis));
    memset(f,0,sizeof(f));
    printf("%d", solve(0,0,0));
    return 0;
}