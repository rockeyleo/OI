#include <iostream>
#include <vector>
using namespace std;
int main(){
	int a;
	vector<int> v;
	cin>>a;
	v.push_back(a);
	while(a!=1){
		if(a%2==0){
			a/=2;
			v.push_back(a);
		}else{
			a=a*3+1;
			v.push_back(a);
		}
	}
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i]<<' ';
}
