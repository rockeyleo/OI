#include <iostream>
#include <cstring>
using namespace std;


int main(){
	bool a[101]={0};
	
	memset(a,0,sizeof(a));
	
	for(int x=1;x<=100;x++){
		for(int y=x;y<=100;y+=x){
			a[y]=!a[y];
		}
	}
	
	for(int x=0;x<=100;x++)
		if(a[x])
			cout<<x<<ends;
}
