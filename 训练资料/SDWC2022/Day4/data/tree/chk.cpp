#include <bits/stdc++.h>
#include "lemon_testlib.h"
using namespace std;
int n,maxx[1005],minn[1005],pa[1005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main(int argc,char *argv[])
{
	registerLemonChecker(argc, argv);
	n=inf.readInt();
	int x=ans.readInt();
	if(x==-1)
	{
		int y=ouf.readInt();
		if(y!=-1)
		{
			quitf(_wa,"Wrong Ans");
			return 0;
		}
		quitf(_ok,"ok");
		return 0;
	}
	for(int i=1;i<=n;i++)pa[i]=i,minn[i]=n+1,maxx[i]=0;
	for(int i=1;i<n;i++)
	{
		int x=ouf.readInt(1,n);
		int y=ouf.readInt(1,n);
		if(find(x)==find(y))
		{
			quitf(_wa,"the output is not a tree");
			return 0;
		}
		pa[find(x)]=find(y);
		minn[x]=min(minn[x],y);
		maxx[x]=max(maxx[x],y);
		minn[y]=min(minn[y],x);
		maxx[y]=max(maxx[y],x);
	}
	for(int i=1;i<=n;i++)
	{
		int v1=inf.readInt();
		int v2=inf.readInt();
		if(v1!=minn[i])
		{
			quitf(_wa,"the output is not correct");
			return 0;
		}
		if(v2!=maxx[i])
		{
			quitf(_wa,"the output is not correct");
			return 0;
		}
	}
	quitf(_ok,"ok");
	return 0;
}
