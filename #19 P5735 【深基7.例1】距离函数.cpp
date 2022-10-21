#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

double dis(double x1,double y1,double x2,double y2){
	double a= (x1-x2)*(x1-x2);
	double b= (y1-y2)*(y1-y2);
	return(sqrt(a+b));
}

int main(){
	double x[4],y[4];
	
	for(int i=1;i<=3;i++){
		cin>>x[i]>>y[i];
	}
	double out=dis(x[1],y[1],x[2],y[2])+dis(x[1],y[1],x[3],y[3])+dis(x[3],y[3],x[2],y[2]);
	printf("%.2f",out);
}

