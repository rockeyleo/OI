#include <bits/stdc++.h>
using namespace std;
const int M = 3000000;
int head[M],nxt[M],cnt,to[M];

void add(int f,int t){
	to[++cnt] = t;
	nxt[cnt] = head[f];
	head[f] = cnt;
}

void dfs(){
	
}

int main(){
	
}
