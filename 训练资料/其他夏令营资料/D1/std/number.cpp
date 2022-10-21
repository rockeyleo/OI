#include<bits/stdc++.h>
using namespace std;
const int N=30;
int nxt[N];char s[N];
int to[N][10];
long long L,R;
int len,k;

long long f[N][N][N][2][2];
int num[N];

inline long long getdp(int now,int spos,int cnt,int upv,int stv) {
	if(cnt<0) return 0;
	if(now<0) return cnt==0;
	if(~f[now][spos][cnt][upv][stv]) return f[now][spos][cnt][upv][stv];
	long long ans=0;
	for(int v=0;v<10;v++) {
		if(upv&&v>num[now]) break;
		int nst=stv|(v!=0);
		int npos=nst?to[spos][v]:0;
		int ncnt=cnt-(npos==len);
		ans+=getdp(now-1,npos,ncnt,upv&&v==num[now],nst);
	}
	return f[now][spos][cnt][upv][stv]=ans;
}

inline void init(long long x) {
	for(int i=0;i<20;i++) {
		num[i]=x%10;x/=10;
	}
	memset(f,-1,sizeof(f));
}

long long ans[N];

int main() {
	freopen("number10.in","r",stdin);
	freopen("number10.ans","w",stdout);
	scanf("%lld%lld%s%d",&L,&R,s+1,&k);len=strlen(s+1);
	for(int i=2,j=0;i<=len;i++) {
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;nxt[i]=j;
	}
	for(int i=0;i<=len;i++) for(int addv=0;addv<10;addv++) {
		int now=i;
		while(now&&(now==len||addv!=s[now+1]-'0')) now=nxt[now];
		if(s[now+1]-'0'==addv) now++;
		to[i][addv]=now;
	}
	init(R);
	for(int i=0;i<=k;i++) ans[i]=getdp(20,0,i,1,0);
	init(L-1);
	for(int i=0;i<=k;i++) ans[i]-=getdp(20,0,i,1,0);
	for(int i=0;i<=k;i++) printf("%lld%c",ans[i],i==k?'\n':' ');
}
/*
1 1000000000000000000 004003 4



1919810 1145141919810 114514 2

*/
