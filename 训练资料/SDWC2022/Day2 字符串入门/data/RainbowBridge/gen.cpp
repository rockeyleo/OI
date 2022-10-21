#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
inline int getn(int n) { return getn(1,n); }
int a[1000010];
int main()
{
	string name="RainbowBridge";srand((unsigned int)time(0));
	const int sample=0;string sample_name="sample_"+name;
//	system(("g++ "+name+".cpp -o "+name).c_str());
	rep(id,1,10)
	{
		string ids;for(int x=id;x;x/=10) ids+=char('0'+x%10);
		reverse(ids.begin(),ids.end());
		if(!sample) freopen((name+ids+".in").c_str(),"w",stdout);
		else freopen((sample_name+ids+".in").c_str(),"w",stdout);
		
		int n=500000,t=(id>5),spec=0;
		if(id%5==1) n=200;
		else if(id%5==2) n=2000;
		else if(id%5==3) spec=1;
		
		if(spec) rep(i,1,n) printf("%c",char(getn('a','z')));
		else{
			rep(i,1,n/4) printf("%c",getn(0,n/100)==0?'b':'a');
			rep(i,1,n/2) printf("a");
			rep(i,1,n/4) printf("%c",getn(0,n/100)==0?'b':'a');
		}
		
		printf("\n%d\n",t);
		
		fclose(stdout);
		if(!sample) system((name+" < "+name+ids+".in > "+name+ids+".out").c_str());
		else system((name+" < "+sample_name+ids+".in > "+sample_name+ids+".out").c_str());
		if(!sample) cerr<<name<<ids<<".in and "<<name<<ids<<".out has been made.\n";
		else cerr<<sample_name<<ids<<".in and "<<sample_name<<ids<<".out has been made.\n";
	}
	return 0;
}
