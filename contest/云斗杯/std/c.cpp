#include <iostream>
#include <stack>
using namespace std;
int n;
long long hmin[500010],hmax[500010];
struct node{
	long long s,num;
}a[500010];
stack<node> qmin,qmax;
const long long mod=1000000000;
int main(){
	long long sum;
	long long i,j,x,y,xx,yy;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].num=i;
	}
	for(i=1;i<=n;i++){
//		cout<<"i "<<i<<endl;
//		cout<<qmin.top().s<<" "<<qmax.top().s<<endl;
		while(!qmin.empty()&&qmin.top().s>a[i].s){
			hmin[qmin.top().num]=i-1;
//			cout<<qmin.top().s<<" "<<qmin.top().num<<endl;
			qmin.pop();
//			cout<<"minpop"<<endl;
		}
		while(!qmax.empty()&&qmax.top().s<a[i].s){
			hmax[qmax.top().num]=i-1;
//			cout<<qmax.top().s<<" "<<qmax.top().num<<endl;
			qmax.pop();
//			cout<<"maxpop"<<endl;
		}
		qmin.push(a[i]);
		qmax.push(a[i]);
	}
	while(!qmin.empty()){
		hmin[qmin.top().num]=n;
		qmin.pop();
	}
	while(!qmax.empty()){
		hmax[qmax.top().num]=n;
		qmax.pop();
	}
//	for(i=1;i<=n;i++){
//		cout<<hmax[i]<<" ";
//	}
//	cout<<endl;
//	for(i=1;i<=n;i++){
//		cout<<hmin[i]<<" ";
//	}
//	cout<<endl;
	sum=0;
	for(i=1;i<=n;i++){
		x=hmax[i];
		y=hmin[i];
		xx=a[i].s;
		yy=a[i].s;
		j=i;
//		cout<<i<<endl;
		while(j<=n){
//			cout<<j<<" "<<x<<" "<<y<<endl;
			if(x<y){
				sum+=((((((x-j+1)*((j-i+1)+(x-i+1))/2)%mod)*xx)%mod)*yy)%mod;
//				cout<<"plus "<<(x-j+1)<<" "<<((j-i+1)+(x-i+1))<<" "<<xx<<" "<<yy<<endl;
				sum%=mod;
				j=x;
				j++;
				x=hmax[j];
				xx=a[j].s;
			}
			else{
				sum+=((((((y-j+1)*((j-i+1)+(y-i+1))/2)%mod)*xx)%mod)*yy)%mod;
//				cout<<"plus "<<((y-j+1)*((j-i)+(y-i))/2)<<" "<<xx<<" "<<yy<<endl;
				sum%=mod;
				j=y;
				j++;
				y=hmin[j];
				yy=a[j].s;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}/*
2 4 1 4
1 2 3 4
2 4 4 4
2 2 1 1
  1 2 3
  4 4 4
  4 1 1
    1 2
    1 4
    1 1
      1
      4
      4


8 3 1 9 7 4
i j
1 2 3 4 5 6
8 8 8 9 9 9
8 3 1 1 1 1
  1 2 3 4 5
  3 3 9 9 9
  3 1 1 1 1
    1 2 3 4
    1 9 9 9
    1 1 1 1
      1 2 3
      9 9 9
      9 7 4
        1 2
        7 7
        7 4
          1
          4
          4
*/
