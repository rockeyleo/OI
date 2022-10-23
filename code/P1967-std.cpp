#include<bits/stdc++.h>//kruskal重构树,求两点之间所有的路径中，最短的边的最大值
using namespace std;
int n,m,q;
int nxt[200010],to[200010],head[50010],w[50010],tot;//重构树的边，w是新树点权
int cnt;
int f[50010];//kruskal算法的并查集
int fa[50010][20],dep[50010];//用于求lca
int vis[50010];
struct orz//用于kruskal算法
{
    int x,y,val;
}a[100010];
char buf[1<<15],*fs,*ft;
inline char getc(){return (ft==fs&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),ft==fs))?0:*fs++;}
inline int read()
{
    int x=0,f=1;  char ch=getc();
    while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getc();}
    while(isdigit(ch))  {x=(x<<1)+(x<<3)+(ch^48);  ch=getc();}
    return x*f;
}
void put(int x)
{
    if(x==0){putchar('0');putchar('\n');return;}
    if(x<0){putchar('-');x=-x;}
    int num=0;char ch[16];
    while(x) ch[++num]=x%10+'0',x/=10;
    while(num) putchar(ch[num--]);
    putchar('\n');
}
inline int my(orz a,orz b)
{
    return a.val>b.val;
}
inline int find(int x)
{
    int r=x,mid,j=x;
    while(r!=f[r]) r=f[r];
    while(j!=f[j]) mid=f[j],f[j]=r,j=mid;
    return r;
}
inline void add(int xx,int yy)
{
    to[++tot]=yy;nxt[tot]=head[xx];head[xx]=tot;
}

void dfs(int x)//预处理lca
{
    vis[x]=1;
    for(int ct=head[x];ct;ct=nxt[ct])
    {
        int y=to[ct];
        fa[y][0]=x;
        for(int i=1;i<=15;++i)
            fa[y][i]=fa[fa[y][i-1]][i-1];
        dep[y]=dep[x]+1;
        dfs(y);
    }
}

// void dfs(int now, int f=0){
//     vis[now] = 1;
//     fa[now][0] = f; dep[now] = dep[f]+1;
//     for(int i=1;(i<<1)<=dep[now];i++){
//         fa[now][i] = fa[fa[now][i-1]][i-1];
//     }
//     for(int i=head[now];i;i=nxt[i]){
//         if(to[i]!=f)dfs(to[i],now);
//     }
// }

inline int lca(int x,int y)//求解lca
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=15;i>-1;--i) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=15;i>-1;--i) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

int main()
{
    freopen("P1967_3.in","r",stdin);
    freopen("P1967_3.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=m;++i)
        a[i].x=read(),a[i].y=read(),a[i].val=read();
    for(int i=1;i<=n;++i)f[i]=i,f[n+i]=n+i;//并查集初始化

    cnt=n;sort(a+1,a+m+1,my);//kruskal算法+重构
    for(int i=1;i<=m;++i)
    {
        int fx=find(a[i].x),fy=find(a[i].y);
        if(fx!=fy)
            f[fx]=f[fy]=++cnt,w[cnt]=a[i].val,add(cnt,fx),add(cnt,fy);
    }

    for(int i=cnt;i>n;--i)//预处理lca,注意原图可能不联通，所以我们可能构出了一个森林
        if(!vis[i])
            dep[i]=1,fa[i][0]=i,dfs(i);

    q=read();//处理询问
    for(int i=1;i<=q;++i) 
    {
        int xx=read(),yy=read();
        if(find(xx)!=find(yy)) put(-1);//两点可能不联通
        else put(w[lca(xx,yy)]);
    }
    return 0;
}