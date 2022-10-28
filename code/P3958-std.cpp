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
int dy()//�����Ż����ǵ�Ҫ�жϸ���
{
    shu=ch=0,tf=true;
    while(ch<'0'||ch>'9')tf=ch=='-'?false:true,ch=getchar();
    while(ch>='0'&&ch<='9')shu=shu*10+ch-'0',ch=getchar();
    return tf?shu:-shu;
}
struct POS//�洢����ĵ������
{
    int x,y,z;
}pos[2000];
queue<int>bfs;//bfs���õĶ���
int lc;
bool visit[2000];//�Ƿ��е���������
struct Edge//��������ģ����ʽǰ������д��
{
    int t;
    int nexty;
}edge[3000000];
int head[2000];
long long pf(int a)//ƽ����ע��Ҫintתlong long
{
    return ((long long)a)*((long long)a);
}
long long dis(int a,int b)//��������ƽ��
{
    return pf(pos[a].x-pos[b].x)+pf(pos[a].y-pos[b].y)+pf(pos[a].z-pos[b].z);
}
int cnt;
void add(int a,int b)//����ӱ�
{
    cnt++;
    edge[cnt].t=b;
    edge[cnt].nexty=head[a];
    head[a]=cnt;
}
int main()
{
    //freopen("cheese.in","r",stdin);
    //freopen("cheese.out","w",stdout);//ע�͵�
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
        cnt=0;//��ʼ��
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dis(i,j)<=4*pf(r))//�����Բ�ľ���С��2r��������ƽ����ʽ�����Ա��4*r^2���������ǿ��Ի��ൽ��
                {
                    add(i,j);
                    add(j,i);//����ӱ�
                }
            }
        }
        tf=false;//tf���Ƿ���Ե�������
        for(int i=0;i<n&&!tf;i++)
        {
            if(pos[i].z<=r)//������Դӵײ����
            {
                bfs.push(i);
                visit[i]=true;//�ǵô���visit
                if(h-pos[i].z<=r)tf=true;//����Ѿ������ߵ��ϲ㣬��ֱ������
            }
        }
        while(!tf&&!bfs.empty())//bfs��ʼ
        {
            lc=bfs.front();
            bfs.pop();
            for(int i=head[lc];i!=0&&!tf;i=edge[i].nexty)//�������Ե���ĵ�
            {
                if(!visit[edge[i].t])//���û�е����
                {
                    bfs.push(edge[i].t);
                    visit[edge[i].t]=true;
                    if(h-pos[edge[i].t].z<=r)tf=true;//����Ѿ��������棬������
                }
            }
        }
        if(tf)printf("Yes\n");
        else printf("No\n");//�ж����Yes����No
    }
    return 0;
}
