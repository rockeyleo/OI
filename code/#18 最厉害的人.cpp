#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string name[101];
int E[101],C[101],M[101];
int sum[101];
map<int,string> m; 

int main(){
	int n;
	cin>>n;
	memset(E,0,sizeof(E));
	memset(C,0,sizeof(C));
	memset(M,0,sizeof(M));
	for(int x=1;x<=n;x++){
		cin>>name[x]>>C[x]>>M[x]>>E[x];
		sum[x]=C[x]+M[x]+E[x];
		m.insert(pair<int,string>(sum[x],name[x]));
	}
	sort(sum[1],sum[n]);
	for(auto iter=m.find(101);iter!=m.end();iter++){
		cout<<iter->first;
	}
}

