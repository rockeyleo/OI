#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int out[1001];
int main(){
	string i;
	int zl=0;
	int xb;
	memset(out,0,sizeof(out));
	getline(cin,i);
	
	for(int j=0;j<=i.length()-1;j++){
		if(!(i[j]>='a' and i[j]<='z')){
			if(!(i[j+1]>='a' and i[j+1]<='z') and j+1<=i.length()-1){
				if(!(i[j+2]>='a' and i[j+2]<='z')and j+1<=i.length()-1 and j+2<=i.length()-1){
					xb = (i[j]-'0')*100+(i[j+1]-'0')*10+(i[j+2]-'0');
					out[xb]++;
					j+=3;
				}else{
					xb =((i[j]-'0')*10)+(i[j+1]-'0');
					j+=2;
					out[xb]++;
				}
			}else{
				xb =i[j]-'0';
				out[xb]++;
				j++;
			}
		}
	}
	for(auto x:out){
		//cout<<x;
		if(x)
			zl++;
	}
	
	cout<<zl;
}

