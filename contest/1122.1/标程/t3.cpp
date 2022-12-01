#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,L=1025;
int Q,m,x,y,opt;
struct Stack{
	int dp[N][L],val1[N],val2[N],tot;
	void add(int x,int y){
		tot++;
		val1[tot]=x;val2[tot]=y;
		for (int i=0;i<m;i++)dp[tot][i]=max(dp[tot-1][i],dp[tot-1][i^x]+y);
	}
}A,B;
int main(){
	scanf("%d",&Q);m=1024;
	memset(A.dp,192,sizeof A.dp);
	memset(B.dp,192,sizeof B.dp);
	A.dp[0][0]=B.dp[0][0]=0;
	while (Q--){
		scanf("%d",&opt);
		if (opt==1){
			scanf("%d%d",&x,&y);
			A.add(x,y);
		}
		if (opt==2){
			scanf("%d%d",&x,&y);
			B.add(x,y);
		}
		if (opt==3){
			if (A.tot==0){
				int len=(B.tot+1)/2,t=B.tot;B.tot=0;
				for (int i=len;i;i--)A.add(B.val1[i],B.val2[i]);
				for (int i=len+1;i<=t;i++)B.add(B.val1[i],B.val2[i]);
			}
			A.tot--;
		}
		if (opt==4){
			if (B.tot==0){
				int len=(A.tot+1)/2,t=A.tot;A.tot=0;
				for (int i=len;i;i--)B.add(A.val1[i],A.val2[i]);
				for (int i=len+1;i<=t;i++)A.add(A.val1[i],A.val2[i]);
			}
			B.tot--;
		}
		int ans=-1;
		for (int i=0;i<m;i++)
			if (A.dp[A.tot][i]>=0&&B.dp[B.tot][i]>=0)ans=max(ans,A.dp[A.tot][i]+B.dp[B.tot][i]);
		printf("%d\n",ans);
	}
	return 0;
}



