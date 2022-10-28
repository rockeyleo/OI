#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int shu,ch;
bool tf;
int dy()//读入优化，记得要判断负数
{
    shu=ch=0,tf=true;
    while(ch<'0'||ch>'9')tf=ch=='-'?false:true,ch=getchar();
    while(ch>='0'&&ch<='9')shu=shu*10+ch-'0',ch=getchar();
    return tf?shu:-shu;
}
struct POS//存储输入的点的坐标
{
    int x,y,z;
}pos[2000];
queue<int>bfs;//bfs所用的队列
int lc;
bool visit[2000];//是否有到达过这个点
struct Edge//链表，我是模仿链式前向星来写的
{
    int t;
    int nexty;
}edge[3000000];
int head[2000];
long long pf(int a)//平方，注意要int转long long
{
    return ((long long)a)*((long long)a);
}
long long dis(int a,int b)//算出距离的平方
{
    return pf(pos[a].x-pos[b].x)+pf(pos[a].y-pos[b].y)+pf(pos[a].z-pos[b].z);
}
int cnt;
void add(int a,int b)//链表加边
{
    cnt++;
    edge[cnt].t=b;
    edge[cnt].nexty=head[a];
    head[a]=cnt;
}
int main()
{
    //freopen("cheese.in","r",stdin);
    //freopen("cheese.out","w",stdout);//注释掉
    int t=dy();
    int n,h,r;
    bool tf;
    while(t--)
    {
        n=dy(),h=dy(),r=dy();
        for(int i=0;i<n;i++)
        {
            pos[i].x=dy();
            pos[i].y=dy();
            pos[i].z=dy();
        }
        while(!bfs.empty())bfs.pop();
        for(int i=0;i<n;i++)visit[i]=false,head[i]=0;
        cnt=0;//初始化
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dis(i,j)<=4*pf(r))//如果两圆心距离小于2r（这里是平方形式，所以变成4*r^2），则它们可以互相到达
                {
                    add(i,j);
                    add(j,i);//互相加边
                }
            }
        }
        tf=false;//tf即是否可以到达上面
        for(int i=0;i<n&&!tf;i++)
        {
            if(pos[i].z<=r)//如果可以从底层进入
            {
                bfs.push(i);
                visit[i]=true;//记得打上visit
                if(h-pos[i].z<=r)tf=true;//如果已经可以走到上层，则直接跳出
            }
        }
        while(!tf&&!bfs.empty())//bfs开始
        {
            lc=bfs.front();
            bfs.pop();
            for(int i=head[lc];i!=0&&!tf;i=edge[i].nexty)//遍历可以到达的点
            {
                if(!visit[edge[i].t])//如果没有到达过
                {
                    bfs.push(edge[i].t);
                    visit[edge[i].t]=true;
                    if(h-pos[edge[i].t].z<=r)tf=true;//如果已经到达上面，则跳出
                }
            }
        }
        if(tf)printf("Yes\n");
        else printf("No\n");//判断输出Yes还是No
    }
    return 0;
}
