#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int a[4] = {0,0,0,0};
	string order = " ";
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	cin>>order;
	for(int i=3;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(a[i]>a[i+1])
				swap(a[i],a[i+1]); 
		}
	}
	
	for(int i=1;i<=3;i++){
		switch(order[i-1]){
			case 'A':
				 cout<<a[1]<<" ";
				 break;
			case 'B':
				 cout<<a[2]<<" ";
				 break;
			case 'C':
				 cout<<a[3]<<" ";
				 break;
		}
	}
}
