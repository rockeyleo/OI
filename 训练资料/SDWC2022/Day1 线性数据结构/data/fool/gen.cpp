#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
inline int getn(int n) { return getn(1,n); }
int p[1000010];
int main()
{
	string name="fool";srand((unsigned int)time(0));
	const int sample=1;string sample_name="sample_"+name;
//	system(("g++ "+name+".cpp -o "+name).c_str());
	rep(id,1,6)
	{
		string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end());
		if(!sample) freopen((name+ids+".in").c_str(),"w",stdout);
		else freopen((sample_name+ids+".in").c_str(),"w",stdout);
		
		int n,len,m;
		if(!sample)
		{
			if(id<=2) n=200,len=10000000,m=1000000000;
			else if(id<=4) n=2000,len=1000000,m=1000000000;
			else if(id<=6) n=200000,len=20,m=1000000;
			else if(id<=8) n=200000,len=1000,m=200000;
			else n=200000,len=100000,m=1000000000;
			int k=n/2;assert(m>=n);printf("%d\n",n);
			rep(i,1,n) p[i]=int((long long)m*i/n);
			random_shuffle(p+1,p+n+1);
			rep(i,1,k) printf("%d %d\n",p[i],p[i]);
			rep(i,k+1,n)
			{
				int L=getn(len/2,len),l=getn(1,m-L+1),r=l+L-1;
				printf("%d %d\n",l,r);
			}
		}
		else{
			if(id==1) n=10,len=5,m=30;
			else if(id==2) n=200,len=100,m=3000;
			else if(id==3) n=2000,len=1000,m=30000;
			else if(id==4) n=200000,len=20,m=1000000;
			else if(id==5) n=200000,len=10000,m=200000;
			else n=200000,len=100000,m=1000000000;
			printf("%d\n",n);
			rep(i,1,n)
			{
				int L=getn(len/2,len),l=getn(1,m-L+1),r=l+L-1;
				printf("%d %d\n",l,r);
			}
		}
		
		fclose(stdout);
		if(!sample) system((name+" < "+name+ids+".in > "+name+ids+".out").c_str());
		else system((name+" < "+sample_name+ids+".in > "+sample_name+ids+".out").c_str());
		if(!sample) cerr<<name<<ids<<".in and "<<name<<ids<<".out has been made.\n";
		else cerr<<sample_name<<ids<<".in and "<<sample_name<<ids<<".out has been made.\n";
	}
	return 0;
}
