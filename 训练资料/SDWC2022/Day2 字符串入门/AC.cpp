#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=160,S=1000010,T=500010,L=80,SIG=26;
struct ac_node{
	int ch[SIG],fail,val;bool vis;
}t[T];int top=0,cnt[N];char ss[S];queue<int> q;
inline int new_node()
{
	return top++,t[top].fail=t[top].val=0,t[top].vis=false,
		memset(t[top].ch,0,sizeof(t[top].ch)),top;
}
inline int insert_ac(int rt,char *s)
{
	int n=(int)strlen(s+1),now=rt;
	rep(i,1,n) { int c=s[i]-'a';if(!t[now].ch[c]) t[now].ch[c]=new_node();now=t[now].ch[c]; }
	return t[now].val++,rt;
}
inline int get_fail(int rt)
{
	while(!q.empty()) q.pop();
	rep(i,0,SIG-1) { int &c=t[rt].ch[i];(c?t[c].fail=rt,q.push(c),0:c=rt); }
	while(!q.empty())
	{
		int x=q.front(),f=t[x].fail;q.pop();
		for(int i=0;i<SIG;i++)
		{
			int &y=t[x].ch[i];
			if(y) t[y].fail=t[f].ch[i],q.push(y);
			else y=t[f].ch[i];
		}
	}
	return 0;
}
inline int find_ac(int rt,char *s)
{
	int n=(int)strlen(s+1),now=rt,ans=0;
	while(!q.empty()) q.pop();
	rep(i,1,n)
	{
		int c=s[i]-'a';now=t[now].ch[c];
		for(int p=now;p&&(p^rt)&&!t[p].vis;p=t[p].fail)
			ans+=t[p].val,t[p].val++,t[p].vis=true;
	}
	return ans;
}
int main()
{
	int n,rt;scanf("%d",&n),top=0,rt=new_node();
	rep(i,1,n) scanf("%s",ss+1),insert_ac(rt,ss);
	memset(cnt,0,sizeof(cnt)),get_fail(rt),scanf("%s",ss+1);
	return !printf("%d\n",find_ac(rt,ss));
}
