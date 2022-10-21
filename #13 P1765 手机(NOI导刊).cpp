#include <iostream>

using namespace std;
int main(){
	string in;
	getline(cin,in);
	int step =0;
	char yi[8]={'a','d','g','j','m','p','t','w'};
	char er[8]={'b','e','h','k','n','q','u','x'};
	char san[8]={'c','f','i','l','o','r','v','y'};
	char si[2]={'s','z'};
	
	for(auto x:in){
		if(x=='s' or x=='z')
			step+=4;
		if(x==' ')
			step+=1;
		for(int j=0;j<=7;j++){
			if(x==yi[j]){
				step+=1;
			}
			if(x==er[j]){
				step+=2;
			}
			if(x==san[j]){
				step+=3;
			}
		}
	}
	
	cout<<step;
	
}
