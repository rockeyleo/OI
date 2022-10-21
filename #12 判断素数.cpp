#include <iostream>
#include <cmath>
using namespace std;
int panduan(int a);
int main(){
	int a;
	cin>>a;
	panduan(a);
	
}

int panduan(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
