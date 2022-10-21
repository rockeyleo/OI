#include <iostream>

using namespace std;
int main(){
	string a;
	getline(cin,a);
	int l = a.size();
	for(auto x:a){
		if(x==' ' or x=='\n'){
			l--;
		}
	}
	cout<<l<<endl;
}
