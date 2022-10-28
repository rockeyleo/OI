#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
int val[M];
int fa[M],vis[M];
queue<int> q;
void bfs(){
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int now = q.front(); q.pop();

	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='('){
			val[i]=1;
		}else{
			val[i]=2;
		}
	}
	for(int i=2;i<=n-1;i++){
		cin>>fa[i];
	}
	bfs();
}
