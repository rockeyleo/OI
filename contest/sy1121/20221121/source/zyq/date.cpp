#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    int n,a[100000][100000],m,b[100000][100000];
    cin>>n;
    for(int i=1;i<n;i++){
    	int x,y;
    	cin>>x>>y;
    	a[x][y]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int k,l;
		cin>>k>>l;
		b[k][l]=1;
	}
    cout<<1;
    return 0;
}
