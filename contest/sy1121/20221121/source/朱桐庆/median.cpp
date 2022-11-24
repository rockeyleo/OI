#include<bits/stdc++.h>
using namespace std;
#define maxn 500000
int n,a[maxn],tot,flag,dis,b[maxn]; 
void bian(){
	if(tot>n)
	{	dis=1;
		return ;
	}
	int k;
	if(flag==0)
		for(int i=2;i<=n-1;i++)
		{	k=a[i]+a[i-1]+a[i+1];
			if(k<2)b[i]=0;
			else b[i]=1;
		}
	if(flag)
		for(int i=2;i<=n-1;i++)
		{	k=b[i]+b[i-1]+b[i+1];
			if(k<2)a[i]=0;
			else a[i]=1;
		}
	if(flag==0)flag=1;
	else flag=0;
	tot++;
	for(int i=2;i<n;i++)
		if(a[i]!=b[i])
		{
			bian();
			break;
		}
	return ;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>n;
	if(n>=15000)cout<<"-1"<<endl;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[1]=a[1],b[n]=a[n];
	bian();
	if(!dis)cout<<tot-1<<endl;
	else cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*


*/
