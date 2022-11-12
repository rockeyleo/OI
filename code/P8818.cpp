#include <bits/stdc++.h>
using namespace std;
const int M = 100009;
int a[M][25],b[M][25];

int l2g(int x){
	if(x==1)return 0;
	return (l2g(x/2)+1);
}

template<class T>T read(){
    char ch = getchar();
    T ret = 0, f = -1;
    while(ch<'0' or ch>'9'){if(ch=='-'){f = -f;}ch = getchar();}
    while(ch>='0' and ch<='9'){ret = ret*10+ch-'0'; ch = getchar();}
    return ch*f;
}

void init(int &f[][],int n,int opt){
	if(opt){
		for(int i=1;i<=n;i++){
			for(int j=1;i+(1<<j)-1<=n;j++){
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}	
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;i+(1<<j)-1<=n;j++){
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
	return;
}

void query(int x,int y){
	
}

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		a[i][0] = read<int>();
	}
	for(int i=1;i<=m;i++){
		b[i][0] = read<int>();
	}
	init(a,n,1);init(b,m,0);
	for(int i=1;i<=q;i++){
		
	}
	return 0;
}
