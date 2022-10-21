#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
inline int getn(int n) { return getn(1,n); }
int a[1000010];
int main()
{
	string name="moon";srand((unsigned int)time(0));
	const int sample=1;string sample_name="sample_"+name;
//	system(("g++ "+name+".cpp -o "+name).c_str());
	rep(id,4,4)
	{
		string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end());
		if(!sample) freopen((name+ids+".in").c_str(),"w",stdout);
		else freopen((sample_name+ids+".in").c_str(),"w",stdout);
		
		int T=5,n=id+1;printf("%d\n",T);
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",getn(0,n)," \n"[i==n]);
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",getn(0,100000000)," \n"[i==n]);
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",i*10000000," \n"[i==n]);
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",0+(getn(1,n)<=2)," \n"[i==n]);
		printf("%d\n",n);
		rep(i,1,n) printf("%d%c",1+(getn(1,n)<=n/2)," \n"[i==n]);
		
		fclose(stdout);
		if(!sample) system((name+" < "+name+ids+".in > "+name+ids+".out").c_str());
		else system((name+" < "+sample_name+ids+".in > "+sample_name+ids+".out").c_str());
		if(!sample) cerr<<name<<ids<<".in and "<<name<<ids<<".out has been made.\n";
		else cerr<<sample_name<<ids<<".in and "<<sample_name<<ids<<".out has been made.\n";
	}
	return 0;
}
