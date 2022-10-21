#include <bits/stdc++.h>
using namespace std;
const int M = 2000000;
int lg[M];
int l2g(int a){
    if(a==1)return 0;
    if(lg[a]!=0)return lg[a];
    return(lg[a]=(l2g(a/2)+1));
}

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

// int num[M];

int f[M][25];
int main(){
    int n,m,l,r;
    cin>>n>>m;
    // for(int i=1;i<=n;i++){
    //     cin>>num[i];
    // }
    for(int i=1;i<=n;i++){
        f[i][0]=read();
    }
    lg[1]=0;
    for(int j=1;j<=24;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    // cin>>l>>r;
    for(int i=1;i<=m;i++){
        // cin>>l>>r;
        l=read();
        r=read();
        int len=l2g(r-l+1);
        cout<<max(f[l][len],f[r-(1<<len)+1][len])<<"\n";   //注意不要用endl
    }
}