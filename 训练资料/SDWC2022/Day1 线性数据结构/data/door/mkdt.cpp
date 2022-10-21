#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
inline int getn(int n) { return getn(1,n); }
int a[1000010];
int main()
{
	string name="door";srand((unsigned int)time(0));
	const int sample=1;string sample_name="sample_"+name;
//	system(("g++ "+name+".cpp -o "+name).c_str());
	rep(id,1,5)
	{
		string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end());
		if(!sample) freopen((name+ids+".in").c_str(),"w",stdout);
		else freopen((sample_name+ids+".in").c_str(),"w",stdout);
		
		int n=getn(290000,300000);
		if(!sample)
		{
			if(id==1) n=4;
			else if(id==2) n=getn(7,8);
			else if(id<=4) n=getn(15,16);
			else if(id<=7) n=getn(1900,2000);
		}
		else{
			if(id==1) n=4;
			else if(id==2) n=getn(7,8);
			else if(id==3) n=getn(15,16);
			else if(id==4) n=getn(1900,2000);
		}
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",getn(0,1)," \n"[i==n]);
		
		fclose(stdout);
		if(!sample) system((name+" < "+name+ids+".in > "+name+ids+".out").c_str());
		else system((name+" < "+sample_name+ids+".in > "+sample_name+ids+".out").c_str());
		if(!sample) cerr<<name<<ids<<".in and "<<name<<ids<<".out has been made.\n";
		else cerr<<sample_name<<ids<<".in and "<<sample_name<<ids<<".out has been made.\n";
	}
	return 0;
}
