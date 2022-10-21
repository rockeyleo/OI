#include<bits/stdc++.h>
#define lint long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1000010,M=N<<1,SIG=26;
struct SAM{
	int fa,ch[SIG],v;
}t[M];int cnt,rt,last;lint ans;
struct edges{
	int to,pre;
}e[M];int etop,h[M],sz[M];char s[N];
inline int add_edge(int u,int v) { return e[++etop].to=v,e[etop].pre=h[u],h[u]=etop; }
inline int new_node(int v) { return t[++cnt].v=v,cnt; }
inline int extend(int w)
{
	int p=last,np=new_node(t[p].v+1);
	while(p&&!t[p].ch[w]) t[p].ch[w]=np,p=t[p].fa;
	if(!p) t[np].fa=rt;
	else{
		int q=t[p].ch[w];
		if(t[p].v+1==t[q].v) t[np].fa=q;
		else{
			int nq=new_node(t[p].v+1);
			memcpy(t[nq].ch,t[q].ch,sizeof(int)*SIG);
			t[nq].fa=t[q].fa,t[q].fa=t[np].fa=nq;
			while(p&&t[p].ch[w]==q) t[p].ch[w]=nq,p=t[p].fa;
		}
	}
	return sz[last=np]=1;
}
int dfs(int x)
{
	for(int i=h[x];i;i=e[i].pre) sz[x]+=dfs(e[i].to);
	if(sz[x]>1) ans=max(ans,(lint)sz[x]*t[x].v);return sz[x];
}
int main()
{
	rt=last=new_node(0);
	scanf("%s",s+1);int n=(int)strlen(s+1);
	rep(i,1,n) extend(s[i]-'a');
	rep(i,1,cnt) add_edge(t[i].fa,i);
	dfs(rt);printf("%lld\n",ans);return 0;
}
