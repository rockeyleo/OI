#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int s[1001][1001];
int main(){
	int a;
	cin>>a;
	memset(s,0,sizeof(s));
	s[1][1]=1;
	int x=1;
	int y=1;
	int o=1;
	while(o<a*a){
		while(x<a and s[y][x+1]==0) s[y][++x]=++o;
		while(y<a and s[y+1][x]==0) s[++y][x]=++o;
		while(x>1 and s[y][x-1]==0) s[y][--x]=++o;
		while(y>1 and s[y-1][x]==0) s[--y][x]=++o;
	}
	
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++)
			printf("%4d ",s[i][j]);
		cout<<"\n"; 
	}
	
	return 0;
}
