#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
inline int getn(int n) { return getn(1,n); }
int a[1000010];
int main()
{
	string name="abyss";srand((unsigned int)time(0));
	const int sample=1;string sample_name="sample_"+name;
//	system(("g++ "+name+".cpp -o "+name).c_str());
	rep(id,2,6)
	{
		string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end());
		if(!sample) freopen((name+ids+".in").c_str(),"w",stdout);
		else freopen((sample_name+ids+".in").c_str(),"w",stdout);
		
		int n=2000,d=10,k=30,spec=0;
		
		if(!sample)
		{
			if(id<=2) n=200,d=10,k=20;
			else if(id<=4) n=2000,d=10,k=30;
			else if(id<=6) n=200000,d=n,k=getn(1,n);
			else if(id<=8) n=200000,k=50000,spec=1;
			else n=200000,d=100,k=10000;
		}
		else{
			if(id==2) n=200,d=10,k=20;
			else if(id==3) n=2000,d=10,k=30;
			else if(id==4) n=200000,d=n,k=getn(1,n);
			else if(id==5) n=200000,k=50000,spec=1;
			else n=200000,d=100,k=10000;
		}
		printf("%d %d\n",n,k);
		if(!spec)
		{
			for(int las=n/2,i=1;i<=n;printf("%c"," \n"[i==n]),i++)
			printf("%d",las=getn(max(1,las-d),min(las+d,n)));
		}
		else{
			rep(i,1,n) a[i]=getn(1,n);sort(a+1,a+n+1);
			rep(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
		}
		
		fclose(stdout);
		if(!sample) system((name+" < "+name+ids+".in > "+name+ids+".out").c_str());
		else system((name+" < "+sample_name+ids+".in > "+sample_name+ids+".out").c_str());
		if(!sample) cerr<<name<<ids<<".in and "<<name<<ids<<".out has been made.\n";
		else cerr<<sample_name<<ids<<".in and "<<sample_name<<ids<<".out has been made.\n";
	}
	return 0;
}
