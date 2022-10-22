#include<bits/stdc++.h>
using namespace std;
int n;
int a[101],w[101];
int Max[101][101],Min[101][101];
int main()
{
	cin>>n;
	memset(Min,0x7f7f7f7f,sizeof(Min)); 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)
	{
		Max[i][i]=Min[i][i]=0;
	}
	for(int i=1;i<=2*n;i++)
	    w[i]=w[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l+i<=2*n;l++)
		{
			int r=l+i-1;
			for(int mid=l;mid<r;mid++)
			{
    			Max[l][r]=max(Max[l][mid]+Max[mid+1][r]+w[r]-w[l-1],Max[l][r]);
    			Min[l][r]=min(Min[l][mid]+Min[mid+1][r]+w[r]-w[l-1],Min[l][r]);
    
            }
        } 
	}
	int ans=0,ans1=0x7f7f7f7f;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,Max[i][i+n-1]);
		ans1=min(ans1,Min[i][i+n-1]);
	}
	cout<<ans1<<endl<<ans;

	return 0;
  }
